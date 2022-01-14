#include "../std_lib_facilities.h"

int main() 
{
	//d2 write out, based on smaller,  or larger.
	//[d3] if equal, write that they are equal.
	int val1 = 0;
	int val2 = 0;
	while (cin >> val1 >> val2) {
		int small = 0;
		int large = 0;
		if (val1 == val2) {
			cout << "the numbers are equal\n";
		} else if (val1 < val2) {
			cout << "the smaller value is: " << val1 << "\n"
				 << "the larger value is: " << val2 << "\n"; 
		} else if (val1 > val2) {
			cout << "the smaller value is: " << val2 << "\n"
				 << "the larger value is: " << val1 << "\n"; 
		}		
	}
}