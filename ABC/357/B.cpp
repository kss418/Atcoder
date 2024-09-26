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


int main() {
    fastio;

    cin >> s;
    ll low = 0, up = 0;
    for(auto& i : s){
        if(i >= 'a' && i <= 'z') low++;
        else up++;
    }

    if(up > low){
        for(auto& i : s){
            if(i >= 'a' && i <= 'z') cout << (char)(i - 'a' + 'A');
            else cout << i;
        }
    }
    else{
        for(auto& i : s){
            if(i >= 'a' && i <= 'z') cout << i;
            else cout << (char)(i - 'A' + 'a');
        }
    }


    return 0;
}
