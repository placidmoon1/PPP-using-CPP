#include "../std_lib_facilities.h"

int min(int a, int b);
int max(int a, int b);

int main()
{
	int val1 {0}, val2 {0}, val3 {0};
	cout << "Enter three integer values, seperated by a space: ";
	cin >> val1 >> val2 >> val3;
	
	int minV, midV, maxV;
	minV = min(min(val1, val2), val3);
	maxV = max(max(val1, val2), val3);
	midV = val1 + val2 + val3 - minV - maxV;
	
	cout << minV << ", " << midV << ", " << maxV << "\n";
	
	return 0;
}

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int max(int a, int b) {
	if (a > b) 
		return a;
	else 
		return b;
}