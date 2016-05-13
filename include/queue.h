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
public:
	
	//Queue(int s);
	//Queue (const int *p, const int psize);	//из массива
	//Queue (Edge *n, const int nsize);			//из ребер (структура)
	//Queue(const Queue &que);
	//virtual ~Queue() = 0;
	
	virtual void SetQsize(int s) = 0;
	virtual int GetQsize(void) = 0;
	
	virtual void Pop() = 0;						//изьятие из начала(с мин меткой)
	virtual Edge Top() = 0;						//изьятие ребра без удаления
	
	virtual void Insert(Edge n, int i) = 0;		//вставка ребра
	virtual int IsEmpty() = 0;
	////void Print();					//вывод массива
	
	//Queue& operator =(const Queue& q);
	//int operator ==(const Queue &q)const;
	//int operator !=(const Queue &q)const;
	
	virtual void print1() = 0;		//вывод со списком ребер
};

class D_heap_Queue : public Queue
{
private:
	int qsize;
public:
	D_heap *heap;
	D_heap_Queue(int s);
	//Queue (const int *p, const int psize);	//из массива
	D_heap_Queue (Edge *n, const int nsize);			//из ребер (структура)
	D_heap_Queue(const D_heap_Queue &que);
	~D_heap_Queue();

	virtual void SetQsize(int s);
	virtual int GetQsize(void);

	virtual void Pop();						//изьятие из начала(с мин меткой)
	Edge Top();						//изьятие ребра без удаления

	virtual void Insert(Edge n, int i);		//вставка ребра
	int IsEmpty();
	//void Print();					//вывод массива

	D_heap_Queue& operator =(const D_heap_Queue& q);
	int operator ==(const D_heap_Queue &q)const;
	int operator !=(const D_heap_Queue &q)const;

	void print1();		//вывод со списком ребер
};
