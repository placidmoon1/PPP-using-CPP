#include "../std_lib_facilities.h"

int main()
{
	int number_of_words = 0;
	string previous = " ";
	string current;
	while (cin >> current) {
		++number_of_words;
		if (previous == current) 
			cout << "Word number " << number_of_words 
				 << " repeated word: " << current << "\n";
		previous = current; // updates the current word to previous 
	}
}