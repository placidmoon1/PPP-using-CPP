#include "../std_lib_facilities.h"

int main()
{
	string bleep = "BLEEP"; 
	vector<string> prohibited = {"ROM", "lockdown", "no-pass"};
	
	for (string word; cin >> word; ) 
	{
		//check if word input is in prohibited, by traversing the prohibited vector
		for (string prob_word: prohibited) {
			if (word == prob_word) { // if input match word in prohibited vector
				word = bleep; //substitute input to bleep
				break; //breaking the traversal of probhibited vector	
			} 
		}
		
		cout << word << "\n";
	}
	
	return 0;
}