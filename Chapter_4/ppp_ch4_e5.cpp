#include "../std_lib_facilities.h"

int main()
{
	double op1 {0.0}, op2 {0.0};
	char oper;
	
	//input will be [op1] [op2] [operator]
	//i,e, 5.4 3.1 +, which means 5.4 + 3.1
	while (cin >> op1 >> op2 >> oper) {
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
	
	
	return 0;
}