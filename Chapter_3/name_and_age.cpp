#include "../std_lib_facilities.h"

int main()
{
	cout << "Please enter your first name and age: ";
	string first_name = "??";
	double age_in_years = 0;
	cin >> first_name >> age_in_years; 
	//write out age in months. 
	double age_in_months = age_in_years * 12;
	cout << "Hello, I am " << first_name << " and I am " << age_in_months << " months old!\n";
}