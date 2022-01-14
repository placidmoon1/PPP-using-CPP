#include "../std_lib_facilities.h"

int main()
{
	int min = 1;
	int max = 100;
	char user_input = ' ';
	int total_count = 0;
	
	cout << "Number guessing game!\n"
		 << "Think a number between 1 ~100\n";
	
	
	while(min != max) {
		total_count++;
		int midpoint = (max + min) / 2;
		int halfdiff = (max-min) / 2;
		cout << "Cur range: " << min << " ~ " << max << "\n"
			 << "Is your number less than " << midpoint << "?\n"
			 << "Input y if yes, n if no: ";
		cin >> user_input;
		
		if (halfdiff == 0) 
			halfdiff = 1;
		
		switch(user_input) {
			case 'y':
				max = max - halfdiff - 1;
				break;
			case 'n':
				min += halfdiff;
				break;
		}
	}
	cout << "Your number is " << max <<"?\n";
	cout << "It took " << total_count <<" questions to find your number!\n";
}