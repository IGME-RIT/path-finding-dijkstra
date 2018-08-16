/*
File Name : graph.cpp
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
#include "graph.h"


#pragma region Graph Generation



void graph::genGraph()
{

	//Initializing units
	srand(time(NULL)); //seeds our random number generation
	int randCost;
	for (int i = 0; i < S; i++)
	{
		Vertex temp;
		temp.index = i;

		
		for (int j = 0; j < S; j++)
		{
			if (i == j)
				temp.costs.push_back(0);
			else if(j<i)
			{
				temp.costs.push_back(Graph[j].costs[i]);
			
			}
			else
			{
				randCost = rand() % (10);
				temp.costs.push_back(randCost);
			}
				
		}
		
		Graph.push_back(temp);
	}

}


#pragma endregion

//Print graph out
void graph::printGraph()
{
	int start;

	
	for (int i = 0; i < S; i++)
	{
		std::cout << "Vertex " << i << ": ";
		for (int j = 0; j < S; j++)
		{
			std::cout << Graph[i].costs[j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "Enter start vertex:";
	std::cin >> start;
	Dijsktra(start);
	std::cout << "Minimum distances from vertex "<<start<<"\n";
	for (int i = 0; i < S; i++)
	{
		std::cout << "To Vertex "<<i<<": "<<dist[i] << " \n";
	}
	
	
}

//Constructor
graph::graph()
{
	genGraph();
}

//Actual algorithm
void graph::Dijsktra(int start)
{
	
	
	//Initalizing distances to max values
	for (int i = 0; i < S; i++)
	{
		dist.push_back(INT_MAX);
	}


	dist[start] = 0;
	int minIndex=-1;
	int minCost;
	
	//Loop until our path vector has all the vertices from the graph
	while (path.size()<S)
	{
		minCost = INT_MAX;
		for (int i = 0; i < S; i++)
		{
			if (Graph[i].included == false && dist[i] < minCost)
			{
				minCost = dist[i];
				minIndex = i;
			}
		}
		Graph[minIndex].included = true;
		path.push_back(Graph[minIndex]);

		//Updating  distances of vertices adjacent to the one we picked above
		for (int i = 0; i < S; i++)
		{
			if (!Graph[i].included &&			//Not already in our path vector
				Graph[minIndex].costs[i]>0 &&	//Connected to our selected vertex
				dist[minIndex] + Graph[minIndex].costs[i] < dist[i]) //distance from start to current vertex is lesser than stored current vertex distance
			{
				dist[i] = dist[minIndex] + Graph[minIndex].costs[i];
			}
		}
		
	}

	
}
