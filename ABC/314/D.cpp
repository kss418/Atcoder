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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
ll in[MAX];

char upper(char c){
    if(c <= 'z' && c >= 'a') return c - 'a' + 'A';
    return c;
}

char lower(char c){
    if(c <= 'Z' && c >= 'A') return c - 'A' + 'a';
    return c;
}

int main() {
    fastio;

    cin >> n >> s >> m;
    ll up = -1;
    vector <ll> num;

    while(m--){
        ll t, x; char c;
        cin >> t >> x >> c;

        if(t == 1){
            s[x - 1] = c;
            num.push_back(x - 1);
        }
        else if(t == 2){
            up = 0;
            num.clear();
        }
        else{
            up = 1;
            num.clear();
        }
    }

    for(auto& i : num) in[i] = 1;

    for(int i = 0;i < n;i++){
        if(in[i]) {
            cout << s[i]; continue;
        }

        if(up == -1) cout << s[i];
        else if(up) cout << upper(s[i]);
        else cout << lower(s[i]);
    }


    return 0;
}
