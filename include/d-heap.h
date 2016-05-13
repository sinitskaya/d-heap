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
	int d;                     //����� ��������
	int Islist(int i);         //�������� ��-�� �� ����
public:
	int size;                  //����� ��������� � ����
	VType *keys;      
	Edge *nd;

	D_heap(int s, int d);				//nd=0
	D_heap(int s, int d, int k);		//nd !=0 k - �����
	D_heap(const D_heap & heap);
	D_heap(Edge *n, const int nsize, int d);		//�� ���������
	//D_heap(const int *p, const int psize,int d);	//�� �������
	~D_heap();

	int GetD();							//�������� d
	void SetD(int d1);                  //���������� d
	void Swap(int i, int j);            //����������������
	void siftUp(int i);                 //��������
	void siftDown(int i);               //����������
	void DeleteMinKey();                //�������� � ��� ������
	void DeleteIndex(int i);            //�������� � �������� ��������
	void Heapify();                     //����������
	int MinChild(int i);                //������ ������������ �������
	void InsertKey(VType key);             //������� ������ �����
	int Hight();                        //���-�� �����(������)
	int IsEmpty();
	void Print();		//����� � ������� 
	void PrintMas();	//����� �������

	int operator ==(const D_heap &heap)const;
	int operator !=(const D_heap &heap)const;
	D_heap& operator =(const D_heap &heap);
	VType & operator [](int pos);

	void print1(void);					// ����� �� ������� �����
	//friend class Queue; 
};