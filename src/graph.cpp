#include "graph.h"
#include <ctime>

Graph:: Graph(int s)
{
	if (s<0)
		throw exception ("gsize<0");

	gsize = s;
	edge = new VType1*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new VType1[gsize];
	
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(i==j)
				edge[i][j] = -1;
			else
				edge[i][j] = INT_MAX;
		}
}

Graph:: Graph(int s, int k)
{
	if (s<0)
		throw exception ("gsize<0");
	if (k<=0)
		throw exception ("k<=0");

	gsize = s;
	//srand (time(0));
	edge = new VType1*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new VType1[gsize];
	
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
		{
			if(i==j)
				edge[i][j] = -1;
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

Graph:: Graph(int init, int, int)       //������������� �������������
{
	int kol; VType1 ves;

	cout << "������� ����� ������: ";
	cin >> kol;
	if (kol<0)
		throw exception ("kol<0");
	gsize = kol;

	//������
	edge = new VType1*[gsize*gsize];
	for(int i=0; i<gsize; i++)
		edge[i] = new VType1[gsize];

	//���������� -1
	for(int i=0; i<gsize; i++)
		for(int j=0; j<gsize; j++)
			edge[i][j] = -1;
	//
	cout << "������� ���� �����, ����������� ������� i,j: "<< endl;
	for(int i=0; i<=gsize-2; i++)				// ��������� nn �� �����
		for(int j=i+1; j<gsize; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << " = ";
			cin >> ves;
			edge[i][j] = ves;
		}

	//������ �������
	for(int i=0; i<=gsize-2; i++)
		for(int j=i+1; j<gsize; j++)
			edge[j][i] = edge[i][j];
}

Graph:: ~Graph()
{
	if(*edge!=0)
		for(int i=0; i<gsize; i++)
			delete [] edge[i];
}

Graph& Graph:: operator =(const Graph &g)
{
if (this != &g)
	{
		for(int i=0; i<gsize; i++)
			delete [] edge[i];
		gsize = g.gsize;

		edge = new VType1*[gsize*gsize];
		for(int i=0; i<gsize; i++)
			edge[i] = new VType1[gsize];
		
		for (int i=0; i<gsize; i++)
			for (int j=0; j<gsize; j++)
				edge[i][j] = g.edge[i][j];
	}
	return *this;
}