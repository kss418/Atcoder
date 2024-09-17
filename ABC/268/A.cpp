#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101;
ll use[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i <= 5; i++) {
		cin >> n;
		use[n] = 1;
	}

	ll result = 0;
	for (int i = 0; i <= 100; i++) {
		result += use[i];
	}
	cout << result;


	return 0;
}