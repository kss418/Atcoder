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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], c[MAX];
priority_queue <pll, vector<pll>, greater<pll>> pq; 

void run(){
    cin >> n >> m; ll now = 0, cnt = 0;;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i] >> c[i];

        while(!pq.empty() && cnt + c[i] > m){
            auto[qt, qc] = pq.top(); pq.pop();
            now = max(now, qt); cnt -= qc;
        }

        now = max(now, a[i]);
        pq.push({now + b[i], c[i]}); cnt += c[i];
        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}