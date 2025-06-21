#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	ll a, b;
	cin >> a >> b;
	ll result = 1;
	for (int i = 1; i <= b; i++) {
		result *= a;
	}

	cout << result;
	

	return 0;
}

