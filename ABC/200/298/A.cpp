#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;


int main() {
	fastio;
	
    cin >> n >> s;
    int chk1 = 0, chk2 = 0;
    for(auto i : s){
        if(i == 'o'){
            chk1 = 1;
        }
        else if(i == 'x'){
            chk2 = 1;
        }
    }
    
    if(chk2 || !chk1) cout << "No";
    else cout << "Yes";
    
    
	return 0;
}
