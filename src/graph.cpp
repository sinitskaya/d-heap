#include "graph.h"
#include <vector>
#include <ctime>
Graph:: Graph(int s)
{
	gsize = s;
	/*
	*edge = new int[gsize];
	
		}*/
	edge = new int*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new int[gsize];
	
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(i==j)
				edge[i][j] = 0;
			else
				edge[i][j] = INT_MAX;
		}
}

Graph:: Graph(int s, int k)
{
	gsize = s;
	//srand (time(0));
	edge = new int*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new int[gsize];
	
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(i==j)
				edge[i][j] = 0;
			else
				edge[i][j] = ( rand() % k );
		}

		for(int i=0; i<gsize; i++)
			for(int j=0; j<gsize; j++)
			{
				if(edge[i][j]=edge[j][i])
					edge[i][j] = edge[j][i];
			}
		
}

void Graph:: Print()
{
	for(int i=0; i<gsize; i++)
	{
		for(int j=0; j<gsize; j++)
		{
			if (edge[i][j]==INT_MAX)
				cout << "  " << "M";
			else
				cout << "  " << edge[i][j];
		}
		cout << endl;
	}
}
Graph:: ~Graph()
{
	for(int i=0; i<gsize; i++)
		delete [] edge[i];
}