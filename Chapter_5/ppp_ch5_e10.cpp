#include "../std_lib_facilities.h"

int main(){
	int sum_until = 0;
	vector<double> v;
	vector<double> v_diff;
	
	cout << "Please enter the number of values you want to sum:\n";
	cin >> sum_until;
	if (sum_until <= 0) {
		error("You cannot sum less than 1 numbers. Please enter n >1 ");
	}
	
	cout << "Please enter some doubles (press '|' to stop):\n";
	for (double i = 0; cin >> i;) {
		v.push_back(i);
	}
	
	if (sum_until >= v.size()) {
		error("You cannot sum more than the numbers in the vector");
	}
	double sum = 0;
	cout << "The sum of the first " << sum_until << " numbers ( ";
	for (int i = 0; i < sum_until; i++) {
		cout << v[i] << " ";
		sum += v[i];
	}
	cout << ") is " << sum <<".\n";
	
	cout << "Vector of differences:\n";
	for (int i = 0; i < v.size(); i++) {
		if (i != 0)
			v_diff.push_back(v[i] - v[i-1]);
	}
	for (int i = 0; i < v_diff.size(); i++) {
		cout << v_diff[i] << " ";
	}
	cout << "\n";
	return 0;
}