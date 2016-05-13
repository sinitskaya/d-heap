#include "disjoint_set.h"
#include "graph.h"
#include "queue.h"

int main()
{
	try{
	setlocale(0,"");
	//Graph g1(6,10);
	Graph g1(8);
	g1.edge[0][1] = 2;
	g1.edge[0][2] = 1;
	g1.edge[0][3] = 0;
	g1.edge[0][4] = 5;
	g1.edge[0][5] = 0;
	g1.edge[0][6] = 0;
	g1.edge[0][7] = 0;

	g1.edge[1][2] = 2;
	g1.edge[1][3] = 0;
	g1.edge[1][4] = 2;
	g1.edge[1][5] = 3;
	g1.edge[1][6] = 0;
	g1.edge[1][7] = 0;

	g1.edge[2][3] = 0;
	g1.edge[2][4] = 4;
	g1.edge[2][5] = 0;
	g1.edge[2][6] = 0;
	g1.edge[2][7] = 0;

	g1.edge[3][4] = 3;
	g1.edge[3][5] = 0;
	g1.edge[3][6] = 8;
	g1.edge[3][7] = 0;

	g1.edge[4][5] = 1;
	g1.edge[4][6] = 0;
	g1.edge[4][7] = 4;

	g1.edge[5][6] = 7;
	g1.edge[5][7] = 2;

	g1.edge[6][7] = 5;
	for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<g1.gsize; j++)
			g1.edge[j][i] = g1.edge[i][j];
	cout << "ћатрица смежности:" << endl;
	g1.Print();//
	/////////////////////////////////((size*size)/2)
	int size = 8; //n={12,76,98};
	int s = ((size*size)/2);
	node *n = new node[s];
	int *dist = new int[s];

	int k = 0;
	for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<i; j++)
			if (j!=i)
			{
				n[k].v1 = i;
				n[k].v2 = j;
				n[k].ves = g1.edge[i][j];
				k++;
				dist[i] = g1.edge[i][j];
				cout << dist[i] << " ";
			}
	cout << endl;
	
	Queue q(k);
	int nkol=0, f=0;
	for(int i=0; i<k; i++)
		if(n[i].ves!=0)
		{
			q.Insert(n[i],f);
			nkol++;
			f++;
		}
	q.SetQsize(nkol);
	q.heap->Heapify(); //сортирует по возрастанию
	q.print1();

	node *newn = new node[nkol];
	for(int i=0; i<nkol; i++)
	{
		newn[i].v1 = -1;
		newn[i].v2 = -1;
		newn[i].ves = -1;
	}

	Disjoint_set d(size); //0 до 7
	for( int i=0; i<=7; i++)
		d.CreateSingleton(i);
	
	int t = 0;
	//cout << "v1: " << bv.v1 << "v2: " << bv.v2 << "ves: " << bv.ves;
	while( (!q.IsEmpty()) && (t<size-1) ) //&& (t<size-1)
	{
		node bv = q.Top();
		int r = d.FindSubset(bv.v1); f = d.FindSubset(bv.v2);
		//cout << "d.FindSubset(bv.v1): " << r << "  d.FindSubset(bv.v2): " << f << endl;
		if(r!=f)
		{
			d.Union(d.FindSubset(bv.v1), d.FindSubset(bv.v2));
			newn[t].v1 = bv.v1;
			newn[t].v2 = bv.v2;
			newn[t].ves = bv.ves;
			t++;
		}
		q.Pop();
		//q.print1();
	}
	cout << "ћинимальное остовное дерево: " << endl; 
	for(int i=0; i<t; i++)
		cout << "v1: " << newn[i].v1 << "  v2: " << newn[i].v2 << "  ves: " << newn[i].ves << endl;

	/*d.CreateSingleton(1);
	d.CreateSingleton(2);
	d.CreateSingleton(3);
	d.CreateSingleton(4);
	d.CreateSingleton(5);
	d.CreateSingleton(6);
	d.CreateSingleton(7);
	d.CreateSingleton(8);
	d.CreateSingleton(9);*/
	
	/*d.Union(3,9);
	d.Union(7,3);
//	d.Union(7,4);*/
	/*d.Union(1,2);
	d.Union(3,7);
	d.Union(3,1);
	d.Union(6,4);
	d.Union(6,3);
	d.Print();cout << endl;
	cout << d.FindSubset(4) << endl;*/

	delete [] dist;
	delete [] n;
	delete [] newn;
	return 0;
	}

	catch(exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
}