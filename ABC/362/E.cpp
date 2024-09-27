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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll arr[MAX], result[MAX];
map <pll, ll> cnt[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];

    for(int cur = 1;cur <= n;cur++){
        cnt[cur][{1, 0}] = 1; result[1]++;
        result[1] %= MOD;
        for(int pre = 1;pre < cur;pre++){
            ll diff = arr[cur] - arr[pre];
            cnt[cur][{2,diff}] += 1; result[2]++;
            result[2] %= MOD;
            cnt[cur][{2,diff}] %= MOD;

            for(int c = 3; c <= cur;c++){
                cnt[cur][{c,diff}] += cnt[pre][{c - 1,diff}] % MOD;
                result[c] += cnt[pre][{c - 1,diff}] % MOD;
                result[c] % MOD;
            }
        }
    }

    for(int i = 1;i <= n;i++) cout << result[i] % MOD << " ";    


    return 0;
}
