#pragma once
#include <iostream>
using namespace std;
typedef int VType1;

class Graph
{
public:
	
	int gsize;		 //����� ������
	VType1 **edge;		 //��������� �����, ���� ���������

	Graph(int init, int, int);       //������������� �������������
	Graph(int s);			//���������� ����� ���� ������� � -1 �� ���������
	Graph(int s, int k);	//���������� ����� �������� ������� �� 0 �� k �� ������������
	Graph(const Graph &g);
	~Graph();
	Graph& operator =(const Graph &g);
	void Print();			//����� �����
};