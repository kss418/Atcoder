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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX];
map <ll, ll> num;

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> arr[i];

    num[0] = 1;
    ll sum = 0, cnt = 1;
    for(int i = 1;i <= n;i++){
        sum += arr[i];
        ll ban = sum - m;
        ll cur = (cnt - num[ban] + MOD) % MOD;
        num[sum] += cur; cnt += cur;
        num[sum] %= MOD; cnt %= MOD;

        if(i == n) cout << cur % MOD;
    }


    return 0;
}
