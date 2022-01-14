#include "../std_lib_facilities.h"

int main()
{
	cout << "Please enter your first name: ";
	string first_name = "??";
	cin >> first_name; 
	//prompt to input first_name of recipient
	cout << "Hello, " << first_name << "\n";
	cout << "Enter the name of the person you want to write to: ";
	cin >> first_name;
	
	//output "Dear [first_name],"
	cout << "Dear " << first_name << ",\n";
	
	//[ppp_c3_d2] add some introductory lines to the letter
	cout << "	How are you? I am fine :)\n" 
		 << "Currently working as a KATUSA TT;;\n";
	
	//[ppp_c3_d3] Prompt the user for name of another friend, 
	// and output accordingly
	string friend_name = "";
	cout << "[Prompt] Enter a friend's name: ";
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";
	
	//[ppp_c3_d4] Ask for friend's sex, and output accordingly
	char friend_sex = 0;
	cout << "[Prompt] Enter the friend's sex; m if male, f if female: ";
	cin >> friend_sex;
	if (friend_sex == 'm') 
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	else if (friend_sex = 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";
	
	//[ppp_c3_d5] Prompt for age. If age not in 1 ~ 109 range, call simple_error()
	int age = 0;
	cout << "[Prompt] Enter your age: ";
	cin >> age;
	if (age <= 0 || age >= 110) 
		simple_error("you're kidding!");
	else
		cout << "I heard you just had a birthday and you are " << age << " years old.\n";
	
	//[ppp_c3_d6] Add appropriate responses for the recipient's age
	if (age < 12) 
		cout << "Next year you will be " << age + 1 << ".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age > 70) 
		cout << "I hope you are enjoying retirement.\n";
	
	//[ppp_c3_d7] An end-of-letter remark
	cout << "Yours sincerely,\n\n\nGu Hong (Kevin) Min.\n";
	
 
}