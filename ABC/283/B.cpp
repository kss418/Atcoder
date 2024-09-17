#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, com, x, k;
int arr[100001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	while (m--) {
		cin >> com >> k;
		if (com == 1) {
			cin >> x;
			arr[k] = x;
		}
		else {
			cout << arr[k] << "\n";
		}
	}


	return 0;
}

