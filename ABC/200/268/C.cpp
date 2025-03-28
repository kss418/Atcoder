#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
ll arr[MAX], result[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		result[(arr[i] - i + n) % n]++;
		result[(arr[i] - i + n + 1) % n]++;
		result[(arr[i] - i + n - 1) % n]++;
	}

	ll cnt = 0;
	for (int i = 0; i < n; i++) cnt = max(cnt, result[i]);
	cout << cnt;

	return 0;
}
