#pragma once
#include <iostream>
using namespace std;
const int MAX_D_HEAP_SIZE = 100000000;
typedef int VT;

class D_heap 
{
private:
	int d;                     //����� ��������
	int Islist(int i);         //�������� ��-�� �� ����
public:
	int size;                  //����� ��������� � ����
	VT *keys;        
	D_heap(int s, int d);
	D_heap(const D_heap & heap);
	~D_heap();

	int GetD();
	int GetSize();
	void Swap(int i, int j);            //����������������
	void siftUp(int i);                 //��������
	void siftDown(int i);               //����������
	void DeleteMinKey();                //�������� � ��� ������
	void DeleteIndex(int i);            //�������� � �������� ��������
	void Heapify();                     //����������
	int MinChild(int i);                 //������ ������������ �������
	void InsertKey(VT key);             //������� ������ �����
	int Hight();                        //���-�� �����(������)
	void Print();

	int operator ==(const D_heap &heap)const;
	int operator !=(const D_heap &heap)const;
	D_heap& operator =(const D_heap &heap);
	VT & operator [](int pos);
};