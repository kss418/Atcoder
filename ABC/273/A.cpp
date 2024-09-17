#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fun(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return fun(n - 1) * n;
	}
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << fun(n);




	return 0;
}
