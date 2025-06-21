#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr[100001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i].size() << " ";
		sort(arr[i].begin(), arr[i].end());
		for (auto j : arr[i]) {
			cout << j << " ";
		}
		cout << "\n"; 
	}


	
	return 0;
}

