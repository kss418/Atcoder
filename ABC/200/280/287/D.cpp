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
ll n, m, k; string s, t;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

bool chk(ll sidx, ll tidx){
    if(s[sidx] == '?' || t[tidx] == '?') return 1;
    else if(s[sidx] == t[tidx]) return 1;
    return 0;
}

void print(ll cnt){
    if(cnt == t.size()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    fastio;

    cin >> s >> t;

    ll cnt = 0, cur = 0;
    for(int i = s.size() - t.size();i < s.size();i++){
        if(chk(i, cur)) cnt++; cur++;
    }
    print(cnt); 

    ll pre = s.size() - t.size();
    for(int i = 0;i < t.size();i++){
        if(chk(pre, i)) cnt--; pre++;
        if(chk(i, i)) cnt++;

        print(cnt);
    }


    return 0;
}
