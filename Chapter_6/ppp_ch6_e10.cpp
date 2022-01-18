#include "../std_lib_facilities.h"

int factorial(int num)
{
	int ans = 1;
	for (int i = 1; i <= num; i++) {
		ans *= i;
	}
	return ans;
}

int main()
{
	int n1, n2;
	char u_choice; 
	
	cout << "Enter two integers: ";
	cin >> n1 >> n2;
	if (n1 < 0 || n2 < 0) error ("cannot enter negative numbers");
	if (n1 < n2) error ("first number has to be larger than the seocnd");
	
	cout << "To calculate permutation, enter char p, to calculate combinations, enter c: ";
	cin >> u_choice;
	switch(u_choice) {
		case 'p':
			cout << factorial(n1) / factorial(n1 - n2) << "\n";
			break;
		case 'c':
			cout << factorial(n1) / factorial(n1 - n2) / factorial(n2) << "\n";
			break;
		default:
			error("Wrong choice selected. Only [p]ermuations and [c]ombinations allowed");
	}
}