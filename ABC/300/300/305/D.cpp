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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> a;
map <ll, ll> sum;
map <ll, bool> cnt;

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> m; 
        a.push_back(m);
        cnt[m] = i % 2;
    }

    sum[0] = 0;
    for(int i = 1;i < n;i++){
        if(i % 2 == 1) sum[a[i]] = sum[a[i - 1]];
        else sum[a[i]] = sum[a[i - 1]] + (a[i] - a[i - 1]);
    }

    cin >> m;
    while(m--){
        ll l, r; cin >> l >> r;
        ll st = *lower_bound(all(a), l);
        ll en = *lower_bound(all(a), r);

        ll cur = sum[en] - sum[st];
        if(cnt[st] % 2 == 0) cur += st - l;
        if(cnt[en] % 2 == 0) cur -= en - r;

        cout << cur << "\n";
    }


    return 0;
}
