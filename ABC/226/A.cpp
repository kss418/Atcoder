#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 101010;
int arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	double x;
	cin >> x;
	if ((int)x + 1 - x <= 0.5) {
		cout << (int)(x + 1);
	}
	else {
		cout << (int)x;
	}
	
	
	return 0;
}
