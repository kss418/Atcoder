#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr[200000];
int n, k, num, pu, ord;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (num--) {
			cin >> pu;
			arr[i].push_back(pu);
		}
	}

	while (k--) {
		cin >> num >> ord;
		cout << arr[num - 1][ord - 1] << "\n";
	}

	return 0;
}
