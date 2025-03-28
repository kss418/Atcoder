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
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 501010;
ll arr[MAX];
vector <ll> num[MAX];
vector <ll> same, diff;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		if (arr[i] == i) {
			same.push_back(i);
		}
	}

	ll sr = 0, dr = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == i) {
			sr += same.size() - 1;
		}
		else {
			dr += arr[arr[i]] == i;
		}
	}

	sr /= 2;
	dr /= 2;
	cout << sr + dr;

	return 0;
}
