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
vector <ll> a, b;
ll mod[3] = { MOD, 998244353, 922337203685471 };
ll key[3] = {29, 31, 26};
ll p[MAX];

vector <ll> h(vector <ll> arr, ll cur){
    vector <ll> ret;
    for(int i = 1;i < MAX;i++) p[i] = (p[i - 1] % mod[cur] * key[cur]) % mod[cur];
    ret.resize(n + 1);

    for(int i = 1;i <= n;i++){
        ret[i] = (ret[i - 1] % mod[cur] + p[arr[i]]) % mod[cur];
    }

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    a.resize(n + 1); b.resize(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    p[0] = 1;
    vector <ll> sa[3], sb[3];
    for(int i = 0;i < 3;i++) {
        sa[i] = h(a, i); sb[i] = h(b, i);
    }

    while(m--){
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        ll flag = 1;
        for(int i = 0;i < 3;i++){
            ll a = (sa[i][r1] - sa[i][l1 - 1] + mod[i]) % mod[i];
            ll b = (sb[i][r2] - sb[i][l2 - 1] + mod[i]) % mod[i];
            if(a != b) flag = 0;
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}
