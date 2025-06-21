#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int result[500002];
int arr[500002];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	result[1] = 0;

	for (int i = 1; i <= n; i++) {
		result[2 * i] = result[arr[i]] + 1;
		result[2 * i + 1] = result[arr[i]] + 1;
	}

	for (int i = 1; i <= 2 * n + 1; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
