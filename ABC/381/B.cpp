#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[31];


int main() {
    fastio;

    cin >> s;

    ll flag = 1;
    if(s.size() % 2) flag = 0;

    for(auto& i : s) cnt[i - 'a']++;
    for(int i = 0;i < s.size() / 2;i++){
        if(s[2 * i] != s[2 * i + 1]) flag = 0;
    }

    for(int i = 0;i < 26;i++){
        if(cnt[i] && cnt[i] != 2) flag = 0;
    }

    if(!flag) cout << "No";
    else cout << "Yes";


    return 0;
}

