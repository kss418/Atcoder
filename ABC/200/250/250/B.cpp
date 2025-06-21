#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 11;
int arr[1001][1001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> n >> y >> x;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cnt = i % 2;
		for (int j = 0; j < n; j++) {
			for (int l = 1; l <= y; l++) {
				for (int k = 1; k <= x; k++) {
					arr[i * y + l][j * x + k] = cnt;
				}
			}
			cnt ^= 1;
		}
	}

	for (int i = 1; i <= n * y; i++) {
		for (int j = 1; j <= n * x; j++) {
			if (arr[i][j]) {
				cout << "#";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	

	return 0;
}
