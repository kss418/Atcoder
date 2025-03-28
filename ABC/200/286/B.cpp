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
const int MAX = 101;
vector <char> result;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (i && s[i] == 'a' && s[i - 1] == 'n') {
			result.pop_back();
			result.push_back('n');
			result.push_back('y');
			result.push_back('a');
		}
		else {
			result.push_back(s[i]);
		}
	}

	for (auto i : result) {
		cout << i;
	}

	return 0;
}
