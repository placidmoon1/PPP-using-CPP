#include "../std_lib_facilities.h"

int findInVec(vector<int> vec, int el) 
{
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == el)
			return i;
	}
	return -1; 
}

int main()
{
	vector<int> input_int;
	vector<int> input_int_freq;
	int user_input;
	
	cout << "Finding mode from sequence of integers\n";
	
	while (cin >> user_input) {
		int index_in_vec = findInVec(input_int, user_input);
		if (index_in_vec == -1) { //not found
			input_int.push_back(user_input);
			input_int_freq.push_back(1);
		} else {
			input_int_freq[index_in_vec]++;
		}
	}
	
	int max_freq = 0; //this is checked everytime new value is inputted. j
	int max_freq_index = 0;
	for (int i = 0; i < input_int_freq.size(); i++) {
		if (input_int_freq[i] > max_freq) {
			max_freq = input_int_freq[i];
			max_freq_index = i;
		}
	}
	
	cout << "Mode is " << input_int[max_freq_index] << " with frequency " << max_freq << "\n";
	return 0;
}