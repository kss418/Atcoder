#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
vector <int> arr[200001];
int seq = 0;
int l[200001], r[200001];


pair<int, int> dfs(int node, int pa) {
    int cnt = 0;
    for (auto nxt : arr[node]) {
        if (nxt != pa) {
            cnt++;
        }
    }

    if (!cnt) {
        seq++;
        l[node] = r[node] = seq;
        return { l[node],r[node] };
    }
    
    l[node] = 1e9;
    for (auto nxt : arr[node]) {
        if (nxt == pa) {
            continue;
        }

        pair<int, int> ret = dfs(nxt, node);
        l[node] = min(l[node], ret.first);
        r[node] = max(r[node], ret.second);
    } 

    return { l[node],r[node] };
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int st, en;
        cin >> st >> en;
        arr[st].push_back(en);
        arr[en].push_back(st);
    }

    dfs(1, -1);
    
    for (int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << "\n";
    }

    return 0;
}
