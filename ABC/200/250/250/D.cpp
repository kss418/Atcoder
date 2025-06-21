#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 1010101;
int prime[MAX];
vector <ll> p;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	memset(prime, -1, sizeof(prime));
	int r = pow(n, 1.0 / 3);
	int cnt = 0;
	int result = 0;

	for (int i = 2; i <= r; i++) {
		if (prime[i] == -1) {
			prime[i] = 1;
			p.push_back(i);
		}
		else {
			continue;
		}

		for (int j = 2 * i; j <= r; j += i) {
			prime[j] = 0;
		}
	}
	sort(p.begin(), p.end());

	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < i; j++) {
			ll cur = p[i] * p[i] * p[i] * p[j];
			if (cur <= n) {
				result++;
			}
			else {
				break;
			}
		}
	}

	cout << result;
	

	return 0;
}
