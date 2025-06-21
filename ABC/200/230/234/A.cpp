#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int fx(int t) {
	return t * t + 2 * t + 3;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	
	int t;
	cin >> t;
	cout << fx(fx((fx(t) + t)) + fx(fx(t)));



	return 0;
}

