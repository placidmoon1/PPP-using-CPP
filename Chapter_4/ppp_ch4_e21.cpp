#include "../std_lib_facilities.h"

int findInVec(vector<string> vec, string el) 
{
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == el)
			return i;
	}
	return -1; 
}


int main()
{
	const string term_name = "NoName";
	
	vector<string> names;
	vector<int> scores;
	
	string user_name;
	int user_score;
	while (cin >> user_name >> user_score) {
		if (user_name == term_name)
			break;
		
		if (findInVec(names, user_name) != -1) {
			cout << "No duplicate names allowed. Terminating..\n";
			break;
		}
		
		names.push_back(user_name);
		scores.push_back(user_score);
	}
	
	for (int i = 0; i < names.size(); i++) {
		cout << "(" << names[i] << "," <<scores[i] << ")\n";
	}
	
	//[e20]
	cout << "For e21: Ener a score, and we will print corresponding names with that score. \n";
	bool matched = false;
	while (cin >> user_score) {
		for (int i = 0; i <scores.size(); i++) {
			if (scores[i] == user_score) {
				matched = true;
				cout << names[i] << "\n";
			}
		}
		
		if (matched == false) {
			cout << "score not found\n";
		}
		matched = false;
	}
	
	return 0;
}