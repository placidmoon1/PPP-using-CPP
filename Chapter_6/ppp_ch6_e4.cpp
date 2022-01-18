#include "../std_lib_facilities.h"

class Name_value {
	public:
		string name;
		int score;
		Name_value (string u_name, int u_score): name {u_name}, score {u_score} {};
};

int findInVec(vector<Name_value> users, string el) 
{
	for (int i = 0; i < users.size(); i++){
		if (users[i].name == el)
			return i;
	}
	return -1; 
}


int main()
{
	const string term_name = "NoName";
	
	vector<Name_value> users;
	
	string user_name;
	int user_score;
	while (cin >> user_name >> user_score) {
		if (user_name == term_name)
			break;
		
		if (findInVec(users, user_name) != -1) {
			cout << "No duplicate names allowed. Terminating..\n";
			break;
		}
		
		users.push_back(Name_value{user_name, user_score});
	}
	
	for (int i = 0; i < users.size(); i++) {
		cout << "(" << users[i].name << "," << users[i].score << ")\n";
	}
	
	//[e20]
	cout << "For e20: Enter a name you want to find the corresponding score \n";
	while (cin >> user_name) {
		int user_index = findInVec(users, user_name);
		if (user_index != -1) {
			cout << "Score for " << user_name << " is " << users[user_index].score <<"\n";
		} else {
			cout << "name not found";
		}
	}
	
	return 0;
}