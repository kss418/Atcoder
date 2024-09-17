#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    
    int x, y, n;
    cin >> x >> y >> n;
    int mod = n % 3;
    int moc = n / 3;

    cout << min(x * n, x * mod + y * moc);





    return 0;
}
