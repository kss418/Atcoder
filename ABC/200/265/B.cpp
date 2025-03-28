#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll arr[100001], bonus[100001];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

        
    ll n, m, t;
    cin >> n >> m >> t;
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int pos;
        cin >> pos;
        cin >> bonus[pos];
    }

    int flag = 1;
    for (int i = 2; i <= n; i++) {
        if (t > arr[i]) {
            t -= arr[i];
            t += bonus[i];
            continue;
        }
        else {
            flag = 0;
            break;
        }
    }

    if (flag) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }



    return 0;
}
