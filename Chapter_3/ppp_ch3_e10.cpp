/*
	Ch.3 Exercise 10
	Description: Write a program that takes an operation followed by two two operands.
	Output the result.
	Input: [Operator: string] [operand: int] [operand: int]
	Output; Resulting value of [operand] [operator] [operand]
	i.e. + 3 4.4 ==> 3 * 4.4 ==> 13.2 
*/
#include "../std_lib_facilities.h"

int main()
{
	string operation;
	double op1;
	double op2;
	
	cout << "Input what you want to calculuate in [operator] [operand] [operand] form: ";
	cin >> operation >> op1 >> op2;
		
	if (operation == "+")
		cout << op1 + op2;
	else if (operation == "-")
		cout << op1 - op2;
	else if (operation == "*")
		cout << op1 * op2;
	else if (operation == "/")
		cout << op1 / op2;
	
	cout << "\n";
	
	return 0;
}