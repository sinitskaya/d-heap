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
	int d;                     //����� ��������
	int Islist(int i);         //�������� ��-�� �� ����
public:
	int size;                  //����� ��������� � ����
	VT *keys;      
	node *nd;

	D_heap(int s, int d); //nd=0
	D_heap(int s, int d, int k);//nd !=0
	D_heap(const D_heap & heap);
	D_heap(node *n, const int nsize, int d);
	D_heap(const int *p, const int psize,int d);
	~D_heap();

	int GetD();
	void Swap(int i, int j);            //����������������
	void siftUp(int i);                 //��������
	void siftDown(int i);               //����������
	void DeleteMinKey();                //�������� � ��� ������
	void DeleteIndex(int i);            //�������� � �������� ��������
	void Heapify();                     //����������
	int MinChild(int i);                 //������ ������������ �������
	void InsertKey(VT key);             //������� ������ �����
	int Hight();                        //���-�� �����(������)
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