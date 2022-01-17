#include "../std_lib_facilities.h"

int main(){
	int sum_until = 0;
	vector<int> v;
	
	cout << "Please enter the number of values you want to sum:\n";
	cin >> sum_until;
	if (sum_until <= 0) {
		error("You cannot sum less than 1 numbers. Please enter n >1 ");
	}
	
	cout << "Please enter some integers (press '|' to stop):\n";
	for (int i = 0; cin >> i;) {
		v.push_back(i);
	}
	
	if (sum_until >= v.size()) {
		error("You cannot sum more than the numbers in the vector");
	}
	int sum = 0;
	cout << "The sum of the first " << sum_until << " numbers ( ";
	for (int i = 0; i < sum_until; i++) {
		cout << v[i] << " ";
		sum += v[i];
	}
	cout << ") is " << sum <<".\n";
	
	return 0;
}