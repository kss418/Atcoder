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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];
vector <vector<ll>> dis, able;

int main() {
    fastio;


    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        ll num; cin >> num;
        vector <ll> cur;
        for(int j = 1;j <= num;j++) {
            cin >> t; cur.push_back(t - 1);
        }

        cin >> s;
        if(s[0] == 'o') able.push_back(cur);
        else dis.push_back(cur);
    }

    ll result = 0;
    for(int i = 0;i < (1ll << n);i++){
        ll flag = 1;
        for(auto& j : able){
            ll cnt = 0;
            for(auto& now : j){
                if(i & (1ll << now)) cnt++;
            }

            if(cnt < k) flag = 0;
        }

        for(auto& j : dis){
            ll cnt = 0;
            for(auto& now : j){
                if(i & (1ll << now)) cnt++;
            }

            if(cnt >= k) flag = 0;
        }

        if(flag) result++;
    }

    cout << result;
    

    return 0;
}

