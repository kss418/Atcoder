#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, com, num1, num2, cnt[200002];
ll arr[200002], orig, num;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> com >> num1;
		if (com == 1) {
			num = num1;
			orig++;
		}
		else if (com == 2) {
			cin >> num2;
			if (cnt[num1] != orig) {
				cnt[num1] = orig;
				arr[num1] = num + num2;
			}
			else {
				arr[num1] += num2;
			}
		}
		else {
			if (cnt[num1] == orig) {
				cout << arr[num1] << "\n";
			}
			else {
				cout << num << "\n";
			}
		}
	}

	

	return 0;
}

