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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
vector <pair <string, ll>> arr;
ll result[MAX], cnt;

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> s;
        arr.push_back({s, i});
    }
    sort(all(arr));

    for(int i = 1;i < n;i++){
        string pre = arr[i - 1].x, cur = arr[i].x;
        ll cnt = 0;
        while(cnt < min<ll>(pre.size(), cur.size())){
            if(pre[cnt] != cur[cnt]) break; cnt++;
        }

        result[arr[i].y] = max<ll>(result[arr[i].y], cnt);
        result[arr[i - 1].y] = max<ll>(result[arr[i - 1].y], cnt);
    }

    for(int i = 0;i < n;i++) cout << result[i] << "\n";


    return 0;
}
