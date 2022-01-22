#include <vector>
#include <iostream>
#include <algorithm>

using std::sort;

void print(std::string label, std::vector<int> vi)
{
	std::cout << label << ": ";
	std::cout << "{";
	for (int i = 0; i < vi.size(); i++) {
		std::cout << vi[i];
		if (i != vi.size() - 1) //not the last element of vector
			std::cout << ", ";
	}
	std::cout << "}\n";
}

void get_stats_refer(std::vector<int>& vi, int& max_v, int& min_v, 
					 int& mean_v, int& median_v ) 
{
	int max_val = vi[0];
	int min_val = vi[0];
	int sum = 0;
	for (int i = 0; i < vi.size(); ++i) {
		if (max_val < vi[i]) 
			max_val = vi[i];
		if (min_val > vi[i])
			min_val = vi[i];
		sum += vi[i];
	}
	max_v = max_val;
	min_v = min_val;
	mean_v = sum / vi.size();
	sort(vi.begin(), vi.end());
	if (vi.size() % 2 == 0) 
		median_v = (vi[vi.size()/2-1] + vi[vi.size()/2-1]) / 2;
	else 
		median_v = vi[vi.size()/2];

}

int main()
{
	int max_v, min_v, mean_v, median_v;
	std::vector<int> vi = {-5, 1, 4, 3, 2, 55, 2};
	print("Vector", vi);
	get_stats_refer(vi, max_v, min_v, mean_v, median_v);
	std::cout << "Largest element in vector is: " << max_v << "\n";
	std::cout << "Smallest element in vector is: " << min_v << "\n";
	std::cout << "Median of vector is: " << median_v << "\n";
	std::cout << "Mean of vector is: " << mean_v << "\n";
	
}