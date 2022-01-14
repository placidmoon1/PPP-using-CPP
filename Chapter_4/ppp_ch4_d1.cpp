#include "../std_lib_facilities.h"

int main() 
{
	//reads in two ints, and print
	//terminate when terminating | is entered. 
	int val1 = 0;
	int val2 = 0;
	while (cin >> val1 >> val2) {
		cout << val1 << " " << val2 << "\n";
	}
}