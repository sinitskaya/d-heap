#include "disjoint_set.h"
#include "graph.h"
#include "queue.h"

int main()
{
	try{
	setlocale(0,"");
	//Graph g1(6,10);
	int r1 = -1;
	cout << "Пользовательский ввод - 0"<< endl << "Пример - 1"<< endl;
	cin >> r1;
	Graph g1(8);
	if (r1 == 0)
	{
		Graph g2(1,1,1);
		g1 = g2;
	}
	if (r1 == 1)
	{
		Graph g2(8);
		//g2.Print();
		g2.edge[0][1] = 2;
		g2.edge[0][2] = 1;
		g2.edge[0][3] = 0;
		g2.edge[0][4] = 5;
		g2.edge[0][5] = -1;
		g2.edge[0][6] = -1;
		g2.edge[0][7] = -1;

		g2.edge[1][2] = 2;
		g2.edge[1][3] = -1;
		g2.edge[1][4] = 2;
		g2.edge[1][5] = 3;
		g2.edge[1][6] = -1;
		g2.edge[1][7] = -1;

		g2.edge[2][3] = -1;
		g2.edge[2][4] = 4;
		g2.edge[2][5] = -1;
		g2.edge[2][6] = -1;
		g2.edge[2][7] = -1;

		g2.edge[3][4] = 3;
		g2.edge[3][5] = -1;
		g2.edge[3][6] = 8;
		g2.edge[3][7] = -1;

		g2.edge[4][5] = 1;
		g2.edge[4][6] = -1;
		g2.edge[4][7] = 4;

		g2.edge[5][6] = 7;
		g2.edge[5][7] = 2;

		g2.edge[6][7] = 5;
		
		for(int i=0; i<g2.gsize; i++)
			for(int j=0; j<g2.gsize; j++)
				g2.edge[j][i] = g2.edge[i][j];
		//g2.Print();
		g1 = g2;
	}

	/*for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<g1.gsize; j++)
			g1.edge[j][i] = g1.edge[i][j];*/
	cout << "Матрица смежности:" << endl;
	g1.Print();//
	cout << endl;
	/////////////////////////////////((size*size)/2)
	int size = 8; //n={12,76,98};
	int s = ((size*size)/2);
	Edge *n = new Edge[s];
	//int *dist = new int[s];

	cout << "Список ребер: ";
	int k = 0;
	for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<i; j++)
			if ( (j!=i) && (g1.edge[i][j]!=-1) )
			{
				n[k].v1 = i;
				n[k].v2 = j;
				n[k].ves = g1.edge[i][j];	//VType & VType1
				k++;
				//dist[i] = g1.edge[i][j];
				//cout << dist[i] << " ";
			}
	//cout << endl;
	
	D_heap_Queue q(k);
	int nkol=0, f=0;
	for(int i=0; i<k; i++)
		//if(n[i].ves!=-1) учли тут (g1.edge[i][j]!=-1)
		{
			q.Insert(n[i],f);
			nkol++;
			f++;
		}
	q.SetQsize(nkol);
	q.heap->Heapify();  //сортирует по возрастанию
	q.print1();			//вывод списка ребер

	Edge *newn = new Edge[nkol];					 //миним ост дер
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
		Edge bv = q.Top();
		int r = d.FindSubset(bv.v1); f = d.FindSubset(bv.v2);
		//cout << "d.FindSubset(bv.v1): " << r << "  d.FindSubset(bv.v2): " << f << endl;
		if(r!=f)
		{
			d.Union( d.FindSubset(bv.v1), d.FindSubset(bv.v2) );
			newn[t].v1 = bv.v1;
			newn[t].v2 = bv.v2;
			newn[t].ves = bv.ves;
			t++;
		}
		q.Pop();
		//q.print1();
	} cout << endl;
	cout << "Минимальное остовное дерево: " << endl; 
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

	//delete [] dist;
	//Disjoint_set set();
	/*Queue que1(10);
	Queue q1w(que1);
	que1 = q1w;
	D_heap h1(10,2); D_heap h2(10,2); h1=h2;
	*/

	delete [] n;
	delete [] newn;
	system("pause");
	}

	catch(exception &e)
	{
		cout << e.what() << endl;
		system("pause");
		return 0;
	}
}