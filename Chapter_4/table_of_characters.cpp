#include "../std_lib_facilities.h"

int main()
{
	int i = 0;
	constexpr char start_of_a = 97;
	while (i < 26) 
	{
		cout << char(start_of_a + i) << '\t' << i + start_of_a << "\n";
		++i;
	}
	
	return 0;
}