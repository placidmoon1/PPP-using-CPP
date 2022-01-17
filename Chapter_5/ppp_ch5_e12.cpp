#include "../std_lib_facilities.h"
vector<int> int_to_dig(int u_input) 
{
	vector<int> ans = {-1, -1, -1, -1}; 
	
	if (u_input < 0 || u_input >= 10000) {
		cout << "Wrong input, try again\n";
		return ans;
	} else {
		ans[3] = u_input % 10;
		u_input /= 10; 
		ans[2] = u_input % 10;
		u_input /= 10; 
		ans[1] = u_input % 10;
		u_input /= 10; 
		ans[0] = u_input % 10;
	}
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans.size(); j++) {
			if (ans[i] == ans[j] && i != j) {
				ans = {-1, -1, -1, -1};
				cout << "Duplicates not allowed. Try again\n";
				return ans;
			}
		}
	}
	
	return ans;	
}


int main()
{
	int u_input;
	vector<int> digits;
	vector<int> ans = {2, 3, 4, 5};
	
	cout << "Bulls and cows game.\n" 
		 << "Enter a 4 digit integer to start.\n"
		 << "* The integers must differ (1234 OK, 1122 NoNo)\n";
	
	//criteria 1) int, 2) 4-digit, 3) distinct digits
	while(true){
		vector<int> v_digits;
		int bulls = 0;
		int cows = 0; 
		
		cout << "Enter your input:\n";
		cin >> u_input;
		v_digits = int_to_dig(u_input);
		if (v_digits[0] == -1)
			continue; //error input
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