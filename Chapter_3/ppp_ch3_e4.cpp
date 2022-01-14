#include "../std_lib_facilities.h"

int main()
{
	//[e4] input two int values, store them in int, and print them
	int val1 {0}, val2 {0};
	cout << "Enter two ints, seperated by a space: ";
	cin >> val1 >> val2; 
	
	//determine smaller, larger, sum, difference, product, and ratio
	if (val1 < val2)
		cout << val1 << " is the smaller and " << val2 << " is the larger.\n";
	else
		cout << val2 << " is the smaller and " << val1 << " is the larger.\n";
	cout << "Sum of two values is: " << val1 + val2 << "\n";
	cout << "Difference of two values is (val1 - val2): " << val1 - val2 << "\n";
	cout << "Product of two values is: " << val1 * val2 << "\n";
	cout << "Ratio of two values is: " << val1 / val2 << "\n";
}