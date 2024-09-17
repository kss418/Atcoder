#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
bool chk[1000000000];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (!chk[num]) {
            cnt++;
            chk[num] = 1;
        }
    }

    cout << cnt;

    return 0;
}
