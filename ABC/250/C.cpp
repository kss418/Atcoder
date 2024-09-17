#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;
int arr[MAX], pos[MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		pos[i] = i;
	}

	while (m--) {
		int num;
		cin >> num;
		int cur = pos[num];
		if (cur != n) {
			int temp = arr[cur + 1];
			arr[cur + 1] = arr[cur];
			pos[arr[cur]]++;
			arr[cur] = temp;
			pos[arr[cur]]--;
		}
		else {
			int temp = arr[cur - 1];
			arr[cur - 1] = arr[cur];
			pos[arr[cur]]--;
			arr[cur] = temp;
			pos[arr[cur]]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	

	return 0;
}
