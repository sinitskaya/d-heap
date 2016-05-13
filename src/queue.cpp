#include "queue.h"
/*
Queue:: Queue(int s)
{
	if (s<=0) 
		throw exception ("Size<=0");
	qsize = s;
	q = new int[qsize];
	//heap = new D_heap(qsize,2);       //�� �� 0
}
Queue:: Queue (const int *p, const int psize)
{
	if (psize<=0) 
		throw exception ("Size<=0");
	qsize = psize;
	q = new int[qsize];
	for (int i=0; i<qsize; i++)
		q[i] = p[i];
}
Queue:: Queue(const Queue &que)
{
	qsize = que.qsize;
	for (int i=0; i<qsize; i++)
		q[i] = que.q[i];    //�� �� 0
}
Queue:: ~Queue()
{
	delete[] q;
}

void Queue:: Pop() //������� �� ������(� ��� ������)
{//��� ������ ����� ������ ��� � ����������
	if (qsize==0)
		return;
	D_heap heap(q, qsize, 2);
	
	int i=0;
	while (heap.keys[0]!=q[i])
		i++;
	//q[i] = -1;
	qsize--;
}
int Queue:: IsEmpty()
{
	if (qsize == 0)
		return 1;
	return 0;
}
void Queue:: Print()
{
	cout << "QUEUE: " << endl;
	
	if (IsEmpty())
	{
		cout << "Empty" << endl;
		return;
	}

	for (int i=0; i<qsize; i++)
		cout << q[i] << " ";
	cout << endl;
}
Queue& Queue:: operator =(const Queue& q1)
{
	if (this!= &q1)
	{
		qsize = q1.qsize;
		for(int i=0; i<qsize; i++)
			q[i] = q1.q[i];
	}
	return *this;
}

*/

void Queue:: SetQsize(int s)
{
	qsize = s;
	heap->size = s;
}
Queue:: Queue(int s)
{
	if (s<=0) 
		throw exception ("Size<=0");
	qsize = s;
	heap = new D_heap(qsize,2,0);       //�� �� 0
}
void Queue:: Insert(node n,int i)
{
	heap->nd[i].v1 = n.v1;
	heap->nd[i].v2 = n.v2;
	heap->nd[i].ves = n.ves;
	heap->keys[i] = n.ves;
}
Queue:: Queue(const int *p, const int psize)
{
	if (psize<=0) 
		throw exception ("Size<=0");
	qsize = psize;
	heap = new D_heap(p,psize,2);
}
////////////////////////////////////////////////////////////////////////
Queue:: Queue(node *n, const int nsize)
{
	if (nsize<=0) 
		throw exception ("Size<=0");
	qsize = nsize;
	heap = new D_heap(n,nsize,2);
}
////////////////////////////////////////////////////////////////////////
Queue:: Queue(const Queue &que)
{
	qsize = que.qsize;
	heap  = que.heap;    //�� �� 0
}
void Queue:: Pop()
{
	if (qsize==0)
		return;
	heap->DeleteMinKey();
	qsize--;
}

int Queue:: IsEmpty()
{
	return heap->IsEmpty();     //size==0 / gsize
}

void Queue:: Print()
{
	cout << "QUEUE: " << endl;
	
	if (IsEmpty())
	{
		cout << "Empty" << endl;
		return;
	}

	for (int i=0; i<qsize; i++)
		cout << heap->keys[i] << " ";
	cout << endl;
}

Queue& Queue:: operator =(const Queue& q)
{
	if (this!= &q)
	{
		for(int i=0; i<q.heap->size; i++)
			heap = q.heap;
	}
	return *this;
}

Queue:: ~Queue(){
	delete heap;
}
////////////////////////////////////////////////
void Queue:: print1()
{
	heap->print1();
}
////////////////////////////////////////////////
node Queue:: Top()
{
	return heap->nd[0];
}
///////////////////////////////////////////////