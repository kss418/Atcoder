#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 301010;
ll arr[MAX], num[MAX], dp[MAX][2];


int main() {
	fastio;
    
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> num[i] >> arr[i];
        if(num[i]){
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
        }
        else{
            dp[i][1] = max(max(dp[i - 1][0], dp[i - 1][1]) + arr[i], dp[i - 1][1]);
            dp[i][0] = dp[i - 1][0];
        }
    }
    
    cout << max(dp[n][0], dp[n][1]);
    
    
    
    
	return 0;
}
