#include <iostream>
#include <vector>

void print_until_s(const std::vector<std::string>& v, std::string quit)
{
	for (std::string s : v) {
		if (s == quit) return;
		std::cout << s << '\n';
	}
}

void print_until_ss(const std::vector<std::string>& v, std::string quit)
{
	bool flag_once = false; 
	for (std::string s : v) {
		if (s == quit && !flag_once) 
			flag_once = true;
		else if (s==quit && flag_once) 
			return;
		std::cout << s << '\n';
	}
}

int main()
{
	const std::string quit = "Is";
	const std::vector<std::string> vs = {"Hello", "World", "My", "Name", "Is", "Kevin", ".",
										 "Is", "He", "Ok?"};
	print_until_s(vs, quit);
	std::cout << "---------------------------------------\n";
	print_until_ss(vs, quit);

}