#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
deque <pll> q;

void run(){
    cin >> n;
    while(n--){
        ll op; cin >> op;
        if(op == 1){
            ll c, v; cin >> c >> v;
            if(q.empty() || q.back().x != v) q.push_back({v, c});
            else{
                ll cnt = q.back().y; q.pop_back();
                q.push_back({v, c + cnt});
            }
        }
        else{
            ll c, now = 0; cin >> c;
            while(c){
                auto& [v, cnt] = q.front(); q.pop_front();
                ll mn = min(c, cnt); now += v * mn;
                cnt -= mn; c -= mn;
                if(cnt) q.push_front({v, cnt});
            }

            cout << now << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

