#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;



int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if (abs(a % 10 - b % 10) == 1 || abs(a - b) == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }


    return 0;
}
