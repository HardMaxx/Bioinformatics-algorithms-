
# Linear graph algorithm, transformation 
> 
> 

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
<!--* [Screenshots](#screenshots)-->
* [Setup](#setup)
* [Project Status](#project-status)
<!--* [Room for Improvement](#room-for-improvement)-->
* [Acknowledgements](#acknowledgements)
<!--* [Contact](#contact)
* [License](#license) -->
<!--* [Usage](#usage)-->


## General Information
It is a console application that checking if the loaded graph is a graph adjoint and if the graph is a adjointe, transforming it into its original graph.


## Technologies Used
- The tool is written in C++


## Features
- loading any graph directed from a text file,
- checking if the loaded graph is a graph adjoint,
- if the graph is a adjoint, check if it is a line graph,
- printing a message about the result of the above check,
- if the graph is a adjoint, transforming it into its original graph (H),
- saving the result graph H to a text file other than the input file, but in the same format. 
<!--
## Screenshots
![Main window](./images/main_window.png)
![add job window](./images/add_job.png)
![history rerun window](./images/history_window_rerun.png)
![info error window](./images/info_error.png)
![info no data window](./images/info_nodata.png)
![info window](./images/info_window.png)
<!-- If you have screenshots you'd like to share, include them here. -->

<!--
## Setup
### Linux
` sudo apt update `

` sudo apt install dirmngr gnupg apt-transport-https ca-certificates `

` sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF `

` sudo sh -c 'echo "deb https://download.mono-project.com/repo/ubuntu stable-bionic main" > /etc/apt/sources.list.d/mono-official-stable.list' `

` sudo apt update `

` sudo apt install mono-complete `

` sudo apt install libcanberra-gtk-module libcanberra-gtk3-module `

` sudo apt install xcb `

-->
## Usage

Position the file in the program that contains the graph you want to examine and run the program.

Graph example 
`1 2
1 7
2 3
3 4
4 5
5 6
6 7
7 8
6 2
3 1`


## Project Status
Project is: _no longer being worked on_. 

<!--
## Room for Improvement

Room for improvement:
- Code improvement
- GC improvement
- Problem with memory after long run

To do:
- Add more bioinformatic tools
- Add tools non-bioinformatics

-->
## Acknowledgements

This project was inspired by:
- C. Berge, Graphs and Hypergraphs, North-Holland Publishing Company, London, 1973.
- J. Błażewicz, A. Hertz, D. Kobler, D. de Werra, On some properties of DNA graphs, Discrete Applied Mathematics 98, 1-19, 1999.


<!--

<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
