#include "queue.h"

void D_heap_Queue:: SetQsize(int s)
{
	if(s<0)
		throw exception ("gsize<0");

	qsize = s;
	heap->size = s;
}

D_heap_Queue:: D_heap_Queue(int s)
{
	if (s<=0) 
		throw exception ("Size<=0");

	qsize = s;
	heap = new D_heap(qsize,2,0);       //из 0
}

void D_heap_Queue:: Insert(Edge n, int i)      //вставка ребра
{
	if((i<0) || (i>qsize-1))
		throw exception ("Not correct index");

	heap->nd[i].v1 = n.v1;
	heap->nd[i].v2 = n.v2;
	heap->nd[i].ves = n.ves;
	heap->keys[i] = n.ves;
}
/*Queue:: Queue(const int *p, const int psize)
{
	if (psize<=0) 
		throw exception ("Size<=0");
	qsize = psize;
	heap = new D_heap(p,psize,2);
}*/
////////////////////////////////////////////////////////////////////////
D_heap_Queue:: D_heap_Queue(Edge *n, const int nsize)			//из ребер (структура)
{
	if (nsize<=0) 
		throw exception ("Size<=0");
	if(n==0)
		throw exception ("*n=0");

	qsize = nsize;
	heap = new D_heap(n,nsize,2);
}
////////////////////////////////////////////////////////////////////////
D_heap_Queue:: D_heap_Queue(const D_heap_Queue &que)
{
	qsize = que.qsize;
	int D = que.heap->GetD();

	/*if(que.heap->nd==0) //nd!=0 везде, нет конструктора, где nd==0
	{
		heap = new D_heap(qsize, D); //nd=0; keys=random

		for(int i=0; i<qsize; i++)
			heap->keys[i] = que.heap->keys[i];

	}*/

	if(que.heap->nd!=0)
	{
		heap = new D_heap(qsize, D, 1); 
		for(int i=0; i<qsize; i++)
		{
			heap->nd[i].v1 = que.heap->nd[i].v1;
			heap->nd[i].v2 = que.heap->nd[i].v2;
			heap->nd[i].ves = que.heap->nd[i].ves;
		}
	}
	//heap = que.heap;
	//heap = h;    //не из 0 //*heap
}

void D_heap_Queue:: Pop()			//изьятие из начала(с мин меткой)
{
	if (qsize==0)
		return;
	heap->DeleteMinKey();
	qsize--;
}

int D_heap_Queue:: IsEmpty()
{
	return heap->IsEmpty();     //size==0 / gsize
}
/*
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
*/
D_heap_Queue& D_heap_Queue:: operator =(const D_heap_Queue& q)
{
	if (this!= &q)
	{
		qsize = q.qsize;
		int D = q.heap->GetD();

		if(q.heap->nd!=0)//////////////////
		{
			delete [] heap->keys;
			heap = new D_heap(qsize, D, 1); 
			for(int i=0; i<qsize; i++)
			{
				heap->nd[i].v1 = q.heap->nd[i].v1;
				heap->nd[i].v2 = q.heap->nd[i].v2;
				heap->nd[i].ves = q.heap->nd[i].ves;
			}
		}////////////////////////////////
		/*if(q.heap->nd==0) //nd!=0 везде, нет конструктора, где nd==0
		{
			heap = new D_heap(qsize, D); //nd=0; keys=random

			for(int i=0; i<qsize; i++)
				heap->keys[i] = q.heap->keys[i];

		}*/
		//for(int i=0; i<q.heap->size; i++)
			//heap = q.heap;
	}
	return *this;
}
/////////////////////////////////////////////////////////////
int D_heap_Queue :: operator !=(const D_heap_Queue &q)const
{
	return !(*this == q);
}

int D_heap_Queue :: operator ==(const D_heap_Queue &q)const
{
	if (this != &q)
	{
		if ((qsize != q.qsize) )
			return 0;

		for (int i=0; i<qsize; i++)
			if (heap->nd[i].v1!=q.heap->nd[i].v1)
				return 0;
		for (int i=0; i<qsize; i++)
			if (heap->nd[i].v2!=q.heap->nd[i].v2)
				return 0;

		for (int i=0; i<qsize; i++)
			if (heap->keys[i]!=q.heap->keys[i])
				return 0;
	}
	return 1;
}
////////////////////////////////////////////////////////////////////
D_heap_Queue:: ~D_heap_Queue(){
		//heap = 0;
		delete heap;
}
////////////////////////////////////////////////
void D_heap_Queue:: print1()		//вывод со списком ребер
{
	heap->print1();
}
////////////////////////////////////////////////
Edge D_heap_Queue:: Top()			//изьятие ребра
{
	return heap->nd[0];
}
///////////////////////////////////////////////
int D_heap_Queue:: GetQsize(void){
	return qsize;
}
