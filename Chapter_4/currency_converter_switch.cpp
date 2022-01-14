#include "../std_lib_facilities.h"

int main()
{
	//const values as of Jan 13, 2022
	constexpr double error = -1.0; //error code
	constexpr double yen_to_dollar = 0.0087;
	constexpr double kroner_to_dollar = 0.12;
	constexpr double pound_to_dollar = 1.37;	
	constexpr double yuan_to_dollar = 0.16;

	
	double currency_val = 0.0;
	double in_dollars = 0.0; //conveted currency_val, in dollars
	char unit = 'a';
	
	cout << "Please enter a monetary value followed by its currency unit.\n";
	cout << "Valid units are y = yen, k = kroner, u= yuan, or p = pound: ";
	cin >> currency_val >> unit;
	
	switch (unit) {
		case 'y':
			in_dollars = currency_val * yen_to_dollar;
			break;
		case 'k':
			in_dollars = currency_val * kroner_to_dollar;
			break;
		case 'p':
			in_dollars = currency_val * pound_to_dollar;
			break;
		case 'u':
			in_dollars = currency_val * yuan_to_dollar;
			break;
		default:
			in_dollars = error; //when it doesn't match any acceptable cases, error!
			break;
	}
	
	if (in_dollars == error)
		cout << "Enter correctly. Allowed units are y (yen), k (kroner), p (pound), and u(yuan)!\n";
	else 
		cout << currency_val << unit << " in dollars is $" << in_dollars << ".\n";
	
	return 0;
	
}