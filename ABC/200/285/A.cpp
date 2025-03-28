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


const int MAX = 5010;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	if (n * 2 == m || n * 2 + 1 == m) {
		cout << "Yes";
	}
	else if (m * 2 == n || m * 2 + 1 == n) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	


	return 0;
}
