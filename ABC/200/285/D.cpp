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
vector <ll> q;

const int MAX = 101010;
string r[MAX], g[MAX];
ll ir[MAX], ig[MAX];
int indegree[MAX * 2];
vector <int> arr[MAX * 2];
deque <int> d;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	memset(ig, -1, sizeof(ig));
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i];

		ll cur = 1;
		ll num = 0;
		for (int j = r[i].size() - 1; j >= 0; j--) {
			num += (r[i][j] - 'a' + 1) * cur;
			cur *= 26;
		}
		ir[i] = num;
		q.push_back(num);

		cur = 1;
		num = 0;
		for (int j = g[i].size() - 1; j >= 0; j--) {
			num += (g[i][j] - 'a' + 1) * cur;
			cur *= 26;
		}
		ig[i] = num;
		q.push_back(num);
	}

	sort(q.begin(), q.end());
	q.erase(unique(q.begin(), q.end()), q.end());

	ll ma = 0;
	for (int i = 1; i <= n; i++) {
		ir[i] = lower_bound(q.begin(), q.end(), ir[i]) - q.begin() + 1;
		ig[i] = lower_bound(q.begin(), q.end(), ig[i]) - q.begin() + 1;
		ma = max({ ir[i],ig[i],ma });
		arr[ig[i]].push_back(ir[i]);
		indegree[ir[i]]++;
	}
	
	for (int i = 1; i <= ma; i++) {
		if (!indegree[i]) {
			d.push_back(i);
		}
	}

	int cnt = 0;
	while (!d.empty()) {
		int cur = d.front();
		d.pop_front();
		cnt++;

		for (auto nxt : arr[cur]) {
			indegree[nxt]--;
			if (!indegree[nxt]) {
				d.push_back(nxt);
			}
		}
	}
	
	if (cnt != ma) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}


	return 0;
}
