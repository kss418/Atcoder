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
const int MAX = 501010;
int nxt[MAX], pre[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	int nx, pr;
	memset(nxt, -1, sizeof(nxt));
	memset(pre, -1, sizeof(pre));

	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			nx = i;
			pr = i + 1;
			nxt[pre[nx]] = pr;
			nxt[pr] = nx;
			pre[pr] = pre[nx];
			pre[nx] = pr;
		}
		else {
			nx = i + 1;
			pr = i;
			pre[nxt[pr]] = nx;
			nxt[nx] = nxt[pr];
			pre[nx] = pr;
			nxt[pr] = nx;
		}
	}

	int st;
	for (int i = 0; i <= n; i++) {
		if (pre[i] == -1) {
			st = i;
			break;
		}
	}

	int cur = st;
	while (cur != -1) {
		cout << cur << " ";
		cur = nxt[cur];
	}


	return 0;
}
