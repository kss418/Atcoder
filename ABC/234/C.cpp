#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll k;
	cin >> k;
	ll cnt = 1;
	ll c = 0;
	for (int i = 0; i <= 64; i++) {
		if (k >= cnt) {
			c++;
			cnt *= 2;
		}
		else {
			break;
		}
	}
	c--;

	for (ll i = c; i >= 0; i--) {
		ll cur = 1;
		for (int j = 1; j <= i; j++) {
			cur *= 2;
		}

		if (k & cur) {
			cout << 2;
		}
		else {
			cout << 0;
		}
	}
	



	return 0;
}

