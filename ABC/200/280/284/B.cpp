#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 110;
int arr[MAX];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 1) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
	

	return 0;
}
