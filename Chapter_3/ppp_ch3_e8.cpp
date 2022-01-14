/*
	PPP Ch.3, Exercise 8
	Write a program that tests whether the integer input is odd or even.
	Input: integer
	Output: Stand-alone statement saying whether the input was odd or even
*/
#include "../std_lib_facilities.h"
int main(){
	int int_input {0};
	string oddness; // stores whether the input is odd or even
	
	cout << "Enter an integer: ";
	cin >> int_input;
	
	if (int_input % 2 == 0) 
		oddness = "an even";
	else
		oddness = "a odd";
	
	cout << "The value " << int_input << " is " + oddness + " number.\n";
		
	return 0;
}