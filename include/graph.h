#pragma once
#include <iostream>
using namespace std;
typedef int VType1;

class Graph
{
public:
	
	int gsize;		 //число вершин
	VType1 **edge;		 //множество ребер, матр смежности

	Graph(int init, int, int);       //инициализация пользователем
	Graph(int s);			//заполнение графа макс числами и -1 по диагонали
	Graph(int s, int k);	//заполнение графа рандомно числами от 0 до k не включительно
	Graph(const Graph &g);
	~Graph();
	Graph& operator =(const Graph &g);
	void Print();			//вывод графа
};