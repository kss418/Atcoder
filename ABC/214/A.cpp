#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n,m;



int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    if (n >= 1 && n <= 125) {
        cout << 4;
    }
    else if (n >= 126 && n <= 211) {
        cout << 6;
    }
    else {
        cout << 8;
    }

  
    return 0;
}
