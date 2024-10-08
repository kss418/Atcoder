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
ll r, c;
map <ll, vector<ll>> cs, rs;

int main() {
    fastio;

    ll h, w, cy, cx; cin >> h >> w >> cy >> cx;
    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> r >> c;
        cs[c].push_back(r);
        rs[r].push_back(c);
    }
    for(auto& i : cs) sort(all(i.y));
    for(auto& i : rs) sort(all(i.y));

    ll q; cin >> q;
    while(q--){
        char d; ll l; cin >> d >> l;

        if(d == 'L'){
            auto nxt = lower_bound(all(rs[cy]), cx);
            if(nxt == rs[cy].begin()) cx = max(cx - l, 1ll);
            else{
                nxt--;
                cx = max(cx - l, *nxt + 1);
            }
        }
        else if(d == 'R'){
            auto nxt = lower_bound(all(rs[cy]), cx);
            if(nxt == rs[cy].end()) cx = min(cx + l, w);
            else cx = min(cx + l, *nxt - 1);
        }
        else if(d == 'U'){
            auto nxt = lower_bound(all(cs[cx]), cy);
            if(nxt == cs[cx].begin()) cy = max(cy - l, 1ll);
            else{
                nxt--;
                cy = max(cy - l, *nxt + 1);
            }
        }
        else{
            auto nxt = lower_bound(all(cs[cx]), cy);
            if(nxt == cs[cx].end()) cy = min(cy + l, h);
            else cy = min(cy + l, *nxt - 1);
        }

        cout << cy << " " << cx << "\n";
    }


    return 0;
}
