#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
string st[MAX];
vector <char> result[MAX];


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> st[i];
    for (int i = 0; i < MAX; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (st[j].size() <= i) result[i].push_back('*');
            else result[i].push_back(st[j][i]);
        }
    }

    for (int i = 0; i < MAX; i++) {
        while (!result[i].empty() && result[i].back() == '*') result[i].pop_back();
    }

    for (int i = 0; i < MAX; i++) {
        if (result[i].empty()) break;
        for (auto& j : result[i]) cout << j;
        cout << "\n";
    }

  
    return 0;
}
