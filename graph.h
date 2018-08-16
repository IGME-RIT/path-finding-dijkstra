/*
File Name : graph.h
Copyright � 2018
Original authors : Srinivasan Thiagarajan
Refactored by Sanketh Bhat
Written under the supervision of David I.Schwartz, Ph.D., and
supported by a professional development seed grant from the B.Thomas
Golisano College of Computing & Information Sciences
(https ://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.

Description:
Demonstration of the Dijkstra path finding algorithm in c++ 
*/

#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include <vector>
#include <string>
#include <time.h>

const int S = 8;	//Number of vertices

//Veryex struct to hold basic data
struct Vertex{

	int index;	//Index of this vertex stored in the graph
	std::vector<int> costs;	//Stores cost of the edge from this vertex to it's adjacent ones.
	bool included = false;	//Shows if this vertex has been processed yet by the algorithm
};


class graph {
	

	std::vector<Vertex> Graph; //Created graph of vertices
	std::vector<Vertex> path;  //stores the path the algorithm uses
	std::vector<int> dist;		//Stores the minimum distance peratining to each vertex


	void genGraph();
	void Dijsktra(int start);
	
public:
	
	void printGraph();
	graph();
	
};


#endif GRAPH_H
