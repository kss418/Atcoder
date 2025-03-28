#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;


const int MAX = 201010;
vector <int> arr[MAX];
int v[MAX];
vector <int> result;
int cnt = 1;


void bt(int cur) {
	if (cur == 1) {
		v[1] = 1;
		result.push_back(1);
	}

	for (auto nxt : arr[cur]) {
		if (v[nxt]) {
			continue;
		}

		v[nxt] = 1;
		result.push_back(nxt);
		cnt++;
		if (cnt >= 1000000) {
			return;
		}
		bt(nxt);
		result.pop_back();
		v[nxt] = 0;
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

	bt(1);
	cout << min(cnt,1000000);


	return 0;
}
