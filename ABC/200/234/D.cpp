#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int seg[2000001];
int arr[500001];
	
void update(int st, int en, int node, int num, int value) {
	if (st > num || en < num) {
		return;
	}

	seg[node] += value;
	if (st == en) {
		return;
	}

	int mid = (st + en) / 2;
	update(st, mid, node * 2, num, value);
	update(mid + 1, en, node * 2 + 1, num, value);
}

int query(int st, int en, int node, int num) {
	if (st == en) {
		return en;
	}

	int mid = (st + en) / 2;
	if (seg[node * 2] < num) {
		return query(mid + 1, en, node * 2 + 1, num - seg[node * 2]);
	}
	else {
		return query(st, mid, node * 2, num);
	}
}




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < k; i++) {
		update(1, n, 1, arr[i], 1);
	}

	for (int i = k; i <= n; i++) {
		update(1, n, 1, arr[i], 1);
		cout << query(1, n, 1, i - k + 1) << "\n";
	}
	


	return 0;
}

