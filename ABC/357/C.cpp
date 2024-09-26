#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
char result[MAX][MAX];

void dc(ll x, ll y, ll level, ll flag){
    if(!level) {
        if(flag) result[x][y] = '#';
        else result[x][y] = '.';
        return;
    }
   
    ll pow = 1;
    for(int i = 1;i < level;i++) pow *= 3;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(i == 1 && j == 1) dc(x + pow * i, y + pow * j, level - 1, 0);
            else dc(x + pow * i, y + pow * j, level - 1, min<ll>(flag, 1));
        }
    }
}

int main() {
    fastio;

    cin >> n;
    dc(0, 0, n, 1);
    ll pow = 1;
    for(int i = 1;i <= n;i++) pow *= 3;
    for(int i = 0;i < pow;i++){
        for(int j = 0;j < pow;j++) cout << result[i][j];
         cout << "\n";
   }
    
    



    return 0;
}
