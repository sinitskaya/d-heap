#pragma once
#include <iostream>
using namespace std;
typedef int VT;
class D_heap 
{
private:
	int size;                  //число элементов в куче
	int d;                     //число потомков
	int Islist(int i);         //проверка эл-та на лист
public:   	
	VT *keys;        
	D_heap(int s, int d);
	D_heap(const D_heap & heap);
	~D_heap();

	int GetSize();
	void Swap(int i, int j);            //транспонирование
	void siftUp(int i);                 //всплытие
	void siftDown(int i);               //погружение
	void DeleteMinKey();                //удаление с мин ключом
	void DeleteIndex(int i);            //удаление с заданным индексом
	void Heapify();                     //окучивание
	int MinChild(int i);                 //индекс минимального потомка
	void InsertKey(VT key);             //вставка нового ключа
	int Hight();                        //кол-во слоев(высота)
	void Print();

	int operator ==(const D_heap &heap)const;
	int operator !=(const D_heap &heap)const;
	D_heap& operator =(const D_heap &heap);
};