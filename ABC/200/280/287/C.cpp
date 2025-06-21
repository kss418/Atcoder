#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
vector <int> arr[MAX];
int flag = 1, cnt, v[MAX];



void dfs(int cur, int p) {
	if (!flag) {
		return;
	}

	if (v[cur] || arr[cur].size() > 2) {
		flag = 0;
		return;
	}

	v[cur] = 1;
	cnt++;
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
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1, 0);
	
	if (flag && cnt == n) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
