#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 510;
set <pair<int, int>> spell;
int x[MAX], y[MAX];

int gcd(int a, int b) {
	while (b != 0) {
		int mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}

			int xd = x[i] - x[j];
			int yd = y[i] - y[j];
			int g = gcd(abs(xd), abs(yd));
			xd /= g;
			yd /= g;

			spell.insert({ xd,yd });
		}
	}


	cout << spell.size();

	return 0;
}
