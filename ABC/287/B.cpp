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
const int MAX = 1010;
int arr[MAX], cnt[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		cnt[num]++;
	}

	ll result = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[arr[i] % 1000]) {
			result++;
		}
	}

	cout << result;

	return 0;
}
