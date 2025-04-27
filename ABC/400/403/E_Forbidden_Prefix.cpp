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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll seq[2], result;
ll use[MAX][2];
ll adj[MAX][26][2];

void erase(ll cur, ll cnt){
    if(use[cur][cnt] > 0){
        result -= use[cur][cnt];
        use[cur][cnt] = 0;
    }

    for(int i = 0;i < 26;i++){
        if(adj[cur][i][cnt]) erase(adj[cur][i][cnt], cnt);
    }
}

void run(){
    cin >> n; 
    while(n--){
        ll op; cin >> op >> s;
        if(op == 1){
            ll cur = 0, flag = 1;
            for(auto& i : s){
                if(!adj[cur][i - 'a'][1]) flag = 0;
                else cur = adj[cur][i - 'a'][1];
            }   
            if(flag) erase(cur, 1);

            cur = 0;
            for(auto& i : s){
                if(!adj[cur][i - 'a'][0]) adj[cur][i - 'a'][0] = ++seq[0];
                cur = adj[cur][i - 'a'][0];
            }
            use[cur][0]++;
        }
        else{
            ll cur = 0, flag = 1;
            for(auto& i : s){
                if(!adj[cur][i - 'a'][0]) break;
                cur = adj[cur][i - 'a'][0];
                if(use[cur][0]) flag = 0;
            }

            if(flag){
                ll cur = 0;
                for(auto& i : s){
                    if(!adj[cur][i - 'a'][1]) adj[cur][i - 'a'][1] = ++seq[1];
                    cur = adj[cur][i - 'a'][1];
                }
                use[cur][1]++; result++;
            }
        }

        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

