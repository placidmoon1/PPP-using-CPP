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

//converts Kevin to Celcius
double ktoc(double k)
{
	constexpr double min_k = 0;
	if (k < min_k)
		error("ktoc(): k smaller than allowed temp");
	double c = k - 273.15;
	return c;
}


int main()
{
	cout << "K->C, C->K Temp Converter\n"
		 << "Please write the unit of the temp as c or k (24.3c, 21.5k): ";
	
	char convert_to;
	double temp;
	double ans = 0;
	cin >> temp >> convert_to;  
	
	switch (convert_to) {
		case 'k': 
			ans = ktoc(temp);
			break;
		case 'c':
			ans = ctok(temp);
			break;
		default:
			error("Wrong temp type. Allowed is k or c");
			break;
	}
	cout << temp << convert_to << " converted is " << ans <<"\n";
	return 0;
}