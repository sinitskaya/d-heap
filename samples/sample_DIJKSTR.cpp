#include "graph.h"
#include "queue.h"

int main()
{
	try{
	setlocale(0,"");
	//Graph g1(6,10); //random
	Graph g1(8);
	g1.edge[0][1] = 2;
	g1.edge[0][2] = 1;
	g1.edge[0][3] = 0;
	g1.edge[0][4] = 5;
	g1.edge[0][5] = -1;
	g1.edge[0][6] = -1;
	g1.edge[0][7] = -1;

	g1.edge[1][2] = 2;
	g1.edge[1][3] = -1;
	g1.edge[1][4] = 2;
	g1.edge[1][5] = 3;
	g1.edge[1][6] = -1;
	g1.edge[1][7] = -1;

	g1.edge[2][3] = -1;
	g1.edge[2][4] = 4;
	g1.edge[2][5] = -1;
	g1.edge[2][6] = -1;
	g1.edge[2][7] = -1;

	g1.edge[3][4] = 3;
	g1.edge[3][5] = -1;
	g1.edge[3][6] = 8;
	g1.edge[3][7] = -1;

	g1.edge[4][5] = 1;
	g1.edge[4][6] = -1;
	g1.edge[4][7] = 4;

	g1.edge[5][6] = 7;
	g1.edge[5][7] = 2;

	g1.edge[6][7] = 5;
	for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<g1.gsize; j++)
			g1.edge[j][i] = g1.edge[i][j];
	cout << "Матрица смежности:" << endl;
	g1.Print();//

	int size = g1.gsize;
	int *up = new int[size];
	int *dist = new int[size];

	for (int i=0; i<size; i++)
		up[i] = -1; 
	
	for(int i=0; i<size; i++)
		dist[i] = INT_MAX;//
	//Дейкстр
	int r0 = 0;
	dist[r0] = 0;
	while (r0<g1.gsize)
	{
		for(int i=0; i<g1.gsize;i++)
		{
			if((i==r0) || /*(g1.edge[i][r0]==0) ||*/ (g1.edge[i][r0]==-1))
				continue;

			int k=dist[i], r=dist[r0], f=g1.edge[i][r0];
			int delta = k - (r + f);
			if (delta>0)
			{
				dist[i] = dist[i] - delta;
				g1.edge[i][i] = dist[i];
				up[i] = r0;
			}
			
			g1.edge[r0][i] = -1;
			/*пошагово
			for(int i=0; i<size; i++)
				cout << dist[i] << " ";
			cout << endl;
			g1.Print();
			cout << endl;
			for(int i=0; i<size; i++)
				cout << up[i] << " ";
			cout << endl;
			*/
		}
		r0++;
	}//дейкстр
	//вывод
	cout << endl;
	cout << "Вывод алгоритма Дейкстра:" << endl;
	cout << "dist: ";
	for(int i=0; i<size; i++)
			cout << dist[i] << " ";
	cout << endl;

	g1.Print();
	cout << endl;

	cout << "up: ";
	for(int i=0; i<size; i++)
		cout << up[i] << " ";
	cout << endl;
	
	cout << "edge[i][i]: ";
	for(int i=0; i<size; i++)
		cout << g1.edge[i][i] << " ";
	cout << endl;
	system("pause");
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		system("pause"); 
		return 0;
	}
	return 0;
}