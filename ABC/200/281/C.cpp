#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int arr[100001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n, t, result;
	cin >> n >> t;
	ll all = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		all += arr[i];
	}

	t %= all;
	for (int i = 1; i <= n; i++) {
		if (t >= arr[i]) {
			t -= arr[i];
		}
		else {
			result = i;
			break;
		}
	}

	cout << result << " " << t;

	return 0;
}

