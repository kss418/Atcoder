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
constexpr ll MAX = 31;
constexpr ll MOD = 998244353;
string a[MAX], b[MAX];

int main() {
    fastio;

    cin >> n >> m; 
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ll flag = 1;
            for(int cy = 0;cy < n;cy++){
                for(int cx = 0;cx < m;cx++){
                    ll ny = (cy + i) % n, nx = (cx + j) % m;
                    if(a[ny][nx] != b[cy][cx]) {
                        flag = 0; break;
                    }
                }
            }

            if(flag){
                cout << "Yes"; return 0;
            }
        }
    }

    cout << "No";


    return 0;
}
