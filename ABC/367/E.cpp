#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], num[MAX];

class _st {
public:
    ll n; vector <vector<ll>> num;
    _st(ll n, ll m) { //n 개수 m 깊이
        this->n = n;
        num.resize(n + 1, vector<ll>(log2(m + 1) + 1, 0));
    }

	void add(ll st, ll en) { // 간선 삽임
		num[st][0] = en;
	}

	void init() { 
		for (int i = 1; i <= log2(m); i++) {
			for (int j = 1; j <= n; j++) num[j][i] = num[num[j][i - 1]][i - 1];
		}
	}

	ll ret(ll n, ll d) { //n 노드 d 깊이
		for (int i = log2(m); i >= 0; i--) {
			if (d & (1ll << i)) n = num[n][i];
		}
		
		return n;
	}
};


int main()
{
    fastio;
    cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) cin >> num[i];

	_st st(n, 1e18);
	for (int i = 1; i <= n; i++) st.add(i, arr[i]);
	st.init();

	for (int i = 1; i <= n; i++) cout << num[st.ret(i, m)] << " ";


    return 0;
}
