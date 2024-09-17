#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
ll arr[3 * MAX], f[MAX], num[3 * MAX];

int main() {
	fastio;
    
    cin >> n;
    for(int i = 1; i <= 3 * n;i++){
        cin >> num[i];
        arr[num[i]]++;
        if(arr[num[i]] == 2) f[num[i]] = i;
    }
    
    sort(f + 1, f + n + 1);
    for(int i = 1; i <= n;i++) cout << num[f[i]] << " ";
    
    
    
	return 0;
}
