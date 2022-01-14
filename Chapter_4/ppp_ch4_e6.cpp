#include "../std_lib_facilities.h"

int main()
{
	vector<string> digit_in_char = {"zero", "one", "two", "three", "four", 
								   	"five", "six", "seven", "eight", "nine"};
	string user_input;
	string output;
	
	while (cin >> user_input) {
		bool matched = false;
		//two types of user input: 1) "zero", 2) "0"
		//So, check whether input is in digit_in_char. if so, find it.
		//else, convert user_input to int
		for (int i = 0; i< digit_in_char.size(); ++i) {
			if (user_input == digit_in_char[i]) {
				matched = true;
				output = to_string(i);	
				break;
			}
		}
		if (!matched)
			output = digit_in_char[stoi(user_input) - 1];
		
		cout << "Input " << user_input <<" spelled out as " << output <<"\n";
	}
}