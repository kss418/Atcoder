#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
string st[MAX];

bool chk(ll cy, ll cx){
    ll cnt = 0;
    for(int ny = cy; ny <= cy + 5;ny++){
        if(ny >= n) { cnt = 0; break; }
        if(st[ny][cx] == '#') cnt++;
    }
    if(cnt >= 4) return 1;

    cnt = 0;
    for(int nx = cx; nx <= cx + 5;nx++){
        if(nx >= n) { cnt = 0; break; }
        if(st[cy][nx] == '#') cnt++;
    }
    if(cnt >= 4) return 1;

    cnt = 0;
    for(int num = 0; num <= 5;num++){
        ll nx = cx + num, ny = cy + num;
        if(nx >= n) { cnt = 0; break; }
        if(ny >= n) { cnt = 0; break;}
        if(st[ny][nx] == '#') cnt++;
    }
    if(cnt >= 4) return 1;

    cnt = 0;
    for(int num = 0; num <= 5;num++){
        ll nx = cx - num, ny = cy + num;
        if(nx < 0) { cnt = 0; break; }
        if(ny >= n) { cnt = 0; break;}
        if(st[ny][nx] == '#') cnt++;
    }
    if(cnt >= 4) return 1;


    return 0;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll flag = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(flag) break;
            flag |= chk(i, j);
        }
    }

    if(flag) cout << "Yes";
    else cout << "No";
    
    
    return 0;
}
