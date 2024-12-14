#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class node{
public:
    string st;
    ll num() const{
        ll ret = 0;
        for(auto& i : st){
            ret += a[i - 'A' + 1];
        }
        return ret;
    }

    bool operator <(const node& ot) const{
        if(num() != ot.num()) return num() > ot.num();
        return st < ot.st;
    }
};
vector <node> arr;
vector <ll> num;

void bt(ll sz){
    if(num.size() == sz){
        string now;
        for(auto& i : num) now.push_back(i + 'A' - 1);
        node cur = {now};
        arr.push_back(cur);
        return;
    }

    for(int i = (num.empty() ? 1 : num.back() + 1);i <= 5;i++){
        num.push_back(i); 
        bt(sz);
        num.pop_back();
    }
}

int main() {
    fastio;

    for(int i = 1;i <= 5;i++) cin >> a[i];
    for(int i = 1;i <= 5;i++) bt(i); sort(all(arr));

    for(auto& i : arr) cout << i.st << "\n";

     
    return 0;
}
