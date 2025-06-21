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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501;
constexpr ll MOD = 998244353;
string st[MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue;
            ll cnt = 0;
            for(int k = 0;k < 4;k++){
                ll nx = j + dx[k];
                ll ny = i + dy[k];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(st[ny][nx] == '#') cnt ++;
            }

            if(cnt <= 1) continue;
            cout << i + 1 << " " << j + 1;
            return 0;
        }
    }


    return 0;
}
