#include "../std_lib_facilities.h"

void d_check(double a, double b, double c) 
{
	if (b*b - 4 * a * c < 0)
		error("d_check(): b^2-4ac < 0");
}

int main()
{
	//we can check if result is correct, by checking whether
	//b^2 - 4 * a * c >= 0. 
	double a, b, c;
	double x1, x2;
	
	cin >> a >> b >> c;
	d_check(a, b, c);
	
	x1 = (-b + sqrt(b*b - 4 * a *c)) / (2 * a);
	x2 = (-b -sqrt(b*b - 4 * a *c)) / (2 * a);
	
	cout << "Possible roots are: " << x1 << " and " << x2 << "\n";
	return 0;
}