#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;

multiset <int> box[MAX];
set <int> number[MAX];


int main() {
	fastio;
	
    cin >> n >> m;
    while(m--){
        ll num, a, b;
        cin >> num;
        if(num == 1){
            cin >> a >> b;
            box[b].insert(a);
            number[a].insert(b);
        }
        else if(num == 2){
            cin >> a;
            for(auto i : box[a]) cout << i << " ";
            cout << '\n';
        }
        else{
            cin >> a;
            for(auto i : number[a]) cout << i << " ";
            cout << '\n';
        }
    }
    
    
    
	return 0;
}
