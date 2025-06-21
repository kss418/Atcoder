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
vector <ll> arr[MAX];
ll cnt, v[MAX];

void dfs(ll cur, ll p) {
	if (v[cur]) {
		cnt++;
		return;
	}
	v[cur] = 1;

	for (auto nxt : arr[cur]) {
		if (nxt == p) continue;
		dfs(nxt, cur);
	}
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		ll st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}

	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i, 0);
		}
	}
	cout << (cnt >> 1);

	return 0;
}
