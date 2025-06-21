#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n,m;
string s;
ll result;
bool v[101][101][101];


void dfs(int a, int b, int c) {
    if (a + b + c > n) {
        return;
    }

    if (a * b * c > m) {
        return;
    }

    if (v[a][b][c]) {
        return;
    }
    v[a][b][c] = 1;

    result++;
    dfs(a + 1, b, c);
    dfs(a, b + 1, c);
    dfs(a, b, c + 1);
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    dfs(0, 0, 0);

    cout << result;
  
    return 0;
}
