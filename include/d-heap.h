#pragma once
#include <iostream>
using namespace std;
const int MAX_D_HEAP_SIZE = 100000000;
typedef int VT;

struct node {
	int v1;	int v2;	 int ves;
};

class D_heap 
{
private:
	//node *nd;
	int d;                     //число потомков
	int Islist(int i);         //проверка эл-та на лист
public:
	int size;                  //число элементов в куче
	VT *keys;      
	node *nd;

	D_heap(int s, int d); //nd=0
	D_heap(int s, int d, int k);//nd !=0
	D_heap(const D_heap & heap);
	D_heap(node *n, const int nsize, int d);
	D_heap(const int *p, const int psize,int d);
	~D_heap();

	int GetD();
	void Swap(int i, int j);            //транспонирование
	void siftUp(int i);                 //всплытие
	void siftDown(int i);               //погружение
	void DeleteMinKey();                //удаление с мин ключом
	void DeleteIndex(int i);            //удаление с заданным индексом
	void Heapify();                     //окучивание
	int MinChild(int i);                 //индекс минимального потомка
	void InsertKey(VT key);             //вставка нового ключа
	int Hight();                        //кол-во слоев(высота)
	int IsEmpty();
	void Print();
	void PrintMas();

	int operator ==(const D_heap &heap)const;
	int operator !=(const D_heap &heap)const;
	D_heap& operator =(const D_heap &heap);
	VT & operator [](int pos);

	void print1(void);
	//friend class Queue; 
};