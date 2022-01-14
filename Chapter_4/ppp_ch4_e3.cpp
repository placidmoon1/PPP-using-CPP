#include "../std_lib_facilities.h"

int main() 
{
	vector<double> city_dist_vec;
	vector<double> dist_between_vec; //size() is 1 smaller than city_dist_vec
	double user_input = 0.0;
	double dist_total = 0.0;
	double sum_dist_between = 0.0;
	
	
	while (cin >> user_input) {
		city_dist_vec.push_back(user_input);
		dist_total += user_input;
	}
	
	for (int i = 1; i < city_dist_vec.size(); ++i) {
		double dist_between = city_dist_vec[i] - city_dist_vec[i-1];
		if (dist_between < 0) 
			dist_between = -dist_between;
		
		dist_between_vec.push_back(dist_between);
		sum_dist_between += dist_between;
	}
	
	sort(dist_between_vec);
	cout << "Total distance: " << dist_total << "\n" 
		 << "Smallest distance between cities: " << dist_between_vec[0] << "\n" 
		 << "Largest  distance between cities: " << dist_between_vec[dist_between_vec.size() - 1]<< "\n" 
		 << "Mean distance between cities: " << sum_dist_between / dist_between_vec.size() << "\n";
	
	
	return 0;
}