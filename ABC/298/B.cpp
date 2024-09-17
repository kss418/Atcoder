#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101;

ll orig[MAX][MAX], ret[MAX][MAX];

void trans(){
    ll temp[MAX][MAX];
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            temp[i][j] = orig[n - j + 1][i];
        }
    }
    
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            orig[i][j] = temp[i][j];
        }
    }
}

int main() {
	fastio;
	
    cin >> n;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            cin >> orig[i][j];
        }
    }
    
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            cin >> ret[i][j];
        }
    }
    
    t = 4;
    while(t--){
        ll flag = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1; j <= n;j++){
                if(!orig[i][j]) continue;
                if(!ret[i][j]) flag = 0;
                if(!flag) break;
            }
        }
        
        if(flag) {
            cout << "Yes";
            return 0;
        }
        trans();
    }
    
    cout << "No";
    
    
    
	return 0;
}
