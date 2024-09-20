#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
map <string, bool> arr;

int main() {
    fastio;

    string a, b;
    cin >> a >> b;

    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            string cur;
            for (int k = j; k < a.size(); k += i) cur.push_back(a[k]);
            arr[cur] = 1;
        }
    }
    
    if (arr.count(b)) cout << "Yes";
    else cout << "No";


    return 0;
}
