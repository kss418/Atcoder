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
const int MAX = 15;
string st[MAX];
vector <pll> arr;
ll cur[5];
ll dist[5][5];
ll cnt[1001];


ll diff(pll a, pll b) {
	ll first = a.first - b.first;
	ll second = b.second - a.second;
	return first * first + second * second;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 9; i++) {
		cin >> st[i];
		for (int j = 0; j < 9; j++) {
			if (st[i][j] == '#') {
				arr.push_back({ i,j + 1 });
			}
		}
	}

	ll result = 0;
	n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					cur[1] = i;
					cur[2] = j;
					cur[3] = k;
					cur[4] = l;
					memset(dist, 0, sizeof(dist));
					memset(cnt, 0, sizeof(cnt));

					ll mi = INF, ma = 0;
					for (int o = 1; o < 4; o++) {
						for (int p = o + 1; p <= 4; p++) {
							dist[o][p] = diff(arr[cur[o]], arr[cur[p]]);
							cnt[dist[o][p]]++;
							mi = min(mi, dist[o][p]);
							ma = max(ma, dist[o][p]);
						}
					}

					bool flag = 0;
					if (cnt[mi] == 4 && cnt[ma] == 2) {
						flag = 1;
					}

					if (flag) {
						result++;
					}
				}
			}
		}
	}

	cout << result;

	return 0;
}
