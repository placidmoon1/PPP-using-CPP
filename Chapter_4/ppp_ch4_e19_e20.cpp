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
	cout << "For e20: Enter a name you want to find the corresponding score \n";
	while (cin >> user_name) {
		int user_index = findInVec(names, user_name);
		if (user_index != -1) {
			cout << "Score for " << user_name << " is " << scores[user_index] <<"\n";
		} else {
			cout << "name not found";
		}
	}
	
	return 0;
}