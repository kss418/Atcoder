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
pll arr[MAX];
ll sum[MAX], idx, sig, mn;
ll result[MAX];
bool flag;
vector <ll> num;

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {       
        ll vote = k - sig;
        vote -= cur - arr[idx].x;
        ll r = upper_bound(all(num), cur) - num.begin();
        ll l = n - m + 1 - flag;
        if(r >= l)vote -= (r - l + 1) * (cur + 1) - (sum[r] - sum[l - 1]);
        if(flag) vote += cur + 1 - arr[idx].x;

        if(vote < 0) return 1;
        return 0;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo - 1) >> 1;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};


int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        cin >> arr[i].x;
        arr[i].y = i;
        sig += arr[i].x;
    }

    if(n == m){
        for(int i = 1;i <= n;i++) cout << 0 << " ";
        return 0;
    }
    
    sort(arr + 1, arr + n + 1);
    for(int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + arr[i].x;
        num.push_back(arr[i].x);
    }
    sort(all(num));

    for(int i = 1;i <= n;i++){
        if(i > n - m) flag = 1;
        idx = i;
        _bs bs(arr[i].x, arr[i].x + k - sig + 1);
        ll num = bs.ret();
        if(num == arr[i].x + k - sig + 1) result[arr[i].y] = -1;
        else result[arr[i].y] = num - arr[i].x;
    }
    
    for(int i = 1;i <= n;i++) cout << result[i] << " ";
    
  
    return 0;
}
