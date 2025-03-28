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
constexpr ll MAX = 201;
constexpr ll MOD = 998244353;
string st[MAX];

class node{
public:
    ll idx, win;
    bool operator < (node& ot){
        if(win == ot.win) return idx < ot.idx;
        return win > ot.win;
    }
};
vector <node> result;

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < 2 * n;i++) cin >> st[i];
    for(int i = 0;i < 2 * n;i++) result.push_back({i, 0});
    sort(all(result));

    for(int j = 0;j < m;j++){
        for(int i = 0;i < 2 * n;i += 2){
            char pre = st[result[i].idx][j];
            char nxt = st[result[i + 1].idx][j];

            if(pre == 'G' && nxt == 'C'){
                result[i].win++;
            }
            else if(pre == 'C' && nxt == 'P'){
                result[i].win++;
            }
            else if(pre == 'P' && nxt == 'G'){
                result[i].win++;
            }

            if(nxt == 'G' && pre == 'C'){
                result[i + 1].win++;
            }
            else if(nxt == 'C' && pre == 'P'){
                result[i + 1].win++;
            }   
            else if(nxt == 'P' && pre == 'G'){
                result[i + 1].win++;
            }
        }  

        sort(all(result));
    }

    for(auto& i : result) cout << i.idx + 1 << '\n';
    

    return 0;
}
