#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;
set <vector <int>> arr;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		vector <int> cur;
		for (int i = 1; i <= m; i++) {
			int num;
			cin >> num;
			cur.push_back(num);
		}
		arr.insert(cur);
	}
	
	cout << arr.size();
	
	return 0;
}
