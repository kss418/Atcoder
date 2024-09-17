#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 1e9 + 7;

int main() {
    fastio;

    char a, b, c;
    cin >> a >> b >> c;
    if (a == '<' && c == '<') cout << "B";
    else if (c == '>' && a == '>') cout << "B";
    else if (a == '>' && b == '<') cout << "A";
    else if (a == '<' && b == '>') cout << "A";
    else cout << "C";


    return 0;
} 
