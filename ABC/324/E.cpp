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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
string st[MAX];
ll pre[MAX], suf[MAX], sp[MAX];

int main() {
    fastio;

    cin >> n >> s;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        ll cur = 0;
        for(int j = 0;j < st[i].size();j++){
            if(st[i][j] == s[cur] && cur < s.size()) cur++;
        }
        pre[cur]++; cur = 0;

        for(int j = st[i].size() - 1;j >= 0;j--){
            if(st[i][j] == s[s.size() - cur - 1] && cur < s.size()) cur++;
        }
        suf[cur]++;
    }

    for(int i = s.size();i >= 0;i--) sp[i] = sp[i + 1] + pre[i];

    ll result = 0;
    for(int i = 0;i <= s.size();i++) result += suf[i] * sp[s.size() - i];
    
    cout << result;
    

    return 0;
}
