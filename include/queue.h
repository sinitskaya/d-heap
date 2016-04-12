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
	D_heap *heap;
public:
	Queue(int s);
	Queue (const int *p, const int psize);
	Queue(const Queue &que);
	~Queue();

	void Pop();//изьятие из начала(с мин меткой)
	int IsEmpty();
	void Print();
	Queue& operator =(const Queue& q);
};
