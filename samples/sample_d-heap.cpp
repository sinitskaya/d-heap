#include "d-heap.h"
#include <ctime>

int main()
{
	try
	{
		setlocale(0,"");
		srand (time(0));
		D_heap heap(20,5);
		for (int i=0; i<heap.GetSize(); i++)
			heap.keys[i] = ( rand() %10 );
		cout << "Random: "; heap.Print(); cout << endl;

		cout << "Heapify: "; heap.Heapify(); heap.Print();
	                                   
		D_heap h(heap);
		for (int i=(h.size-1); i>0; i--)
		{
			h.Swap(0,i);
			h.size--;
			h.siftDown(0);
		}
		h.size = heap.size;
		cout << endl << "Отсортированный: "<< endl; h.Print();
		system("pause");
	}

	catch (exception &e)
	{
		cout << endl << e.what() << endl;
		system("pause");
		return 0;
	}
	return 0;
}