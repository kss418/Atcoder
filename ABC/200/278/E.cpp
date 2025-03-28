#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int x, y, n, bx, by;
int arr[301][301], result[301][301];
int num[301], cur[301];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> y >> x >> n >> by >> bx;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> arr[i][j];
			num[arr[i][j]]++;
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (i + by - 1 > y || j + bx - 1 > x) {
				continue;
			}

			for (int k = 1; k <= 300; k++) {
				cur[k] = num[k];
			}

			for (int k = i; k <= i + by - 1; k++) {
				for (int l = j; l <= j + bx - 1; l++) {
					cur[arr[k][l]]--;
				}
			}

			int cnt = 0;
			for (int k = 1; k <= 300; k++) {
				if (cur[k]) {
					cnt++;
				}
			}

			result[i][j] = cnt;
		}
	}

	for (int i = 1; i <= y - by + 1; i++) {
		for (int j = 1; j <= x - bx + 1; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}

