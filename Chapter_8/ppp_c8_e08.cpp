#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
	int input_limit;
	const std::string delimiter = "|";
	const std::string label1 = "swap1";
	const std::string label2 = "swap2";
	std::vector<std::string> name;
	std::vector<double> age;
	
	//for user input of 5 names and 5 ages 
	std::string u_in;
	int u_in_int;
	
	std::cout << "Enter an arbirary number of names, and end with a singleton " << delimiter << "\n";
	
	for (; std::cin >> u_in ; ) {
		if (u_in != delimiter) 
			name.push_back(u_in);
		else 
			break;
	}
	
	
	input_limit = name.size(); 
	std::cout << "Enter the age for the input of " <<  input_limit << " people: ";
	for (int i = 0; i < input_limit; ++i) {
		std::cin >> u_in_int;
		age.push_back(u_in_int);
	}
	 
	//print pairs
	for (int i = 0; i < name.size(); ++i) {
		std::cout << "(" << name[i] << "," << age[i] << ")\n";
	}
	
	std::vector<std::string> name_copy = name;
	std::sort(name.begin(), name.end());
	
	std::cout << "Sorted pairs:\n";
	//print out sorted pairs. 
	//only name is sorted, and index mismatches with current age as of now.
	for (int i = 0; i < name.size(); ++i) {
		for (int j = 0; j < name_copy.size(); j++) { //find index in unsorted name vector 
			if (name[i] == name_copy[j]) {
				std::cout << "(" << name[i] << "," << age[j] << ")\n"; 
				break;
			}
		}
	}
		
	
}