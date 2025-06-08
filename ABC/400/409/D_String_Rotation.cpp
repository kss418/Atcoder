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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], mn[30];
vector <char> result;

void run(){
    cin >> n >> s; result.clear();
    memset(mn, 0x3f, sizeof(mn));
    for(int i = 0;i < n;i++){
        mn[s[i] - 'a'] = min<ll>(mn[s[i] - 'a'], i);
    }

    for(int i = 24;i >= 0;i--){
        mn[i] = min(mn[i], mn[i + 1]);
    }

    for(int i = 0;i < n - 1;i++){
        if(s[i] <= s[i + 1]){
            result.push_back(s[i]);
            continue;
        }

        for(int j = i + 1;j < min(n, mn[s[i] - 'a' + 1]);j++){
            result.push_back(s[j]);
        }
        result.push_back(s[i]);

        for(int j = min(n, mn[s[i] - 'a' + 1]);j < n;j++){
            result.push_back(s[j]);
        }
        break;
    }

    if(result.size() != n) result.push_back(s.back());
    for(auto& i : result) cout << i;
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

