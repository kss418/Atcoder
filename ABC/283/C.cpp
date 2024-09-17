#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
string n;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	int result = 0;
	for (int i = 0; i < n.size(); i++) {
		if (i < n.size() - 1 && n[i] == '0' && n[i + 1] == '0') {
			i++;
		}
		result++;
	}

	cout << result;

	return 0;
}

