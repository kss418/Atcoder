#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
pair <int, int> cnt[1001];
int c;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	for(int i = 1; i <= n;i++){
		int num;
		cin >> num;

		while (num % 2 == 0) {
			num /= 2;
			cnt[i].first++;
			c++;
		}
		while (num % 3 == 0) {
			num /= 3;
			cnt[i].second++;
			c++;
		}

		arr[i] = num;
	}

	int flag = 1;
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			flag = 0;
		}
	}

	if (!flag) {
		cout << -1;
		return 0;
	}

	int two = 1000000, three = 10000000;

	for (int i = 1; i <= n; i++) {
		two = min(two, cnt[i].first);
		three = min(three, cnt[i].second);
	}

	c -= two * n;
	c -= three * n;
	cout << c;
	
	return 0;
}

