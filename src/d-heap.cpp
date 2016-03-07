#include "d-heap.h"

D_heap:: D_heap(int s, int d)
{
	if (s<0)
		throw exception ("Negative size");
	if (s>MAX_D_HEAP_SIZE)
		throw exception("Size more than MAX_D_HEAP_SIZE");

	size = s;
	this->d = d;
	this->keys = new VT[size];

	for (int i=0; i<size; i++)
		keys[i] = 0;
}

D_heap::  D_heap(const D_heap & heap)
{
	size = heap.size;
	d = heap.d;
	keys = new VT[size];
	for (int i=0; i<size; i++)
		keys[i] = heap.keys[i];
}

D_heap:: ~D_heap(){
	delete [] keys;
}

void D_heap:: Swap(int i, int j)    //транспонирование
{
	if ((i>=size) || (j>=size))
		throw exception ("Incorrect index");
	VT tmp;
	tmp = keys[i];
	keys [i] = keys[j];
	keys[j] = tmp;
}

int D_heap:: GetSize(){
	return size;
}

int D_heap:: GetD(){
	return d;
}

void D_heap:: siftUp(int i) //всплытие
{
	if (i >= size){
		throw exception ("Incorrect index");
	}
	if (d == 0) return;
	int iparent = (i-1)/d;
	while ((iparent >=0) && (keys[iparent]>keys[i])) {
		Swap(i,iparent);
		i = iparent;
		iparent = (i-1)/d;
	}
}

int D_heap:: MinChild(int i) 
{
	if (i >= size)
		throw exception ("Incorrect index");

	if (Islist(i))
		return -1; //лист у него нет детей
	VT minChild = keys[i*d+1];
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
	if ((i<0) || (i>=size)) 
		throw exception ("Incorrect index");
	if (size == 0)
		return;
	int ichild = MinChild(i);
	while (!Islist(i) && (keys[ichild]<keys[i]))
	{
		Swap(ichild,i);
		i = ichild;
		ichild = MinChild(i);
	}
}

void D_heap:: DeleteMinKey() //удаление с мин ключом
{
	if (size == 0)
		return;
	VT min_key = keys[0];
	keys[0] = keys[size-1];
	size--;
    siftDown(0);
}

void D_heap:: DeleteIndex(int i)  //удаление с заданным индексом
{
	if ((i>=size)|| (i<0))
		throw exception ("Incorrect index");

	keys[i] = keys[size-1];
	size--;
    siftDown(i);
}

void D_heap:: Heapify() //окучивание
{
	if ((d==0) || (size==0)) return;
	for (int i=(size/d); i>=0; i--)
		siftDown(i);
}

void D_heap:: InsertKey(VT key)
{
	D_heap heap(size++,d);
	heap = *this;
	heap.keys[heap.size-1] = key;
	heap.siftUp(size-1);
	*this = heap;
}

void D_heap:: Print(){
	cout << "D_HEAP: " << endl;
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
		keys = new VT[size];
		for (int i=0; i<size; i++)
			keys[i] = heap.keys[i];
	}
	return *this;
}

VT & D_heap:: operator [](int pos)
{
	if ((pos>=size) || (pos<0))
		throw exception ("Incorrect index");
	return keys[pos];
}