#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
string st[MAX];
ll cnt[10][10];

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < 10;j++) cnt[st[i][j] - '0'][j]++;
    }

    ll result = INF;
    for(int i = 0;i < 10;i++){
        ll cur = 0;
        for(int j = 0;j < 10;j++){
            cur = max(cur, (cnt[i][j] - 1) * 10 + j);
        }
        
        result = min(result, cur);
    }

    cout << result;


    return 0;
}
