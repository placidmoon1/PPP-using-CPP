#include "../std_lib_facilities.h"

//[e7] can now accept only! signle digit numbers.
//need to sanity check for it.

constexpr int errorCode = -1;
// if match, return respective int val; if no match, return -1. 
int singleDigitChecker(string user_input) 
{
	vector<string> digits_spelled_out = {"zero", "one", "two", "three", "four", 
								   	"five", "six", "seven", "eight", "nine"};
	vector<string> digit_verbatim = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	const int vectorSize = digit_verbatim.size();
	
	int output = errorCode;
	
	for (int i = 0; i< vectorSize; ++i) {
		if (user_input == digits_spelled_out[i]) {
			output = i;	
			break;
		} else if (user_input == digit_verbatim[i]) {
			output = i;	
			break;
		}
	}
	
	return output;
		
}
	
int main()
{
	string op1_str, op2_str;
	double op1 {0.0}, op2 {0.0};
	char oper;
	
	//input will be [op1] [op2] [operator]
	//i,e, 5.4 3.1 +, which means 5.4 + 3.1
	while (cin >> op1_str >> op2_str >> oper) {
		//sanity check op1, op2
		op1 = singleDigitChecker(op1_str);
		op2 = singleDigitChecker(op2_str);
		if (op1 == errorCode | op2 == errorCode) {
			cout << "Ops failed sanity check " << op1 << " " << op2 << " is invalid!\n";
			continue;
		}
		
		double result_val;
		string keyword;
		switch(oper){
			case '+':
				result_val = op1 + op2;
				keyword = "sum";
				break;
			case '-':
				result_val = op1 - op2;
				keyword = "difference";
				break;
			case '*':
				result_val = op1 * op2;
				keyword = "product";
				break;
			case '/':
				result_val = op1 / op2;
				keyword = "quotient";
				break;
		}
		
		cout << "The " << keyword << " of " << op1 << " and "
			 << op2 << " is " << result_val << ".\n";
	}
}