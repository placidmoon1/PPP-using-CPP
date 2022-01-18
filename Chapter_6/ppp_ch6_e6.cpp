#include "../std_lib_facilities.h"

char classify_input(string u_in)
{
	vector<string> nouns = {"birds", "fish", "c++"};
	vector<string> verbs = {"rules", "fly", "swim"};
	vector<string> conjunctions = {"and", "or", "but"};
	vector<string> articles = {"the"};
	vector<string> punctuations = {"."};
	
	
	//check if user input matches with provided terms 
	for (int i = 0; i < nouns.size(); i++) { //check whether there is a noun
		if (u_in == nouns[i]) return 'n';
	}
	for (int i = 0; i < verbs.size(); i++) {
		if (u_in == verbs[i]) return 'v';
	}
	for (int i = 0; i < conjunctions.size(); i++) {
		if (u_in == conjunctions[i]) return 'c';
	}
	for (int i = 0; i < articles.size(); i++) {
		if (u_in == articles[i]) return 'a';
	}
	for (int i = 0; i < punctuations.size(); i++) {
		if (u_in == punctuations[i]) return 'p';
	}
	
	//if user input doesn't match any words, return '0'
	return '0';
}

int main()
{
	string ok = "OK\n";
	string err_str = "not OK\n";
	bool is_ok = true;
	bool new_sent= true; //if it is a new sentence
	char prev = 'c'; //type of previous input
	for (string u_input; cin >> u_input; ) {
		switch (classify_input(u_input)) {
			case 'a':
				if (new_sent) 
					new_sent = false;
				else if (prev != 'c') //!new_sent && prev != 'c'
					is_ok = false;
				prev = 'a';
				break;
			case 'n':
				if (new_sent) 
					new_sent = false;
				else if (prev != 'a') //!new_sent && prev != 'a'
					is_ok = false;
				prev = 'n';
				break;
			case 'v':
				if (prev != 'n')
					is_ok = false;
				prev = 'v';
				break;
			case 'c':
				if (prev != 'v')
					is_ok = false;
				prev = 'c';
				new_sent = true;
				break;
			case 'p':
				if (prev != 'v')
					is_ok = false;
				if (is_ok) 
					cout << ok;
				else 
					cout << err_str;
				//reset after every sentence 
				new_sent = true;
				is_ok = true;
				break;
			default:
				error("main(): unrecognizable case");
		}
	}
}