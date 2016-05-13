#pragma once
#include <iostream>
using namespace std;
const int MAX_D_HEAP_SIZE = 100000000;
typedef int VType;

struct Edge {
	int v1;	int v2;	 VType ves;
};

class D_heap 
{
private:
	int d;                     //число потомков
	int Islist(int i);         //проверка эл-та на лист
public:
	int size;                  //число элементов в куче
	VType *keys;      
	Edge *nd;

	D_heap(int s, int d);				//nd=0
	D_heap(int s, int d, int k);		//nd !=0 k - любое
	D_heap(const D_heap & heap);
	D_heap(Edge *n, const int nsize, int d);		//из структуры
	//D_heap(const int *p, const int psize,int d);	//из массива
	~D_heap();

	int GetD();							//получить d
	void SetD(int d1);                  //установить d
	void Swap(int i, int j);            //транспонирование
	void siftUp(int i);                 //всплытие
	void siftDown(int i);               //погружение
	void DeleteMinKey();                //удаление с мин ключом
	void DeleteIndex(int i);            //удаление с заданным индексом
	void Heapify();                     //окучивание
	int MinChild(int i);                //индекс минимального потомка
	void InsertKey(VType key);             //вставка нового ключа
	int Hight();                        //кол-во слоев(высота)
	int IsEmpty();
	void Print();		//вывод с высотой 
	void PrintMas();	//вывод массива

	int operator ==(const D_heap &heap)const;
	int operator !=(const D_heap &heap)const;
	D_heap& operator =(const D_heap &heap);
	VType & operator [](int pos);

	void print1(void);					// вывод со списком ребер
	//friend class Queue; 
};