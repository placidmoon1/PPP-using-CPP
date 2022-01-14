#include "../std_lib_facilities.h"

int main()
{
	//const values as of Jan 13, 2022
	constexpr double error = -1.0; //error code
	constexpr double yen_to_dollar = 0.0087;
	constexpr double kroner_to_dollar = 0.12;
	constexpr double pound_to_dollar = 1.37;
	
	double currency_val = 0.0;
	double in_dollars = 0.0; //conveted currency_val, in dollars
	char unit = 'a';
	
	cout << "Please enter a monetary value followed by its currency unit (y, k, or p): ";
	cin >> currency_val >> unit;
	
	if (unit == 'y')
		in_dollars = currency_val * yen_to_dollar;
	else if (unit == 'k')
		in_dollars = currency_val * kroner_to_dollar;
	else if (unit == 'p')
		in_dollars = currency_val * pound_to_dollar;
	else
		in_dollars = error;
	
	if (in_dollars == error)
		cout << "Enter correctly. Allowed units are y (yen), k (kroner), and p (pound)";
	else 
		cout << currency_val << unit << " in dollars is " << in_dollars << ".\n";
	
	return 0;
}