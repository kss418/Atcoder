#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 110;
vector <int> arr[MAX];
bool v[MAX];

void dfs(int cur, int p) {
	if (v[cur]) {
		return;
	}
	v[cur] = 1;

	for (auto nxt : arr[cur]) {
		if (nxt == p) {
			continue;
		}

		dfs(nxt, cur);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
	
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i, 0);
			result++;
		}
	}

	cout << result;

	return 0;
}
