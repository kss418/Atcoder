#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;
int v[501][501];
stack <pair<int, int>> path;
int x, y;
int flag = 1;
string s[501];


void dfs(int curx, int cury) {
    if (curx < 0 || curx >= x || cury < 0 || cury >= y) {
        return;
    }

    if (v[cury][curx]) {
        flag = 0;
        return;
    }
    v[cury][curx] = 1;
    path.push({ curx, cury });

    if (s[cury][curx] == 'U') {
        dfs(curx, cury - 1);
    }
    else if (s[cury][curx] == 'D') {
        dfs(curx, cury + 1);
    }
    else if (s[cury][curx] == 'L') {
        dfs(curx - 1, cury);
    }
    else {
        dfs(curx + 1, cury);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    cin >> y >> x;

    for (int i = 0; i < y; i++) {
        cin >> s[i];
    }

    dfs(0, 0);
    
    if (flag) {
        cout << path.top().second + 1<< " " << path.top().first + 1;
    }
    else {
        cout << -1;
    }

    return 0;
}
