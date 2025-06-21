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
ll a[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;
deque <ll> wait, que;

int main() {
    fastio;

    ll q; cin >> q;
    while(q--){
        ll num, x; cin >> num;
        if(num == 1) {
            cin >> x; que.push_back(x);
            wait.push_back(x);
        }
        else if(num == 2){
            if(!pq.empty()) {
                cout << pq.top() << "\n"; pq.pop();
            }
            else{
                cout << que.front() << "\n";
                que.pop_front(); wait.pop_front();
            }
        }
        else {
            while(!wait.empty()) { 
                pq.push(wait.back()); wait.pop_back();
            } 
            que.clear();
        }
    }
    

    return 0;
}
