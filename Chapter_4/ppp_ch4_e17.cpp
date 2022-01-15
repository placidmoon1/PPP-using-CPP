#include "../std_lib_facilities.h"

int main() {
	cout << "Find min, max, and mode from sequence of strings\n";
	vector<string> v;
	
	for (string s; cin >> s; ) 
		v.push_back(s);
	sort(v);
	
	cout << "Max is: " << v[v.size() - 1] << "\n";
	cout << "Min is: " << v[0] << "\n";
	
	int cur_freq = 0, max_freq = 0;
	string looking_at = "", max_string = "";
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != looking_at) { //new combination
			if (max_freq < cur_freq) {
				max_freq = cur_freq;
				max_string = looking_at;
			}
			looking_at = v[i];
			cur_freq = 1;
		} else { //same combination, add 1 to cur_freq
			cur_freq++;
		}
	}	
	if (max_freq < cur_freq) { //new combination
		max_freq = cur_freq;
		max_string = looking_at;
	}
	cout << "Mode is: " << max_string << " with frequency " << max_freq << "\n";
}