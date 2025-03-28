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
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
ll mg[MAX][MAX], mh[MAX][MAX], d[MAX][MAX];

int main() {
    fastio;

    cin >> n;
    cin >> m;
    while (m--) {
        ll st, en;
        cin >> st >> en;
        st--; en--;
        mg[st][en] = 1;
        mg[en][st] = 1;
    }

    cin >> m;
    while (m--) {
        ll st, en;
        cin >> st >> en;
        st--; en--;
        mh[st][en] = 1;
        mh[en][st] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) cin >> d[i][j];
    }

    vector <ll> per;
    for (int i = 0; i < n; i++) per.push_back(i);
    ll result = INF;

    while (1) {
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mg[per[i]][per[j]] == mh[i][j]) continue;
                cur += d[i][j];
            }
        }

        result = min(result, cur);
        if (!next_permutation(all(per))) break;
    }

    cout << result;


    return 0;
}
