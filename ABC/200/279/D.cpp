#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 401010;
ll a, b;
bool deter(ll num) {
	if (a / sqrt(num) - a / sqrt(num + 1) >= b) {
		return 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b;

	ll st = 0, en = a;
	while (st < en) {
		ll mid = (st + en + 1) / 2;

		if (deter(mid)) {
			st = mid;
		}
		else {
			en = mid - 1;
		}
	}

	long double result = b * st + a / sqrt(st + 1);
	cout.precision(11);
	cout << result;

	return 0;
}
