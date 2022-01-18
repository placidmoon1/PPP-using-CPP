#include "../std_lib_facilities.h"

vector<char> string_to_char(string u_input) 
{
	vector<char> ans = {'0', '0', '0', '0'}; 
	
	for (int i = 0; i < u_input.size(); i++) {
		ans[i] = u_input[i];
	}
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans.size(); j++) {
			if (ans[i] == ans[j] && i != j) {
				ans = {'0', '0', '0', '0'};
				cout << "Duplicates not allowed. Try again\n";
				return ans;
			}
		}
	}
	
	return ans;	
}


int main()
{
	string u_input;
	vector<char> digits;
	vector<char> ans = {'a', 'b', 'c', 'd'};
	
	cout << "Bulls and cows game.\n" 
		 << "Enter a 4 char string to start.\n"
		 << "* The chars must differ (abcd OK, aabb NoNo)\n";
	
	//criteria 1) int, 2) 4-digit, 3) distinct digits
	while(true){
		vector<char> v_digits;
		int bulls = 0;
		int cows = 0; 
		
		cout << "Enter your input: ";
		cin >> u_input;
		
		//check for right size
		if (u_input.size() != 4) {
			cout << "Input a 4 char string.\n"
				 << "You inputted " << u_input.size() << " chars\n";
			continue; //ask for new input 
		}
		
		//check for duplicates
		v_digits = string_to_char(u_input);
		if (v_digits[0] == '0' && v_digits[1] == '0')
			continue; //occurence of duplicates
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (ans[i] == v_digits[j] && i == j)
					bulls++;
				else if (ans[i] == v_digits[j] && i != j)
					cows++;
			}
		}
		if (bulls == 4){
			cout << "Congrats, you won!\n";
			break;
		} else {
			cout << bulls << " bulls and " << cows << " cows\n"; 
		}
	} 

}