#include "../std_lib_facilities.h"

int main()
{
	bool test = false; 
	int blank; //how many -1s should be in digits. 
	string u_input;
	vector<int> digits = {-1, -1, -1, -1}; //-1 indicates not applciable
	constexpr int max_size = 4;
	constexpr int min_size = 1;
	
	cin >> u_input;
	//u_input should be 1 ~ 4 chars
	if (u_input.size() > max_size || u_input.size() < min_size) 
		error("wrong input size");
	blank = max_size - u_input.size();
	
	//convert u_input string to digits
	for (int i = 0; i < u_input.size(); i++) {
		digits[i+blank] = u_input[i] - '0'; 
	}
	
	if (test) {
		cout << blank << " blanks\n";
		for (int i = 0; i < digits.size(); i++) 
			cout << "Digit " << i << ": " << digits[i] << "\n";
	}
	
	//explain the digits in text
	for (int i = blank; i < digits.size(); i++) {
		if (i == 0)
			cout << digits[i] << " thousand(s) ";
		else if (i == 1)
			cout << digits[i] << " hundred(s) ";
		else if (i == 2)
			cout << digits[i] << " ten(s) and ";
		else if (i == 3)
			cout << digits[i] << " one(s).\n";
	}
	
}