#include "../std_lib_facilities.h"

int main(){
	int n; //number of fib numbers to calculuate
	int max_fib_count; // maximum positive integer fibs allowed
	vector<int> v_fib;
	
	v_fib.push_back(1);
	v_fib.push_back(1);
	
	cin >> n;
	if (n < 1) 
		error("You need to count at least 1 Fib Numbers!");
	
	if (n == 1)
		cout << "1\n";
	else if (n == 2)
		cout << "1 1\n";
	else {
		for (int i = 2; i < n; i++) {
			int next_fib = v_fib[i-1] + v_fib[i -2];
			if (next_fib < 0) { //integer overflow has happened
				max_fib_count = i;
				cout << "Max fib count is " << max_fib_count << "\n";
				error("Exceeded maximum fib count");
			}
			v_fib.push_back(next_fib);
		}
	}
	for (int i: v_fib){
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}