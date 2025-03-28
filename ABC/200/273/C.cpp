#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int result[200001] = {};
	int n;
	vector <int> arr;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int ptr = arr.size() - 2;
	int cur = 0;
	for (int i = ptr; i >= 0; i--) {
		if (arr[i] == arr[i + 1]) {
			result[cur]++;
		}
		else {
			result[cur]++;
			cur++;
		}
	}
	result[cur]++;
	
	for (int i = 0; i < arr.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
