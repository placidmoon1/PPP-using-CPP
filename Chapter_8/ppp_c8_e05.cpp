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

std::vector<int> swap1 (const std::vector<int>& vi) 
{
	std::vector<int> new_vi;
	for (int i = vi.size() -1 ; i >= 0; --i) {
		new_vi.push_back(vi[i]);
	}
	return new_vi;
}

void swap2(std::vector<int>& vi)
{
	for (int i = 0; i < vi.size() / 2; i++) {
		int temp = vi[vi.size() - 1 - i];
		vi[vi.size() - 1 - i] = vi[i];
		vi[i] = temp;
	}
}

int main() {
	const std::string label1 = "swap1";
	const std::string label2 = "swap2";
	std::vector<int> vi_to_swap = {1, 2, 3, 4, 5, 6, 7};
	std::vector<int> res_vec = swap1(vi_to_swap);
	
	print("Original vector", vi_to_swap);
	print(label1, res_vec);
	swap2(vi_to_swap);
	print(label2, vi_to_swap);	
	
}