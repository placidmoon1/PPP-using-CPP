#include <iostream>
#include <string>
#include <vector>

//take a vector<string>, 
//return a vector<int> containing # chars in each string.
std::vector<int> count_char(const std::vector<std::string>& vs) 
{
	std::vector<int> v_char_count;
	for (std::string s: vs) {
		v_char_count.push_back(s.size());
	}
	return v_char_count;
}

//returns INDEX of occurrence
int max_len(const std::vector<int> &vi) 
{
	int max_ind = 0;
	int max_val = vi[0];
	
	for (int i = 0; i < vi.size(); ++i)
	{
		if (vi[i] > max_val) {
			max_val = vi[i];
			max_ind = i;
		}
	}

	return max_ind;
}

//returns INDEX of occurrence
int min_len(const std::vector<int> &vi) 
{
	int min_ind = 0;
	int min_val = vi[0];
	
	for (int i = 0; i < vi.size(); ++i)
	{
		if (vi[i] < min_val) {
			min_val = vi[i];
			min_ind = i;
		}
	}

	return min_ind;
}

//returns INDEX of occurrence
int greatest_lex(const std::vector<std::string> &vs) 
{
	int great_ind = 0;
	std::string great_val = vs[0];
	
	for (int i = 0; i < vs.size(); ++i)
	{
		if (vs[i] > great_val) {
			great_val = vs[i];
			great_ind = i;
		}
	}

	return great_ind;
}

//returns INDEX of occurrence
int least_lex(const std::vector<std::string> &vs) 
{
	int least_ind = 0;
	std::string least_val = vs[0];
	
	for (int i = 0; i < vs.size(); ++i)
	{
		if (vs[i] < least_val) {
			least_val = vs[i];
			least_ind = i;
		}
	}

	return least_ind;
}

int main()
{
	std::vector<std::string> vs = {"Hello", "My", "Nombre", "Is", "A", "KingKong^^"};
	std::vector<int> vi = count_char(vs);
	
	int ind_max_len = max_len(vi);
	int ind_min_len = min_len(vi);
	int ind_greatest_lex = greatest_lex(vs);
	int ind_leat_lex = least_lex(vs);
	
	std::cout << "Longest is " << vs[ind_max_len] << " with length " << vi[ind_max_len] << "\n" 
			  << "Shortest is " << vs[ind_min_len] << " with length " << vi[ind_min_len] << "\n" 
			  << "Lexicographically greatest is " << vs[ind_greatest_lex] 
			  << " at index " << ind_greatest_lex << "\n" 
			  << "Lexicographically smallest is " << vs[ind_leat_lex] 
			  << " at index " << ind_leat_lex << "\n"; 

	
}