#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[MAX];
deque <ll> result;

int main() {
    fastio;

    cin >> n >> s;
    ll mul = n, sum = 0;
    for(int i = 0;i < n;i++){
        sum += (i + 1) * (s[i] - '0');
        cnt[mul] += sum; mul--;
    }

    for(int i = 1;i <= n + 100;i++){
        ll div = cnt[i] / 10;
        cnt[i] %= 10;
        cnt[i + 1] += div;
        result.push_front(cnt[i]);
    }

    while(!result.empty()){
        if(result.front()) break;
        result.pop_front();
    }
    
    for(auto& i : result) cout << i;


    return 0;
}

