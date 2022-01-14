#include "../std_lib_facilities.h"

int main() 
{
	int int_grain = 1;
	double double_grain = 1.0;
	
	//max squares till overflow.
	int int_limit = 0;
	double double_limit = 0.0;

	for (int i = 1; i <= 64 ; i++) {
		cout << "[int] With " << i << " squares, earned " << int_grain << " grains!\n";
		cout << "[double] With " << i << " squares, earned " << double_grain << " grains!\n";
		
		int_grain *= 2;
		double_grain *= 2;
		
		//first time grain counted in int becomes neg.
		if (int_limit == 0 && int_grain < 0)
			int_limit = i - 1;
			
		//first time grain counted in double becomes neg.
		if (double_limit == 0 && double_grain < 0)
			double_limit = i - 1;
		
	}
	
	cout << "Limit of int is " << int_limit << " squares.\n";
	cout << "Limit of double is " << double_limit << " squares.\n";
}