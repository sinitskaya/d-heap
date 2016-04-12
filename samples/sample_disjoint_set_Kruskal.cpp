#include "disjoint_set.h"

int main()
{
	try{
	Disjoint_set d;
	d.CreateSingleton(1);
	d.CreateSingleton(2);
	d.CreateSingleton(3);
	d.CreateSingleton(4);
	d.CreateSingleton(5);
	d.CreateSingleton(6);
	d.CreateSingleton(7);
	d.CreateSingleton(8);
	d.CreateSingleton(9);
	
	/*d.Union(3,9);
	d.Union(7,3);
//	d.Union(7,4);*/
	d.Union(1,2);
	d.Union(3,7);
	d.Union(3,1);
	d.Union(6,4);
	d.Union(6,3);
	d.Print();cout << endl;
	cout << d.FindSubset(4) << endl;

	return 0;
	}

	catch(exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
}