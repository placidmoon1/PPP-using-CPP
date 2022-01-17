#include "../std_lib_facilities.h"

int main()
{
	double pi = 3.14;
	
	int int_correct = narrow_cast<int>(2);
	int int_error = narrow_cast<int>(pi);
	char char_error = narrow_cast<char>(334234);
	
	return 0;
}