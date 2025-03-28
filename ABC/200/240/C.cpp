#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
bool able[101][10000];
int jump[101][2];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, en;
    cin >> n >> en;
    for (int i = 1; i <= n; i++) {
        cin >> jump[i][0] >> jump[i][1];
    }
    
    able[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (j >= jump[i][0]) {
                able[i][j] = max(able[i][j], able[i - 1][j - jump[i][0]]);
            }

            if (j >= jump[i][1]) {
                able[i][j] = max(able[i][j], able[i - 1][j - jump[i][1]]);
            }
        }
    }

    if (able[n][en]) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}
