#include "d-heap.h"

D_heap:: D_heap(int s, int d, int k) //nd!=0 k-любое, key=0
{
	if (s<0)
		throw exception ("Negative size");
	if (s>MAX_D_HEAP_SIZE)
		throw exception("Size more than MAX_D_HEAP_SIZE");
	if (d<2)
		throw exception ("d<2");
	
	size = s;
	this->d = d;
	this->keys = new VType[size];
	nd = new Edge[size];

	for (int i=0; i<size; i++)
	{
		keys[i] = 0;
		nd[i].v1 = -1;
		nd[i].v2 = -1;
		nd[i].ves = -1;
	}
	Heapify();//+
}
D_heap:: D_heap(int s, int d) //nd=0
{
	if (s<0)
		throw exception ("Negative size");
	if (s>MAX_D_HEAP_SIZE)
		throw exception("Size more than MAX_D_HEAP_SIZE");
	if (d<2)
		throw exception ("d<2");

	size = s;
	this->d = d;
	this->keys = new VType[size];
	nd=0;
	/*for (int i=0; i<size; i++)
		keys[i] = 0;*/

	for (int i=0; i<size; i++)
			keys[i] = ( rand() %10 );
	/*cout << "Random: "; Print(); cout << endl;
	
	cout << "Heapify: "; Heapify(); Print();*/
	Heapify();//+_
}
/*D_heap:: D_heap(const int *p, const int psize, int d)//куча из массива
{
	if (p==0)
		throw exception ("p=0");
	if (d<2)
		throw exception ("d<2");
	if (psize<0)
		throw exception ("psize < 0");

	nd=0;
	size = psize;
	this->d = d;
	keys = new int[size];

	for (int i=0; i<size; i++)
		keys[i] = p[i];
	Heapify();
}*/
//////////////////////////////////////////////////////////////////////////////
D_heap:: D_heap(Edge *n, const int nsize, int d)//куча из  массива структур
{
	if (nsize<0)
		throw exception ("Negative size");
	if (d<2)
		throw exception ("d<2");
	if(n==0) 
		throw exception ("*n=0");

	size = nsize;
	this->d = d;
	keys = new VType[size];
	nd = new Edge[size];
	for(int i=0; i<size; i++)
		keys[i] = n[i].ves;

	for(int i=0; i<size; i++)
	{
		nd[i].ves = n[i].ves;
		nd[i].v1 = n[i].v1;
		nd[i].v2 = n[i].v2;
	}
	Heapify();//+
}
//////////////////////////////////////////////////////////////////////////
D_heap::  D_heap(const D_heap & heap)
{
	size = heap.size;
	d = heap.d;
	nd=0;
	keys = new VType[size];
	for (int i=0; i<size; i++)
		keys[i] = heap.keys[i];
}

D_heap:: ~D_heap(){
	delete [] keys;
	if (nd!=0)
		delete [] nd;
}

void D_heap:: Swap(int i, int j)    //транспонирование
{
	if ((i>=size) || (j>=size) || (i<0) || (j<0))
		throw exception ("Incorrect index in swap");
	VType tmp;
	tmp = keys[i];
	keys [i] = keys[j];
	keys[j] = tmp;
	if(nd!=0)
	{
		Edge tmp2;
		tmp2 = nd[i]; 
		nd[i] = nd[j];
		nd[j] = tmp2;
	}
}

int D_heap:: GetD(){
	return d;
}

void D_heap:: siftUp(int i) //всплытие
{
	if ((i >= size) || (i<0))
		throw exception ("Incorrect index in siftUp");
	
	if (d == 0) return;
	int iparent = (i-1)/d;
	while ((iparent >=0) && (keys[iparent]>keys[i])) {
		Swap(i,iparent);
		i = iparent;
		iparent = (i-1)/d;
	}
}

void D_heap:: SetD(int d1)
{
	d = d1;
}
int D_heap:: MinChild(int i) 
{
	if ((i >= size) || (i<0))
		throw exception ("Incorrect index in MinChild");

	if (Islist(i))
		return -1; //лист у него нет детей
	VType minChild = keys[i*d+1];
	int minc = i*d+1; //индекс мин потомка в масс
	for (int j=1; j<=d; j++)
		if ((minChild > keys[i*d+j]) && ((i*d+j)<size))
		{
			minChild = keys[i*d+j];
			minc = i*d+j;
		}
	return minc;
}

void D_heap:: siftDown(int i) //погружение
{
	if ((i<0) || (i>=size)) //>size-1//sift(0) - size=0
		throw exception ("Incorrect index in siftDown");
	/*if (size == 0)
		return;*/
	int ichild = MinChild(i); //индекс
	while (!Islist(i) && (keys[ichild]<keys[i]))
	{
		Swap(ichild,i);
		i = ichild;
		ichild = MinChild(i);
	}
}

void D_heap:: DeleteMinKey() //удаление с мин ключом
{
	Heapify();
	if (size == 0)
		return;
	VType min_key = keys[0];
	keys[0] = keys[size-1];            
	/////////////////////////////////////////////////
	if(nd!=0)
		nd[0] = nd[size-1];
	//////////////////////////////////////////////
	size--;
	if (size!=0)                    //size=0 - sifd(0) i=size=error-выход за масс
		siftDown(0);
}

void D_heap:: DeleteIndex(int i)  //удаление с заданным индексом
{
	if ((i>=size)|| (i<0))
		throw exception ("Incorrect index in DeleteIndex");

	keys[i] = keys[size-1];          
	if(nd!=0)
		nd[i] = nd[size-1];
	size--;
    siftDown(i);
}

void D_heap:: Heapify() //окучивание
{
	if ((d==0) || (size==0) || (size==1)) return;
	for (int i=(size/d); i>=0; i--)// при d=1, выход за массив
		siftDown(i);
}

void D_heap:: InsertKey(VType key)
{
	D_heap heap(size++,d);
	heap = *this;
	heap.keys[heap.size-1] = key;
	heap.siftUp(size-1);
	*this = heap;
}

void D_heap:: Print(){
	cout << "D_HEAP: " << endl;
	if (IsEmpty ())
	{
		cout << "IsEmpty" << endl;
		return;
	}
	int f = 1; //слои
	int h = Hight(); // высота
	int i = 0; //слои с нуля для подсчета эл-ов
	int k = 0; //индекс для массива
	while (f != (h+1)){
		f++;
		for (int j=0; j<pow(d,i); j++){
			if (k>(size-1))
				return;
			cout << keys[k] << " ";
			k++;
		}
		i++;
		cout << endl;
	}
	cout << endl;
}

void D_heap:: PrintMas()
{
	for (int i=size-1; i>=0; i--)
		cout << keys[i] << " ";
	cout << endl;
}

int D_heap:: Hight()
{
	if (size == 0)
	{
		cout << "not data";
		return 0;
	}
	int h=1; int i=0;
	while  (!( Islist(i) ))
	{
		i = i*d +1;
		h++;
	}
	return h;
}

int D_heap:: IsEmpty()
{
	if (size<0)
		throw exception ("size<0");
	if (size == 0)
		return 1;
	else return 0;
}

int D_heap:: Islist(int i)
{
	if ((i*d+1) > (size-1))
		return 1;
	else
		return 0;
}

int D_heap:: operator ==(const D_heap &heap)const
{
	if (this != &heap)
	{
		if ((size != heap.size) || (d!=heap.d))
			return 0;
		for (int i=0; i<size; i++)
			if (keys[i]!=heap.keys[i])
				return 0;
	}
	return 1;
}

int D_heap:: operator !=(const D_heap &heap)const
{
	return !(*this == heap);
}

D_heap& D_heap:: operator =(const D_heap &heap)
{
	if (this != &heap)
	{
		delete [] keys;
		size = heap.size;
		d = heap.d;
		keys = new VType[size];
		for (int i=0; i<size; i++)
			keys[i] = heap.keys[i];
	}
	return *this;
}

VType & D_heap:: operator [](int pos)
{
	if ((pos>=size) || (pos<0))
		throw exception ("Incorrect index in []");
	return keys[pos];
}
///////////////////////////////////////////////////////////////
void D_heap:: print1(void) // вывод со списком ребер
{
	cout << endl;
	for(int i=0; i<size; i++)
	{
		cout << "v1: " << nd[i].v1 << " ";
		cout << "v2: " << nd[i].v2 << " ";
		cout << "ves: " << nd[i].ves << " ";
		cout << endl;
	}
}
////////////////////////////////////////////////////