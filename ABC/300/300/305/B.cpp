#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2020;



int main() {
	fastio;
    
    ll arr[7] = {0, 3, 4, 8, 9, 14, 23};
    char a, b;
    cin >> a >> b;
    cout << abs(arr[a - 'A'] - arr[b - 'A']);
    
    
    
	return 0;
}
