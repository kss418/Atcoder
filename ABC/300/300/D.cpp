#include <bits/stdc++.h>
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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;

class _es {
public:
    ll n; vector <ll> p, pn;
    _es(ll n) {
        this->n = n;
        p.resize(n + 1, -1);
    }

    void init() {
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i] != -1) continue; p[i] = i;
            pn.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                if (p[j] == -1) p[j] = i;
            }
        }
    }

    ll mp(ll n) { // 최소 소인수 반환
        return p[n];
    }

    vector<ll> ret() { // 소수 벡터 반환
        return pn;
    }

    bool prime(ll n) { // 소수 판별
        if (n == 1) return 0;
        return p[n] == n;
    }
};

int main() {
    fastio;

    cin >> n; _es es(MAX); es.init();
    vector <ll> p = es.ret();

    ll result = 0;
    for(int i = 0;i < p.size();i++){
        ll a = p[i]; if(a * a * a * a * a > n) break; 
        for(int j = i + 1;j < p.size();j++){
            ll b = p[j]; if(a * a * b * b * b > n) break;
            for(int k = j + 1;k < p.size();k++){
                ll c = p[k]; if(a * a * b * c * c > n) break;
                result++;
            }
        }
    }
    
    cout << result;


    return 0;
}
