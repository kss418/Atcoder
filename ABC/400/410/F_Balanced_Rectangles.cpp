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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MID = 351010;
constexpr ll MOD = 998244353;
string st[MAX], tmp[MAX];
ll cnt[2 * MAX + 101010];
vector <ll> use;

void flip(){
    for(int i = 0;i < m;i++) tmp[i].clear();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) tmp[j].push_back(st[i][j]);
    }

    swap(n, m);
    for(int i = 0;i < n;i++) st[i] = tmp[i];
}

void run(){
    cin >> n >> m; ll result = 0;
    for(int i = 0;i < n;i++) cin >> st[i];
    if(n > m) flip();
    vector <vector <ll>> sum(n + 1, vector<ll>(m + 1, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            sum[i][j] += (st[i - 1][j - 1] == '#' ? 1 : -1);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            cnt[MID] = 1;
            for(int k = 1;k <= m;k++){
                ll now = sum[j][k] - sum[i - 1][k];
                result += cnt[now + MID];
                cnt[now + MID]++; use.push_back(now + MID);
            }

            cnt[MID] = 0;
            for(auto& v : use) cnt[v] = 0;
            use.clear();
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

