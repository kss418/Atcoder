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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX], result[MAX];
priority_queue <pll, vector<pll>, greater<pll>> pq;
priority_queue <ll, vector <ll>, greater<ll>> q; 

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) q.push(i);

    for(int i = 1;i <= m;i++){
        ll t, w, s;
        cin >> t >> w >> s;
        ll cur = 0;

        while(!pq.empty() && pq.top().x <= t){
            q.push(pq.top().y); pq.pop();
        }

        if(!q.empty()){
            cur = q.top(); q.pop();
        }
        result[cur] += w;

        if(cur) pq.push({s + t, cur});
    }

    for(int i = 1;i <= n;i++) cout << result[i] << "\n";

  
    return 0;
}
