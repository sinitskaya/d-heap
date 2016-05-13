#pragma once
#include "d-heap.h"
/*
class Queue
{
private:

public:
	int qsize;
	int *q;
	Queue(int s);
	Queue (const int *p, const int psize);
	Queue(const Queue &que);
	~Queue();

	void Pop();//изьятие из начала(с мин меткой)
	int IsEmpty();
	void Print();
	Queue& operator =(const Queue& q);
};
*/
class Queue
{
private:
	int qsize;
	//D_heap *heap;
public:D_heap *heap;
	void SetQsize(int s);
	Queue(int s);
	Queue (const int *p, const int psize);
	Queue (node *n, const int nsize);
	Queue(const Queue &que);
	~Queue();

	void Pop();          //изьятие из начала(с мин меткой)
	node Top();
	void Insert(node n, int i);
	int IsEmpty();
	void Print();
	Queue& operator =(const Queue& q);
	void print1();
};
