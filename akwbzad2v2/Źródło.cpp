// ConsoleApplication1.cpp: 
//

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


#define vertices 20

int matrix[vertices][vertices];
int tableArcs[80][2];
int originalGraph[80][2];
int sizeB = 20;
int maxVertex;
vector<int> arrayVertices;

//function to check
bool conjugate(int matrix[][20]);
void display(); //matrix
void matrixReset();
bool structureA(int matrix[][20]);
void start();
void transformation();
bool isVertex(int x);  
//transformation 


bool conjugate(int matrix[][20])
{

	int a = 0;
	int tab[100];
	for (int w = 0; w < sizeB; w++) {
		for (int ww = 1; ww < sizeB; ww++) {
			for (int k = 0; k < sizeB; k++) {
				if ((matrix[w][k] == matrix[ww][k]) && (matrix[w][k] == 1)) { // writes lines that need to be checked because they have the same columns 1, so you have to check the whole row 
					tab[a] = w;		// tab stores line 1 in the even index and line 2 in the odd index, which will be compared 
					tab[a + 1] = ww;
					a = a + 2;
					break;
				}
			}
		}
	}
	for (int a = 0; a < 50; a += 2) {
		for (int kk = 0; kk < sizeB; kk++) {
			if (matrix[tab[a]][kk] != matrix[tab[a + 1]][kk]) { //here I check if these lines are the same, if not, it means that the graph is not concatenated 
				return false;
			}
		}
	}
	return true;

}

bool oneGraf(int matrix[][20]) {
	for (int i = 0; i < sizeB; i++) {
		for (int j = 0; j < sizeB; j++) {
			if (matrix[i][j] > 1) {
				return false; // if false, the given graph is not a 1-graph and this completes further checking 
			}
		}
	}
	return true;
}

void display() {
	cout << endl;
	cout << "X" << "  ";
	for (int i = 0; i < arrayVertices.size(); i++) {
		cout << i + 1 << "  ";
	}
	for (int i = 0; i < arrayVertices.size(); i++) {
		cout << endl;
		cout << i + 1 << "  ";
		for (int j = 0; j < arrayVertices.size(); j++) {
			cout << matrix[i][j] << "  ";
		}
	}
	cout << endl;
}

void matrixReset() {
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			matrix[i][j] = 0;
		}
	}
}


bool structureA(int matrix[][20]) {
	for (int w = 0; w < sizeB; w++) {
		int tabb[50];
		int aj = 0;
		for (int k = 0; k < sizeB; k++) {
			if (matrix[w][k] == 1 && w != k) {  //tab stores the number of the columns where it appeared in the given line 1, i.e. all the successors of the given line so that it would not add a loop to be checked 
				tabb[aj] = k;
				aj++;
			}
		}
		if (aj >= 1) { //if it found more than 1 successor on a given line it must check 

			for (int kk = 0; kk < sizeB; kk++) {
				for (int i = 0; i < aj; i++) {  //these two loops are there to check all the follower combinations 
					for (int ii = 0; ii < aj; ii++) {
						if (i != ii) { // this condition in order to eliminate the comparison of the same rows 
							if ((((matrix[tabb[i]][kk] == matrix[tabb[ii]][kk]) && matrix[tabb[ii]][kk] != 0))) { // here checks if the successors of this line have the same successor 
								return false;
							}
						}

					}
				}
			}
			if ((matrix[w][w] == 1)) {  // if the vertex has a loop of its own and found another connection on this row 
				for (int a = 0; a < aj; a++) {
					if ((matrix[tabb[a]][w] == 1) && (matrix[tabb[a]][tabb[a]] == 1)) { // checks for this structureA 
						return false;
					}
				}
			}
		}
	}
	return true;
}

void start() {
	int a = 1;
	for (int i = 0; i < arrayVertices.size(); i++) {
		originalGraph[i][0] = a;
		a++;
		originalGraph[i][1] = a++;
	}
}

void transformation() {
	for (int i = 0; i < arrayVertices.size(); i++) {
		for (int j = 0; j < arrayVertices.size(); j++) {
			if (matrix[i][j] == 1) {
				if (originalGraph[i][1] < originalGraph[j][0]) {
					originalGraph[j][0] = originalGraph[i][1];
				}
				else originalGraph[i][1] = originalGraph[j][0];

			}
		}
	}
}
bool isVertex(int x) {
	for (int i = 0; i < arrayVertices.size(); i++) {
		if (arrayVertices[i] == x) return true; //
	}
	return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SERCE PROGRAMU

int main()
{


	fstream plik;
	int licznik = 0;
	int ilosc_wierzcholkow = 0;
	//first open the file to set the number of vertices and maximum vertex 
	plik.open("s7graf.txt", ios::in);
	while (!plik.eof()) {
		int y;
		plik >> y;
		licznik++;
		if (!isVertex(y)) arrayVertices.push_back(y); // this is so that the vertices do not repeat themselves 
		if (maxVertex < y) maxVertex = y;
	}
	plik.close();


	//the second reading of the file to write the graph to the successor list and arcs table 
	plik.open("s7graf.txt", ios::in);
	int i = 0;
	while (!plik.eof()) {
		int x, y;
		plik >> x;
		plik >> y;
		tableArcs[i][0] = x;
		tableArcs[i][1] = y;
		i++;
	}
	plik.close();

	//displaying an array of arcs 
	//for (int i = 0; i < licznik/2; i++) {
	//	cout << tableArcs[i][0] << " " << tableArcs[i][1] << endl;
	//}
		


	//matrix reset 
	matrixReset();

	//complement of the matrix 
	for (int i = 0; i < licznik / 2; i++) {
		if (matrix[tableArcs[i][0] - 1][tableArcs[i][1] - 1] == 0) {
			matrix[tableArcs[i][0] - 1][tableArcs[i][1] - 1] = 1;

		}
		else {
			matrix[tableArcs[i][0] - 1][tableArcs[i][1] - 1] = matrix[tableArcs[i][0] - 1][tableArcs[i][1] - 1]++;
		}
	}


	/*display();*/


	//coupling check and 3 structureAs 
	if (conjugate(matrix) && oneGraf(matrix)) {
		cout << endl << " The graph is a conjugated graph (it is a 1-graph) " << endl;
		if (structureA(matrix)) {
			cout << "The graph is a line graph (it does not contain any of the 3 structures) " << endl;
		}
		else
			cout << " The graph is not a line graph (it contains 1 of 3 structures) " << endl;
		cout << endl;
	}
	else
		cout << "Graph is not a conjugate graph " << endl;

	//transformation

		//displaying an array of vertices 

	//for (int i = 0; i < arrayVertices.sizeB(); i++) {
	//	cout << arrayVertices[i] << ", ";
	//}

	cout << endl << endl;

	if (conjugate(matrix) && oneGraf(matrix)) {
		//make it original 
		
		start();

		transformation();

		string fileName = "s7grafwynik.txt";
		fstream file;
		int j = 0;
		file.open(fileName.c_str(), ios::out);
		for (int i = 0; i < arrayVertices.size(); i++) {
			file << originalGraph[i][0] << " ";
			file << originalGraph[i][1] << "\n";
		}
		file.close();

	}

	//////display original graph 
	//for (int i = 0; i < arrayVertices.sizeB(); i++) {
	//	cout << originalGraph[i][0] << " " << originalGraph[i][1] << endl;
	//}
	//cout << endl;



	system("PAUSE");


	return 0;
}