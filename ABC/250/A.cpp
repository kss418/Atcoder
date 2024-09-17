#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> y >> x;
	cin >> n >> m;
	int result = 4;
	if (n == 1) {
		result--;
	}

	if (n == y) {
		result--;
	}

	if (m == 1) {
		result--;
	}

	if (m == x) {
		result--;
	}

	cout << result;

	return 0;
}
