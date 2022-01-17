#include "../std_lib_facilities.h"

//converts Celcius to Kevin
double ctok(double c)
{
	double k = c + 273.15;
	return k;
}


int main()
{
	double c = 0;
	cin >> c; 
	constexpr double min_c = -273.15;
	if (c < min_c) 
		error("main(): c smaller than -273.15 ");
	double k = ctok(c); 
	cout << (k) <<"\n";
	return 0;
}