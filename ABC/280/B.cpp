#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int arr[11];
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] - arr[i - 1] << " ";
	}
	

	return 0;
}

