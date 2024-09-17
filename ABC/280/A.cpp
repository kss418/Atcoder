#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	string arr[11];
	cin >> y >> x;
	int cnt = 0;
	for (int i = 1; i <= y; i++) {
		cin >> arr[i];
		for (int j = 0; j < x; j++) {
			if (arr[i][j] == '#') {
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	

	return 0;
}

