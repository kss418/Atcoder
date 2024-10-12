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
ll sum[31], cnt[31];

int main() {
    fastio;

    cin >> s;
    for(int i = 0;i < s.size();i++){
        sum[s[i] - 'A'] += i; cnt[s[i] - 'A']++;
    }

    ll result = 0;
    for(int i = 0;i < s.size();i++){
        sum[s[i] - 'A'] -= i; cnt[s[i] - 'A']--;
        result += sum[s[i] - 'A'] - cnt[s[i] - 'A'] * (i + 1);
    }

    cout << result;


    return 0;
}
