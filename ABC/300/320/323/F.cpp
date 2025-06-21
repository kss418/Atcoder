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
ll result;
ll px, py, cx, cy, ex, ey;

void run(){
    cin >> px >> py >> cx >> cy >> ex >> ey; 
    ll dx = (ex - cx > 0) ? 1 : -1;
    if(ex == cx) dx = 0;

    ll dy = (ey - cy > 0) ? 1 : -1;
    if(ey == cy) dy = 0;

    ll mx = cx - dx, my = cy - dy;
    ll disty = abs(cx - px) + abs(my - py);
    ll distx = abs(mx - px) + abs(cy - py);
    if(cy == py){
        if(cx > mx && cx < px) distx += 2;
        if(cx < mx && cx > px) distx += 2;
    }

    if(cx == px){
        if(cy > my && cy < py) disty += 2;
        if(cy < my && cy > py) disty += 2;
    }

    if(mx != ex && my != ey) result += min(disty, distx);
    else if(mx != ex) result += distx;
    else result += disty;
    result += abs(ex - cx) + abs(ey - cy);
    cout << result + (mx != ex && my != ey ? 2 : 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
