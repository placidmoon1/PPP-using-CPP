#include "../std_lib_facilities.h"

int main(){
	double km_input = 0.0;
	const double km_to_mile = 1.609; // 1 mile = 1.609km
	
	cout << "[Prompt] Enter km value you want to convert: ";
	cin >> km_input;
	cout << "In miles, " << km_input << " km is " << km_input / km_to_mile << " miles !\n";
	return 0;	
}