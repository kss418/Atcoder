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
const int MAX = 101;
ll arr[MAX], result[MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll a, b;
	cin >> n >> m >> k >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		result[i] = arr[i];
	}

	for (int i = m; i <= k; i++) {
		result[i + a - m] = arr[i];
	}

	for (int i = a; i <= b; i++) {
		result[i - a + m] = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}


	return 0;
}
