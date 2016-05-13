#pragma once
#include <iostream>
using namespace std;

class Graph
{
public:
	
	int gsize;  //число вершин(размер матр)
	int **edge;  //множество ребер, матр смежности
	Graph(int s);
	Graph(int s, int k);
	Graph(const Graph &g);
	~Graph();
	void InitGraph();
	void Print();
};