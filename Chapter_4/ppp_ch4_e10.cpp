#include "../std_lib_facilities.h"

void game_result(char computer_choice, char user_choice) 
{
	//when results are same, result is 0 (tie)

	if (computer_choice - user_choice == 0) 
		cout << "You are tied. Computer chose: " << computer_choice << "\n";
	else if (computer_choice == 'r' && user_choice == 's'
			 || computer_choice == 's' && user_choice == 'p'
			 || computer_choice == 'p' && user_choice == 'r')
		cout << "You lose. Computer chose: " << computer_choice << "\n";
	else
		cout << "You win. Computer chose: " << computer_choice << "\n";
}

int main()
{
	vector<char> values = {'r', 's', 'p'};
	char user_input;
	int game_num = 0; // what iteration of the game we are in
	
	cout << "Rock, Scissors, Papers Game!\n";
	cout << "----------------------------\n";
	cout << "Please input your value.\n" 
		 << "Available values are r, s, and p \n"
		 << "for rock, scissors, and paper, respectuflly: \n";
	while (cin >> user_input) {
		char computer_choice = game_num % 3; //
		switch (user_input) {
			case 'r':
			case 's':
			case 'p':
				game_result(values[computer_choice], user_input);
				break;
			default:
				cout << "Wrong value, please input r, s, or c.\n";
				break;
		}
		cout << "Please input your value: \n" ;
		game_num++;
	}
}