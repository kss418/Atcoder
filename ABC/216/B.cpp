#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
set <pair<string, string>> arr;

int main() {
    fastio;
    
    cin >> n;
    ll flag = 0;
    for (int i = 1; i <= n; i++) {
        string s, e;
        cin >> s >> e;
        if (arr.count({ s,e })) flag = 1;
        arr.insert({ s,e });
    }

    if (flag) cout << "Yes";
    else cout << "No";
    

    return 0;
}
