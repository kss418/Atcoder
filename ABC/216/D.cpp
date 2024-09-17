#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <ll> arr[MAX];
vector <ll> num[MAX];
deque <ll> q;
bool v[MAX];

int main() {
    fastio;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            arr[i].push_back(t);
        }
    }

    for (int i = 0; i < m; i++) {
        num[arr[i].back()].push_back(i);
        if (num[arr[i].back()].size() == 2) q.push_back(arr[i].back());
    }

    ll cnt = 0;
    while (!q.empty()) {
        ll cur = q.front(); q.pop_front();
        if (v[cur]) continue; v[cur] = 1; cnt++;

        for (auto& idx : num[cur]) {
            arr[idx].pop_back();
            if (arr[idx].empty()) continue;
            num[arr[idx].back()].push_back(idx);
        }

        for (auto& idx : num[cur]) {
            if (arr[idx].empty()) continue;
            if (num[arr[idx].back()].size() == 2) q.push_back(arr[idx].back());
        }
        
        num[cur].clear();
    }

    if (cnt == n) cout << "Yes";
    else cout << "No";
    

    return 0;
}
