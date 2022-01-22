#include <vector>
#include <iostream>
#include <string> 
#include <stdexcept> //defines runtime_error

void print(std::string label, std::vector<int> vi)
{
	std::cout << label << ": ";
	std::cout << "{";
	for (int i = 0; i < vi.size(); i++) {
		std::cout << vi[i];
		if (i != vi.size() - 1) //not the last element of vector
			std::cout << ", ";
	}
	std::cout << "}\n";
}

void fibonacci(int x, int y, std::vector<int>& v, int n)
{
	if (n <= 0)
		throw std::runtime_error("n cannot be 0 or smaller");
	else if (n == 1) {
		v.push_back(x);
		return;
	} else {
		v.push_back(x);
		v.push_back(y);
		for (int i = 2; i < n; ++i) {
			int next_fib = v[i-1] + v[i-2];
			if (next_fib < v[i-1]) { // overflow happened. 
				std::cout << "limit of maximum numbers possible for int is " << i << "\n";
				return;
			}
			v.push_back(next_fib);
		}
	}

}

int main()
{
	const int fib_term1 = 1;
	const int fib_term2 = 1;
	const int fib_until = 1000;
	const std::string label = "myvec";
	std::vector<int> vi;
		
	std::cout << "Approximating limit of fib numbers in int\n";
	
	fibonacci(fib_term1, fib_term2, vi, fib_until);
	//print(label, vi);
}