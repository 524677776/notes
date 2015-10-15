#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::testLinearList()
{
	LinearList<int> L(3);
	cout << "L Length = " << L.Length() << endl;

	L.Insert(0, 2).Insert(1, 6);
	cout << "L Length = " << L.Length() << endl;

	int z;
	L.Find(1, z);
	cout << "L First element is: " << z << endl;
	cout << "L Length = " << L.Length() << endl;

	L.Delete(1, z);
	cout << "L Delete element is: " << z << endl;
	cout << "L Length = " << L.Length() << endl;

	cout << "L List is " << L << endl;
	L.Insert(0, 2).Insert(1, 6);
	cout << "L List is " << L << endl;
}

void Test::testChain()
{
	Chain<int> L2;
	cout << "L2 Length = " << L2.Length() << endl;

	L2.Insert(0, 2).Insert(1, 6);
	cout << "L2 Length = " << L2.Length() << endl;
}