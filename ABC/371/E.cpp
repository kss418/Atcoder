#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], la[MAX], cur, result;


int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; 
        if (arr[i] != arr[i - 1]) cur += i - la[arr[i]];
        else cur++;
    
        la[arr[i]] = i; result += cur;
    }
   
    cout << result;


    return 0;
}
