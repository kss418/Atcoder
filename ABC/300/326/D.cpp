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
constexpr ll MAX = 5; // SET MAX SIZE
constexpr ll MOD = 998244353;
string r, c;
ll cr[MAX][3], cc[MAX][3], flag;
vector <ll> vec;
vector <ll> rv[MAX], cv[MAX];
char result[MAX][MAX];

bool chk(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 3;j++){
            if(!cr[i][j]) return 0;
            if(!cc[i][j]) return 0;
        }
    }

    return 1;
}

void bt(){
    ll cur = vec.size();
    if(flag) return;
    if(vec.size() == n * n){
        if(!chk()) return;
        for(int i = 0;i < vec.size();i++){
            ll cy = i / n, cx = i % n;
            result[cy][cx] = (vec[i] == 3 ? '.' : 'A' + vec[i]);
        }
        flag = 1; return;
    }

    for(int i = 0;i < 4;i++){
        ll cy = cur / n, cx = cur % n;
        if(i != 3 && rv[cy].empty() && r[cy] != i + 'A') continue;
        if(i != 3 && cv[cx].empty() && c[cx] != i + 'A') continue;
        if(i != 3 && (cr[cy][i] || cc[cx][i])) continue;
    
        if(i != 3) cr[cy][i]++, cc[cx][i]++;
        if(i != 3) rv[cy].push_back(i), cv[cx].push_back(i);
        vec.push_back(i);
        bt();
        vec.pop_back();
        if(i != 3) rv[cy].pop_back(), cv[cx].pop_back();
        if(i != 3) cr[cy][i]--, cc[cx][i]--;
    }
}

void run(){
    cin >> n >> r >> c; bt();
    if(!flag){ cout << "No"; return; }
    
    cout << "Yes\n";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cout << result[i][j];
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
