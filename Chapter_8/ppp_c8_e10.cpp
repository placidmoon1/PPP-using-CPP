#include <iostream>
#include <vector>

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

int maxv(const std::vector<int>& vi) 
{
	int max_val = vi[0];
	for (int i = 0; i < vi.size(); ++i) {
		if (max_val < vi[i]) 
			max_val = vi[i];
	}
	return max_val;
}

int main()
{
	const std::vector<int> vi = {-5, 1, 4, 3, 2, 55, 2};
	print("Vector", vi);
	std::cout << "Largest element in vector is: " << maxv(vi) << "\n";
}