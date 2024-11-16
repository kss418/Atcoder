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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> arr;

int main() {
    fastio;

    cin >> n >> m >> s;
    ll cnt = 0;
    for(auto& i : s){
        if(cnt > 0 && i == '0') arr.push_back(cnt), cnt = -1;
        else if(cnt < 0 && i == '1') arr.push_back(cnt), cnt = 1;
        else if(i == '0') cnt--;
        else cnt++;
    }
    arr.push_back(cnt);

    ll seq = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] > 0) seq++;
        if(seq != m) continue;
        swap(arr[i], arr[i - 1]); break;
    }

    for(auto& i : arr){
        if(i > 0) for(int j = 1;j <= i;j++) cout << '1';
        else for(int j = 1;j <= -i;j++) cout << '0';
    }


    return 0;
}

