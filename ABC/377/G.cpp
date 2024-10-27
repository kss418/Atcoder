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
string st[MAX];
ll result;

class _trie { // 0-based index
public:
    ll n, m, seq = 2;
    vector <vector<ll>> adj;
    vector <ll> chk;

    _trie(ll k, ll n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
       this->m = m; this->n = n; 
       chk.resize(n * k + 1, INF); adj.resize(n * k + 1);
    }

    void insert(string& s){
        ll cur = 1;
        for(int i = 0;i < s.size();i++){
            char st = s[i];
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) adj[cur][st - 'a'] = seq++;
            cur = adj[cur][st - 'a'];
            chk[cur] = min<ll>(s.size() - i, chk[cur]);
        }
    }

    void erase(string& s){
        ll cur = 1;
        for(auto &st : s){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) return;
            cur = adj[cur][st - 'a'];
        }
        chk[cur] = 0;
    }

    ll find(string& s){
        ll cur = 1;
        for(int i = 0;i < s.size();i++){
            char st = s[i];
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) return INF;
            cur = adj[cur][st - 'a'];
            result = min<ll>(result, chk[cur] + s.size() - i - 2);
        }
        return chk[cur];
    }
};

int main() {
    fastio;

    cin >> n; _trie trie(MAX, 1);
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        string cur = st[i]; 
        result = INF; trie.find(st[i]);
        result = min<ll>(result, st[i].size());
        
        cout << result << "\n";  
        trie.insert(st[i]);
    }


    return 0;
}
