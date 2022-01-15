 #include "../std_lib_facilities.h"

vector<int> prime_finder(int start, int end)
{
	vector<int> all_primes;
	const int up_to = sqrt(end);
	for (int i = start; i <= end; i++) {
		if (i < 2)
			continue;
		else if (i == 2)
			all_primes.push_back(2);
		else {
			bool divisible = false;
			for (int j = 0; j< all_primes.size(); j++) {
				if (i % all_primes[j] == 0) {
					divisible = true; //divisible, not a prime
					break;
				} 
			}
			if (!divisible) 
				all_primes.push_back(i);
		}
		
	}
	return all_primes;
}

int main()
{
	constexpr int minR = 1;
	int maxR = 100;
	cout << "Finding all prime numbers between 1 and n\n";
	cout << "Please input up to where you want to find: ";
	cin >> maxR;
	vector<int> primes = prime_finder(minR, maxR);
	for (int prime : primes) 
		cout << prime << "\n";
	
	return 0;
}