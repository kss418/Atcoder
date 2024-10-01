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
string arr[MAX];
vector <ll> num[4][MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= 3;i++) cin >> arr[i];
    for(int i = 1;i <= 3;i++){
        for(int j = 0;j < n;j++) num[i][arr[i][j] - '0'].push_back(j);
    }
    ll result = INF;

    for(int i = 0;i <= 9;i++){
        vector <ll> per = {1, 2, 3};
        while(1){
            ll cur = -1, flag = 1;

            for(auto& now : per){
                auto nxt = upper_bound(all(num[now][i]), cur % n);
                if(nxt != num[now][i].end()){
                    cur += *nxt - (cur % n);
                    continue;
                }

                auto pre = upper_bound(all(num[now][i]), -1);
                if(pre != num[now][i].end()){
                    cur += n - (cur % n) + *pre;
                    continue;
                }
                flag = 0;
            }            

            if(flag) result = min(result, cur);
            if(!next_permutation(all(per))) break;
        }
    }

    if(result == INF) cout << -1;
    else cout << result;
    
  
    return 0;
}
