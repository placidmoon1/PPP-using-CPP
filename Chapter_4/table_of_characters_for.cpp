#include "../std_lib_facilities.h"

int main()
{
	constexpr char start_of_a = 'a';
	for (int i = 0; i < 26; ++i) 
		cout << char(start_of_a + i) << '\t' << i + start_of_a << "\n";

	cout << "Table of digits\n";
	constexpr char start_of_digit = '0';
	for (int i = 0; i < 10; ++i) 
		cout << char(start_of_digit + i) << '\t' << i + start_of_digit << "\n";
	return 0;
	
}