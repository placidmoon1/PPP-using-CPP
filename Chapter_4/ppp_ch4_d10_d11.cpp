#include "../std_lib_facilities.h"

/**
	Converts raw unit values into meter values.
*/
double converter(double raw_val, string unit) 
{
	constexpr double cm_to_m = 0.01; //1cm = 0.01m
	constexpr double in_to_m = 0.0254; //1in = 0.0254m
	constexpr double ft_to_m = 0.0254 * 12; //1ft = 0.0254*12=0.3048m
	double converted_val = -1.0;
	
	if (unit == "cm") 
		converted_val = raw_val * cm_to_m;
	else if (unit == "ft")
		converted_val = raw_val * ft_to_m;
	else if (unit == "in")
		converted_val = raw_val * in_to_m;
	else if (unit == "m")
		converted_val = raw_val;
	else
		cout << "converter() error: unit " << unit << " isn't valid\n";
	
	return converted_val;
}

//[d9] keep sum, num_values, largest, smallest, and print stats when loop end. 
int main() 
{
	double cur_input = 0.0;
	string cur_unit = " ";
	
	double smallest = 0.0;
	double largest = 0.0;
	bool start = false;
	
	double sum = 0.0;
	int num_values = 0;
	vector<double> input_values;
	
	const string smallest_str = "the smallest so far\n";
	const string largest_str = "the largest so far\n";
	
	//initialize!
	
	while (cin >> cur_input >> cur_unit) {
		cout << "Entered: " << cur_input << cur_unit << '\n';
		cur_input = converter(cur_input, cur_unit);
		
		if (cur_input == -1) //if it is invalid input
			continue; 
		
		cout << "Converted to: " << cur_input << "m\n";
		sum += cur_input;
		num_values++;
		input_values.push_back(cur_input);
		
		if (!start) {
			smallest = cur_input;
			largest = cur_input;
			cout << smallest_str << largest_str;
			start = true;
			continue;
		}
		
		if (cur_input > largest) {
			cout << largest_str;
			largest = cur_input;
		}
		else if (cur_input < smallest) {
			cout << smallest_str;
			smallest = cur_input;
		}
		
	} //end of while loop
	cout << "--------------------------------\n"
		 << "Stats:\n"
		 << "Smallest: " << smallest << "\n"
		 << "Largest: " << largest << "\n"
		 << "Sum: " << sum << "\n"
		 << "num_values: " << num_values << "\n"
		 << "--------------------------------\n";
	
	cout << "Values:\n";
	
	//[d11] sort the input_values vector
	sort(input_values);
	
	//[d10] print input_values vector
	for (double val : input_values)
		cout << val << " ";
	cout << "\n";
	
	cout << "--------------------------------\n";

	
}