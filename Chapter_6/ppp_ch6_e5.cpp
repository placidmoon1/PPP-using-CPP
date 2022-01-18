#include "../std_lib_facilities.h"

string sentence(string, char);
string article();
string noun();
string conjunction(string);

bool finisher = false;

char classify_input(string u_in)
{
	vector<string> nouns = {"birds", "fish", "c++"};
	vector<string> verbs = {"rules", "fly", "swim"};
	vector<string> conjunctions = {"and", "or", "but"};
	vector<string> articles = {"the"};
	
	bool end_of_sent = false; 
	string new_verb;
	if (u_in[u_in.size() - 1] == '.') { //end of sentence 
		end_of_sent = true;
		for (int i = 0; i < u_in.size() - 1; i++) { //copy all but period
			new_verb += u_in[i]; 
		}
	} else {
		new_verb = u_in;
	}
	
	//check if user input matches with provided terms 
	for (int i = 0; i < nouns.size(); i++) { //check whether there is a noun
		if (u_in == nouns[i]) return 'n';
	}
	for (int i = 0; i < verbs.size(); i++) {
		if (new_verb == verbs[i] && end_of_sent) return 'e';
		if (new_verb == verbs[i]) return 'v';
	}
	for (int i = 0; i < conjunctions.size(); i++) {
		if (u_in == conjunctions[i]) return 'c';
	}
	for (int i = 0; i < articles.size(); i++) {
		if (u_in == articles[i]) return 'a';
	}
	
	//if user input doesn't match any words, return '0'
	return '0';
}

class Token {
	public:
		char type;
		string val;
		Token (string caller) {
			string u_input;
			cin >> u_input;
			//cout << "Token() called from " << caller << "\n";
			//cout << "Token() received " << u_input << "\n";
			switch(classify_input(u_input)){
				case 'n':
					type = 'n';
					val = u_input;
					break;
				case 'v':
					type = 'v';
					val = u_input;
					break;
				case 'a':
					type = 'a';
					val = u_input;
				case 'c':
					type = 'c';
					val = u_input;
					break;
				case 'e':
					type = 'e';
					val = u_input;
					break;
				case '0':
				default:
					error("Not a valid input, doesn't exist in dictionary");
			}
		};
};


/**
 Sentence:
 	Noun Verb
	Article Noun Verb
	Sentence Conjugation Sentence 
*/
string sentence(string u_input, char type)
{
	string res = "";
	switch(type){
		case 'a':
			res += u_input + " ";
			cout << "Article: " << u_input << "\n";
			res += article();
			break;
		case 'n':
			res += u_input + " ";
			cout << "Noun: " << u_input << "\n";
			res += noun();
			break; 
		case 'v': case 'e':
			error("sentence(): Verb not allowed in start of sentence");
			break; //never reached
		default:
			error("sentence(): Token type unrecognizable");
			break; //never reached
	}
	return res;
}

string article() {
	string res = "";
	Token u_token = Token("article()"); //reads new input from cin
	switch(u_token.type){
		case 'n':
			res += u_token.val + " ";
			cout << "Noun: " << u_token.val << "\n";
			res += noun();
			break; 
		case 'v': case 'e': 
			cout << "article(): [Error]" << " token type: " << u_token.type 
				 <<  " token value: " <<  u_token.val <<"\n";
			error("article(): Token inappropriate after article");
			break; //never reached
		default:
			cout << "error " << u_token.type << " token type, " <<  u_token.val << "value\n";
			error("article(): Token type unrecognizable");
			break; //never reached
	}
	return res; 
}

string noun() {
	string res = "";
	Token u_token = Token("noun()"); //reads new input from cin
	switch(u_token.type){
		case 'v': 
			res += u_token.val + " ";
			cout << "Verb: " << u_token.val << "\n";
			return res;
		case 'e':
			res += u_token.val;
			cout << "Verb/End-of-sentence: " << u_token.val << "\n";
			finisher = true;
			return res;
		default:
			cout << "noun(): [Error]" << " token type: " << u_token.type 
				 <<  " token value: " <<  u_token.val <<"\n";
			error("noun(): Token type unrecognizable");
			break; //never reached
	}
	
}

string conjunction(string u_input){
	string res = "";
	res += u_input + " ";
	cout << "Conjunction: " << u_input << "\n";
	return res; 
}


int main()
{
	string res;
	char input_type;
	
	for (string u_input; cin >> u_input; ){
		input_type = classify_input(u_input);
		switch (input_type) {
			case 'n': case'a': 
				res += sentence(u_input, input_type); 
				break;
			case 'c':
				res += conjunction(u_input);
				break;
			default:
				error("At the start, only ");
		}
		if (finisher) {
			break;
		}
	}
	cout << "---------------------\n";
	cout << "Received:\n" << res <<"\n";
}