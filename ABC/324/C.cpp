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
vector <ll> result;
map <string, bool> cnt, org;


int main() {
    fastio;

    cin >> n >> s;

    for(int i = 0;i < n;i++) {
        cin >> st[i];
        ll cs = st[i].size();
        if(cs > s.size() + 1 || cs < s.size() - 1) continue;
        
        if(cs == s.size()){
            ll cnt = 0;
            for(int idx = 0;idx < cs;idx++){
                if(s[idx] != st[i][idx]) cnt++;
                if(cnt >= 2) break;
            }

            if(cnt <= 1) result.push_back(i + 1);
        }
        else if(cs == s.size() - 1){
            ll cnt = 0;
            for(int idx = 0;idx < s.size();idx++){
                if(s[idx] != st[i][idx - cnt]) cnt++;
                if(cnt >= 2) break;
            }

            if(cnt <= 1) result.push_back(i + 1);
        }
        else if(cs == s.size() + 1){
            ll cnt = 0;
            for(int idx = 0;idx < cs;idx++){
                if(s[idx - cnt] != st[i][idx]) cnt++;
                if(cnt >= 2) break;
            }

            if(cnt <= 1) result.push_back(i + 1);
        }
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";


    return 0;
}
