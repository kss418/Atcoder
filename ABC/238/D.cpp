#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (m < 2 * n) {
			cout << "No\n";
			continue;
		}
		
		ll x = m - 2 * n;
		ll a = n, b = n;
		for (int i = 0; i < 62; i++) {
			a |= x & (1ll << i);
		}

		if (a + b == m) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	
	
	return 0;
}
