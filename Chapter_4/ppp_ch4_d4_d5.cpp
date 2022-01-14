#include "../std_lib_facilities.h"

int main() 
{
	//[d2] write out, based on smaller, or larger.
	//[d3] if equal, write that they are equal.
	//[d4] change int to double
	double val1 = 0;
	double val2 = 0;
	constexpr double max_diff = 1.0/100;
	
	while (cin >> val1 >> val2) {
		if (val1 == val2) {
			cout << "the numbers are equal\n";
		} else { //if two numbers are not equal 
			if (val1 < val2) {
				cout << "the smaller value is: " << val1 << "\n"
					 << "the larger value is: " << val2 << "\n"; 
			} else if (val1 > val2) {
				cout << "the smaller value is: " << val2 << "\n"
					 << "the larger value is: " << val1 << "\n"; 
			}	
			//[d5] if two numbers differ by less than 0.01, 
			// 	   write "the numbers are almost equal"
			if (val1 - val2 < max_diff && val1 - val2 > 0 ||
				val2 - val1 < max_diff && val2 - val1 > 0) 
				cout << "The numbers are almost equal\n";
		}
		
		
	} //end of while loop
}