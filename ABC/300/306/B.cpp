#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 501;


int main() {
	fastio;
    
    ull result = 0;
    for(ll i = 0; i <= 63;i++){
        cin >> n;
        result += (1ull << i) * n;
    }
    
    cout << result;
    
    
	return 0;
}
