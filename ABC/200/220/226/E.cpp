#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;
const int MOD = 998244353;
vector <int> arr[MAX];
bool v[MAX];
ll edge, node;

void dfs(int cur) {
	if (v[cur]) {
		return;
	}
	v[cur] = 1;
	node++;
	edge += arr[cur].size();

	for (auto nxt : arr[cur]) {
		dfs(nxt);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	ll result = 1;

	for (int i = 1; i <= m; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
	
	for (int i = 1; i <= n; i++) {
		edge = 0, node = 0;
		if (!v[i]) {
			dfs(i);
			
			if (node * 2 == edge) {
				result *= 2;
				result %= MOD;
			}
			else {
				result = 0;
			}
		}
	}
	
	
	cout << result;
	



	return 0;
}
