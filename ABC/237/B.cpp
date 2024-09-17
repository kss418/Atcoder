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

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i * m + j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i + j * m] << " ";
		}
		cout << "\n";
	}


	return 0;
}
