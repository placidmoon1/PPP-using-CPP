#include <iostream>
#include <vector>
#include <string>

void print(std::string label, std::vector<std::string> vi)
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

std::vector<std::string> swap1 (const std::vector<std::string>& vi) 
{
	std::vector<std::string> new_vi;
	for (int i = vi.size() -1 ; i >= 0; --i) {
		new_vi.push_back(vi[i]);
	}
	return new_vi;
}

void swap2(std::vector<std::string>& vi)
{
	for (int i = 0; i < vi.size() / 2; i++) {
		std::string temp = vi[vi.size() - 1 - i];
		vi[vi.size() - 1 - i] = vi[i];
		vi[i] = temp;
	}
}

int main() {
	const std::string label1 = "swap1";
	const std::string label2 = "swap2";
	std::vector<std::string> vs_to_swap = {"a", "cat", "lives", "in", "Camp", "Humphreys"};
	std::vector<std::string> res_vec = swap1(vs_to_swap);
	
	print("Original vector", vs_to_swap);
	print(label1, res_vec);
	swap2(vs_to_swap);
	print(label2, vs_to_swap);	
	
}