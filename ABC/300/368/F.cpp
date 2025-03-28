#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll arr[MAX], num[MAX];


int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    num[1] = 0;
    for(int i = 2;i < MAX;i++){
        num[i] = 1;
        vector <ll> arr; 
        for(int j = 2;j * j <= i;j++){
            if(i % j) continue;
            arr.push_back(num[j]);
            if(j * j != i) arr.push_back(num[i / j]);
        }
        sort(all(arr));
        for(auto& j : arr) if(j == num[i]) num[i]++;
    }

    ll result = 0;
    for(int i = 1;i <= n;i++) result ^= num[arr[i]];

    if(result) cout << "Anna";
    else cout << "Bruno";


    return 0;
}
