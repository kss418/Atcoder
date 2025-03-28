#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> y >> x;
	string arr[31];
	for (int i = 1; i <= y; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j < i; j++) {
			int cur = 0;
			for (int k = 0; k < x; k++) {
				if (arr[i][k] == 'o' || arr[j][k] == 'o') {
					cur++;
				}
			}

			if (cur == x) {
				cnt++;
			}
		}
	}

	cout << cnt;
		


	return 0;
}

