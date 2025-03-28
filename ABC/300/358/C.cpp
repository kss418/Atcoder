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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
string st[MAX];
ll arr[MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        ll cur = 0;
        for(int j = 0;j < m;j++) if(st[i][j] == 'o') cur |= (1ll << j);
        arr[i] = cur;
    }

    vector <ll> per; per.resize(n);
    iota(all(per), 0);
    ll result = INF;

    while(1){
        ll cur = 0;
        for(int i = 0;i < n;i++){
            cur |= arr[per[i]];
            if(cur == (1ll << m) - 1) result = min<ll>(result, i + 1);
        }

        if(!next_permutation(all(per))) break;
    }

    cout << result;


    return 0;
}

