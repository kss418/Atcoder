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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll sc[MAX], cnt[2];

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < m;i++){
        cnt[0] = cnt[1] = 0;
        for(int j = 0;j < n;j++) cnt[st[j][i] - '0']++;

        for(int j = 0;j < n;j++){
            if(st[j][i] == '0' && cnt[0] < cnt[1]) sc[j]++;
            if(st[j][i] == '1' && cnt[1] < cnt[0]) sc[j]++;
        }
    }

    ll mx = -1;
    vector <ll> result;
    for(int i = 0;i < n;i++){
        if(sc[i] < mx) continue;
        if(sc[i] > mx) result.clear();
        mx = sc[i];
        result.push_back(i + 1);
    }

    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}