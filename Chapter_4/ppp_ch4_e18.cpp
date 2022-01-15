#include "../std_lib_facilities.h"

int main()
{
	cout << "Solving quadratic equation\n";
	cout << "Input a, b, and c in ax^2 + bx + c = 0: ";
	
	double a, b, c;
	double x1, x2;
	cin >> a >> b >> c;
	
	//two values of quadratic eq.
	x1 = (-b - sqrt(b*b - 4 * a * c)) / (2 * a);
	x2 = (-b + sqrt(b*b - 4 * a * c)) / (2 * a);
	
	cout << "Two solutions are x = " << x1 << " and x = " << x2 << "\n";
}