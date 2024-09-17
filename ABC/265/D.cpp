#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;
set <ll> arr;
ll sum;
 
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
 
 
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
  	arr.insert(0);
    for (int i = 1; i <= n; i++) {
        ll num;
        cin >> num;
        sum += num;
        arr.insert(sum);
    }
    
 
    int flag = 0;
    for (auto i : arr) {
        if (arr.find(i + p) != arr.end() && arr.find(i + p + q) != arr.end() && arr.find(i +p + q + r) != arr.end()) {
            cout << "Yes";
            return 0;
        }
    }
 
    cout << "No";
 
 
 
    return 0;
}
