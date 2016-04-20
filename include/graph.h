#pragma once
#include <iostream>
using namespace std;

class Graph
{
public:
	
	int gsize;  //����� ������(������ ����)
	int **edge;  //��������� �����, ���� ���������
	Graph(int s);
	Graph(int s, int k);
	Graph(const Graph &g);
	~Graph();
	void InitGraph();
	void Print();
};