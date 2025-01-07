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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 66; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
pll p1 = {-1, -1}, p2;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

class node{
public:
    pll p1, p2;
};

ll tf(node& v){
    ll ret = v.p1.x + v.p1.y * 60 + v.p2.x * 3600 + v.p2.y * 216000;
    return ret;
}
ll dist[13101010];

bool outrange(pll v){
    if(v.x < 0 || v.y < 0 || v.x >= n || v.y >= n) return 1;
    if(st[v.x][v.y] == '#') return 1;
    return 0;
}

void bfs(){
    deque <pair<node, ll>> q;
    memset(dist, 0x3f, sizeof(dist));
    q.push_back({{p1, p2}, 0});

    while(!q.empty()){
        auto[cp, cd] = q.front(); q.pop_front();
        if(dist[tf(cp)] <= cd) continue;
        dist[tf(cp)] = cd;

        auto[p1, p2] = cp;
        for(int i = 0;i < 4;i++){
            pll np1 = p1, np2 = p2;
            np1.x += dx[i]; np2.x += dx[i];
            np1.y += dy[i]; np2.y += dy[i];

            if(outrange(np1)) np1 = p1;
            if(outrange(np2)) np2 = p2;
            q.push_back({{np1, np2}, cd + 1});
        }
    }
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < n;j++){
            if(st[i][j] != 'P') continue;
            if(p1.x == -1) p1 = {i, j};
            else p2 = {i, j};
        }
    }
    node now = {p1, p2};

    bfs(); ll result = INF;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            node now = {{i, j}, {i, j}};
            result = min(result, dist[tf(now)]);
        }
    }

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
