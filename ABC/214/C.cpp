#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n,m;
string s;
const int MAX = 202020;
int gem[MAX], t[MAX];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> gem[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    t[1] = min(t[1], t[n] + gem[n]);
    for (int i = 2; i <= n; i++) {
        t[i] = min(t[i], t[i - 1] + gem[i - 1]);
    }

    t[1] = min(t[1], t[n] + gem[n]);
    for (int i = 2; i <= n; i++) {
        t[i] = min(t[i], t[i - 1] + gem[i - 1]);
    }


    for (int i = 1; i <= n; i++) {
        cout << t[i] << "\n";
    }
    

    return 0;
}
