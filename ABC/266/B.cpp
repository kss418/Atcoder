#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll; 
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	ll mod = 998244353;
	ll result = n % mod;
	if (result < 0) {
		result += mod;
	}

	cout << result;

	
	return 0;
}

