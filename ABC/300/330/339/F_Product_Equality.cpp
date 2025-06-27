#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;

ll mod[3] = {1000000007, 998244353, 1000000009};
string st[MAX];
class node{
public:
    ll v[3] = {};
    bool operator < (const node& ot) const{
        for(int i = 0;i < 3;i++){
            if(v[i] == ot.v[i]) continue;
            return v[i] < ot.v[i];
        }

        return 0;
    }
}; node arr[MAX];
map <node, ll> cnt;
ll now[3], result;

void run(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> st[i];
        now[0] = now[1] = now[2] = 0;

        for(auto& j : st[i]){
            for(int k = 0;k < 3;k++){
                now[k] *= 10;
                now[k] += j - '0';
                now[k] %= mod[k];
            }
        }

        for(int j = 0;j < 3;j++) arr[i].v[j] = now[j];
        cnt[arr[i]]++;
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            node cur;
            for(int k = 0;k < 3;k++){
                cur.v[k] = arr[i].v[k] * arr[j].v[k];
                cur.v[k] %= mod[k];
            }
            
            result += cnt[cur];
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}