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
const int MAX = 101010;
int arr[MAX * 2];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	int st = 0, en = s.size() - 1;
	int se = 1;
	while (1) {
		if (s[st] == 'a' && s[en] == 'a') {
			st++;
			en--;
		}
		else if (s[en] == 'a') {
			en--;
		}
		else {
			break;
		}
	}

	int flag = 1;
	while (st < en) {
		if (s[st] == s[en]) {
			st++;
			en--;
		}
		else {
			flag = 0;
			break;
		}
	}

	if (flag) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}


	return 0;
}
