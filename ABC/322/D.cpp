#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 4; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[3][MAX];
bool result, board[MAX][MAX];

class node{
public:
    ll dy, dx, rot;
};
vector <node> arr;

void rot(ll cur, ll cnt){
    string tmp[MAX];
    for(int t = 0;t < cnt;t++){
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++) tmp[j][4 - i - 1] = st[cur][i][j];
        }

        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++) st[cur][i][j] = tmp[i][j];
        }
    }
}

bool outrange(ll cur, ll dy, ll dx, ll dr){
    rot(cur, dr); bool ret = 0;
    for(int i = 0;i < 4;i++){
        if(ret) break; 
        for(int j = 0;j < 4;j++){
            if(st[cur][i][j] != '#') continue;
            if(i + dy >= 4 || i + dy < 0 || j + dx >= 4 || j + dx < 0){
                ret = 1; break;
            }

            if(!board[i + dy][j + dx]) continue;
            ret = 1; break;
        }
    }
    
    rot(cur, 4 - dr);
    return ret;
}

void draw(ll cur, ll dy, ll dx, ll dr, ll num){
    rot(cur, dr);
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(st[cur][i][j] != '#') continue;
            board[i + dy][j + dx] = num;
        }
    }

    rot(cur, 4 - dr);
}

bool chk(){
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(!board[i][j]) return 0;
        }
    }
    return 1;
}

void bt(){
    if(result) return;
    if(arr.size() == 3){ 
        if(chk()) result = 1; 
        return; 
    }

    for(int i = -3;i < 4;i++){
        for(int j = -3;j < 4;j++){
            for(int k = 0;k < 4;k++){
                if(outrange(arr.size(), i, j, k)) continue;
                draw(arr.size(), i, j, k, 1);
                arr.push_back({i, j, k});
                bt();
                arr.pop_back();
                draw(arr.size(), i, j, k, 0);
            }
        }
    }
}

void run(){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 4;j++) cin >> st[i][j];
    }

    bt();
    cout << (result ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

