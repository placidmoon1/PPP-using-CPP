#include <vector>
#include <iostream>
#include <string> 

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

int main()
{
	const std::string label = "myvec";
	const std::vector<int> vi = {1, 2, 3, 4, 5};
	print(label, vi);
}