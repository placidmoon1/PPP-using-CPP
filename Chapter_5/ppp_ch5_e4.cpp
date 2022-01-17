#include "../std_lib_facilities.h"

//converts Celcius to Kevin
double ctok(double c)
{
	constexpr double min_k = 0;
	double k = c + 273.15;
	if (k < min_k)
		error("ctok(): c smaller than allowed temp");
	return k;
}


int main()
{
	double c = 0;
	cin >> c; 
	double k = ctok(c); 
	cout << (k) <<"\n";
	return 0;
}