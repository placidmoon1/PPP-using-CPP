#include "../std_lib_facilities.h"

//converts Celcius to Kevin
//two errors in original code: narrowing error in int k, 
// and variable error in return int
double ctok(double c)
{
	double k = c + 273.15;
	return k;
}


int main()
{
	double c = 0;
	cin >> c; // variable misspell error
	double k = ctok(c); // string adding error
	cout << (k) <<"\n"; //cout capital 
	return 0;
}