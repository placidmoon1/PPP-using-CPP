#include "../std_lib_facilities.h"

int main() 
{
	int cur_iter = 1;
	constexpr int magic1 = 1000;
	constexpr int magic2 = 1000000;
	constexpr int magic3 = 1000000000;
	vector<int> magic_over = {0, 0, 0};
	
	for (int i = 1; ; i *= 2) {
		cout << "With " << cur_iter << " squares, earned " << i << " grains!\n";
		
		if (i > magic1 && magic_over[0] == 0) {
			cout << "[Alert] Passed " << magic1 << " grains with " << cur_iter << " squares!\n";
			magic_over[0] = 1;
		} else if (i > magic2 && magic_over[1] == 0) {
			cout << "[Alert] Passed " << magic2 << " grains with " << cur_iter << " squares!\n";
			magic_over[1] = 1;
		} else if (i > magic3 && magic_over[2] == 0) {
			cout << "[Alert] Passed " << magic3 << " grains with " << cur_iter << " squares!\n";
			magic_over[2] = 1;
			break;
		}
		++cur_iter;
	}
}