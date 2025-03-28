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
ll result;

int main() {
    fastio;

    cin >> s;
    for(int len = 1; len <= s.size();len++){
        for(int i = 0; i < s.size();i++){
            ll flag = 1;
            for(int j = 0;j < len;j++){
                if(s[i + j] != s[i + len - j - 1]) flag = 0;
            }

            if(flag) result = max<ll>(result, len);
        }
    }

    cout << result;

  
    return 0;
}
