#include <bits/stdc++.h>
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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cy1, cx1, cy2, cx2, result;
deque <pll> q[2];
ll dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool chk(ll o, ll c, ll m){
    if(c > o && m < o) return 0;
    if(c < o && m > o) return 0;
    return 1;
}

bool chk1(ll oy1, ll ox1, ll oy2, ll ox2, ll d){
    if(cy1 != oy1 && cy2 != oy2) return 0;
    if(cx1 != ox1 && cx2 != ox2) return 0;

    ll my = (cy1 == oy1 ? cy1 : cy2);
    ll mx = (cx1 == ox1 ? cx1 : cx2);

    if(!chk(oy1, cy1, my) || !chk(ox1, cx1, mx)) return 0;
    if(!chk(oy2, cy2, my) || !chk(ox2, cx2, mx)) return 0;

    if(abs(mx - ox1) + abs(my - oy1) > d) return 0;
    return ((abs(mx - ox1) + abs(my - oy1)) == (abs(mx - ox2) + abs(my - oy2)));
}

bool chk2(ll oy1, ll ox1, ll oy2, ll ox2, ll d){
    if(cy1 == oy1 && cy2 != oy2) return 0;
    if(cx1 == ox1 && cx2 != ox2) return 0;

    if(ox1 != cx1 && oy1 == oy2){
        if(ox1 > ox2 && cx1 <= cx2 && abs(cx1 - cx2) % 2 == 0) return 1;
        if(ox2 > ox1 && cx2 <= cx1 && abs(cx1 - cx2) % 2 == 0) return 1;
    }
    
    if(oy1 != cy1 && ox1 == ox2){
        if(oy1 > oy2 && cy1 <= cy2 && abs(cy1 - cy2) % 2 == 0) return 1;
        if(oy2 > oy1 && cy2 <= cy1 && abs(cy1 - cy2) % 2 == 0) return 1;
    }

    return 0;
}

void run(){
    cin >> cy1 >> cx1 >> cy2 >> cx2 >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        char c; ll v; cin >> c >> v;
        if(c == 'R') q[0].push_back({0, v});
        if(c == 'L') q[0].push_back({1, v});
        if(c == 'U') q[0].push_back({2, v});
        if(c == 'D') q[0].push_back({3, v});
    }

    for(int i = 1;i <= k;i++){
        char c; ll v; cin >> c >> v;
        if(c == 'R') q[1].push_back({0, v});
        if(c == 'L') q[1].push_back({1, v});
        if(c == 'U') q[1].push_back({2, v});
        if(c == 'D') q[1].push_back({3, v});
    }

    while(!q[0].empty() && !q[1].empty()){
        auto[c0, v0] = q[0].front();
        auto[c1, v1] = q[1].front();
        ll mn = min(v0, v1), oy1 = cy1, oy2 = cy2, ox1 = cx1, ox2 = cx2;

        cy1 += mn * dy[c0]; cy2 += mn * dy[c1];
        cx1 += mn * dx[c0]; cx2 += mn * dx[c1];

        if(oy1 == oy2 && ox1 == ox2){
            if(c0 == c1) result += mn;
        }
        else if(chk1(oy1, ox1, oy2, ox2, mn)) result++;
        else if(c0 != c1 && chk2(oy1, ox1, oy2, ox2, mn)) result++;
        q[0].pop_front(); q[1].pop_front();

        if(v0 > mn) q[0].push_front({c0, v0 - mn}); 
        if(v1 > mn) q[1].push_front({c1, v1 - mn}); 
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}