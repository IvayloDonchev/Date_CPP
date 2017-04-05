#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
	Date d1(12, 10, 2016);
	cout << d1 << endl;			// 12.10.2016
	cout << ++d1 << endl;		// 13.10.2016
	cout << d1 << endl;			// 13.10.2016
	cout << d1++ << endl;		// 13.10.2016
	cout << d1 << endl;			// 14.10.2016
	cout << --d1 << endl;		// 13.10.2016
	cout << d1 << endl;			// 13.10.2016
	cout << d1-- << endl;		// 13.10.2016
	cout << d1 << endl;			// 12.10.2016

	cin >> d1;
	cout << d1 << endl;

}