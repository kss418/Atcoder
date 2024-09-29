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
constexpr ll MAX = 21;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];
ll dp[1 << MAX];
vector <ll> same[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(a[i] != a[j] && b[i] != b[j]) continue;
            same[i].push_back(j);
        }
    }
    dp[0] = 0;

    for(int i = 1;i <= (1 << n) - 1;i++){
        vector <ll> cur;
        for(int j = 0;j < n;j++){
            if((i & (1 << j)) == 0) continue;
            for(auto &k : same[j + 1]){
                if((i & (1 << (k - 1))) == 0) continue;
                ll a = (i & (~(1 << j)));
                ll b = (i & (~(1 << (k - 1))));
                cur.push_back(dp[a & b]);
            }
        }
        sort(all(cur));
        ll num = 0;
        for(auto& j : cur) if(j == num) num++;

        dp[i] = num;
    }

    if(!dp[(1 << n) - 1]) cout << "Aoki";
    else cout << "Takahashi";

  
    return 0;
}
