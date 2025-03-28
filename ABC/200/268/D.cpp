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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
map <string, bool> ban;
vector <string> arr;
ll sum, use, able; vector <ll> num;

void bt(){
    if(use < 0 || able) return;
    if(num.size() == n - 1){
        string cur = arr[0];
        for(int i = 0;i < n - 1;i++){
            for(int j = 1;j <= num[i];j++) cur += "_";
            cur += arr[i + 1];
        }

        if(cur.size() < 3 || cur.size() > 16) return;
        if(ban[cur]) return;
        able = 1; cout << cur << "\n"; return;
    }

    for(int i = 1;i <= use;i++){
        num.push_back(i); use -= i;
        bt();
        num.pop_back(); use += i;
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        string st; cin >> st;
        arr.push_back(st);
        sum += st.size();
    }
    sort(all(arr));
    
    while(m--){
        string st; cin >> st;
        ban[st] = 1;
    }

    if(16 - sum - (n - 1) < 0){
        cout << -1; return 0;
    }

    while(1){
        use = 16 - sum; bt();
        if(able) return 0;
        if(!next_permutation(all(arr))) break;
    }

    cout << -1;

    
    return 0;
}
