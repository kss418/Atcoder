#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	long long n;
	int k;
	cin >> n >> k;
	long long num = 1;
	for (int i = 1; i <= k; i++) {
		num *= 10;
		long long mod = n % num;
		if (mod >= num / 2) {
			n += num - mod;
		}
		else {
			n -= mod;
		}
	}
	
	cout << n;


	return 0;
}
