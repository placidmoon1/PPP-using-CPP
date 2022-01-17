#include "../std_lib_facilities.h"

//converts celcius to fareheit
double ctof(double c)
{
	double f = 9.0/5 * c + 32;
	return f;
}

//converts fareheit to celcius
double ftoc(double f)
{
	double c = (f - 32) * 5.0/9;
	return c;
}

int main() {
	double u_temp;
	
	cout << "F -> C, C-> F converter:: ";
	cin >> u_temp;
	cout << u_temp << "C in Fareheit is " << ctof(u_temp) << "\n";
	cout << u_temp << "F in Celcius is " << ftoc(u_temp) << "\n";
	
	return 0;
}