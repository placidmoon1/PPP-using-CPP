#include "../std_lib_facilities.h"

int main() 
{
	double cur_input = 0.0;
	double smallest = 0.0;
	double largest = 0.0;
	const string smallest_str = "the smallest so far\n";
	const string largest_str = "the largest so far\n";
	
	//initialize!
	cin >> cur_input;
	cout << "Entered: " << cur_input << "\n" << smallest_str << largest_str;
	smallest = cur_input;
	largest = cur_input;
	
	while (cin >> cur_input) {
		cout << "Entered: " << cur_input << '\n';
		if (cur_input > largest) {
			cout << largest_str;
			largest = cur_input;
		}
		else if (cur_input < smallest) {
			cout << smallest_str;
			smallest = cur_input;
		}
		
	} //end of while loop
}