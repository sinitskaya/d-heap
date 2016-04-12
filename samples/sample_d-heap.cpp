#include "d-heap.h"
#include <ctime>

int main()
{
	try
	{
		setlocale(0,"");
		srand (time(0));
		D_heap h(20,5);

	    h.Print();
		int hsize = h.size;
		for (int i=(h.size-1); i>0; i--)
		{
			h.Swap(0,i);
			h.size--;
			h.siftDown(0);
		}
		h.size = hsize;
		cout << endl << "Отсортированный: "<< endl; h.PrintMas();
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