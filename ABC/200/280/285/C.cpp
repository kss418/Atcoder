#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;


const int MAX = 5010;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	ll result = 0;
	ll mul = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		result += mul * (s[i] - 'A' + 1);
		mul *= 26;
	}

	cout << result;
	
	


	return 0;
}
