#include "../std_lib_facilities.h"

int main()
{
	vector<int> values(7, 0);
	int num_rejected = 0;
	bool test = false;
	
	string user_s;
	int user_i;
	
	vector<string> acceptable = {"Monday", "Mon", "monday", "Tuesday", "Tues", "tuesday", 
								 "Wednesday", "Wed", "wednesday", "Thursday", "Thurs", "thursday",
								 "Friday", "Fri", "friday", "Saturday", "Sat", "saturday", 
								 "Sunday", "Sun", "sunday"};
	
	while (cin >> user_s >> user_i ) {
		bool accepted = false;
		for (int i = 0; i < acceptable.size(); i++) {
			if (acceptable[i] == user_s) {
				values[i/3] += user_i;
				accepted = true;
				if (test) {
					cout << acceptable[i] << " " << user_s << " accepted\n"; 
					cout << "New value: " << values[i/3] << "\n";
				}
				break;
			}
		}
		//if it was an illegal input, ignore & add number to num_rejected
		if (!accepted)
			num_rejected++;
	}
	
	for (int i = 0; i< 7; i++) {
		cout << acceptable[i*3] << ": " << values[i] << "\n";
	}	
	
	cout << "Number of rejected values: " << num_rejected << "\n";
	
	return 0;
}