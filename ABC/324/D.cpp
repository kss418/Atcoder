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
short cnt[10], num[10];
ll result;


int main() {
    fastio;

    cin >> n >> s;

    sort(all(s)); reverse(all(s));
    for(auto& i : s) num[i - '0']++;

    ll mx = stoll(s);
    for(ll i = 0;i * i <= mx;i++){
        string cur = to_string(i * i);
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = n - cur.size();
        for(auto&i : cur) cnt[i - '0']++;

        ll flag = 1;
        for(int i = 0;i < 10;i++) if(num[i] != cnt[i]) flag = 0;

        if(flag) result++;
    }

    cout << result;


    return 0;
}
