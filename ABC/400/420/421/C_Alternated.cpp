#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> arr[2];

ll solve(ll cur){
    ll ret = 0, ac = 0, bc = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] - 'A' == ((i % 2) ^ cur)){
            if(s[i] == 'A'){
                ll lb = max(bc - (lower_bound(all(arr[1]), arr[0][ac]) - arr[1].begin()), 0ll);
                ret += max(arr[0][ac] + lb - i, 0ll); ac++;
            }
            else{
                ll lb = max(ac - (lower_bound(all(arr[0]), arr[1][bc]) - arr[0].begin()), 0ll);
                ret += max(arr[1][bc] + lb - i, 0ll); bc++;
            }

            continue;
        }

        if(s[i] == 'A'){
            ll lb = max(ac - (lower_bound(all(arr[0]), arr[1][bc]) - arr[0].begin()), 0ll);
            ret += max(arr[1][bc] + lb - i, 0ll); bc++;
        }
        else{
            ll lb = max(bc - (lower_bound(all(arr[1]), arr[0][ac]) - arr[1].begin()), 0ll);
            ret += max(arr[0][ac] + lb - i, 0ll); ac++;
        }
    }

    return ret;
}

void run(){
    cin >> n >> s;
    for(int i = 0;i < s.size();i++) arr[s[i] - 'A'].push_back(i);
    cout << min(solve(0), solve(1));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}