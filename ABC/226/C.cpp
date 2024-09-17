#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;
vector <int> arr[MAX];
bool v[MAX];
ll ti[MAX]; vector <int> path;
ll result;

void dfs(int cur) {
	if (v[cur]) {
		return;
	}
	v[cur] = 1;

	result += ti[cur];
	for (auto nxt : arr[cur]) {
		if (!v[nxt]) {
			dfs(nxt);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ti[i] >> m;
		for (int j = 1; j <= m; j++) {
			int num;
			cin >> num;
			arr[i].push_back(num);
		}
	}

	result += ti[n];
	for (auto i : arr[n]) {
		if (!v[i]) {
			dfs(i);
		}
	}

	cout << result;


	return 0;
}
