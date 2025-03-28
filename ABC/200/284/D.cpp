#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 110;
vector <int> arr[MAX];
vector <int> result;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		ll mod;
		ll a, b;
		cin >> n;
		
		for (ll i = 2; i <= n; i++) {
			if (n % i == 0) {
				mod = i;
				break;
			}
		}

		n /= mod;
		if (n % mod == 0) {
			a = mod;
			b = n / mod;
		}
		else {
			b = mod;
			a = sqrt(n);
		}

		cout << a << " " << b << "\n";
	}

	return 0;
}
