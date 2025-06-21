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
ll arr[MAX][MAX];
vector <pll> num[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> m;
        for(int j = 1;j <= m;j++) {
            cin >> arr[i][j];
            num[arr[i][j]].push_back({m, i});
        }
    }
    cin >> k;
    sort(all(num[k]));
    
    vector <ll> result;
    if(!num[k].empty()){
        ll mn = num[k][0].first;
        for(auto& i : num[k]) {
            if(i.x != mn) continue;
            result.push_back(i.y);
        }
    }
    sort(all(result));

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";


    return 0;
}
