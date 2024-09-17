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
const int MAX = 1010;
ll arr[MAX], cnt[400];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
		cnt[sum % 360] = 1;
	}
	
	int pre = 0;
	int result = 0;
	for (int i = 0; i < 360; i++) {
		if (cnt[i]) {
			result = max(i - pre, result);
			pre = i;
		}
	}
	result = max(360 - pre, result);
	
	cout << result;


	
	return 0;
}
