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



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int flag = 0;
	for (int i = 1; i <= a.size(); i++) {
		if (b.substr(0, i) == a) {
			flag = 1;
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
