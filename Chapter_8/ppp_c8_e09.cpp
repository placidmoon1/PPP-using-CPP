#include <iostream>
#include <vector>
#include <stdexcept>

double final_index (const std::vector<double>& price, 
				   	const std::vector<double>& weight)
{
	if (price.size() != weight.size()) throw std::runtime_error("Price size doesn't match weight size");
	double final_value = 0.0;
	for (int i = 0; i < weight.size(); ++i) {
		final_value += price[i] * weight[i];
	}
	return final_value;
}

int main()
{
	const std::vector<double> price = {1.1, 2.2, 3.3, 4.4, 5.5};
	const std::vector<double> weight = {0.1, 0.2, 0.3, 0.0, 2.0};
	double index_val = final_index(price, weight);
	std::cout << "Index val is: " << index_val << "\n";
}