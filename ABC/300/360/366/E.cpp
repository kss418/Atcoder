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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
constexpr ll si = 4010101;
pll arr[MAX];
ll cx[si], cy[si], dx[si], dy[si], nx[si], ny[si];
vector <ll> x, y;

int main() {
    fastio;

    ll mid = 2000001;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i].x >> arr[i].y;
        cx[arr[i].x + mid]++; cy[arr[i].y + mid]++;
    }

    dx[-2000001 + mid] = n; dy[-2000001 + mid] = n;
    for(int i = -2000000;i <= 2000001;i++){
        dx[i + mid] = dx[i - 1 + mid] - 2 * cx[i + mid];
        dy[i + mid] = dy[i - 1 + mid] - 2 * cy[i + mid];
    }

    for(int i = 1;i <= n;i++) {
        nx[-2000001 + mid] += abs(arr[i].x + 2000001);
        ny[-2000001 + mid] += abs(arr[i].y + 2000001);
    }

    for(int i = -2000000;i <= 2000001;i++){
        nx[i + mid] = nx[i - 1 + mid] - dx[i + mid - 1];
        if(nx[i + mid] <= m) x.push_back(nx[i + mid]);

        ny[i + mid] = ny[i - 1 + mid] - dy[i + mid - 1];
        if(ny[i + mid] <= m) y.push_back(ny[i + mid]);
    }
    sort(all(y));

    ll result = 0;
    for(auto& i : x){
        result += --upper_bound(all(y), m - i) - y.begin() + 1;
    }

    cout << result;
    

    return 0;
}
