#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;
int dp[200001];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    stack <pair<int,int>> s;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        int flag = 0;
        if (!s.empty() && s.top().first == num) {
            dp[i] = dp[s.top().second] + 1;
            if (dp[i] == num) {
                flag = 1;
                while (!s.empty() && s.top().first == dp[i]) {
                    s.pop();
                }
            }
        }
        else {
            dp[i] = 1;
        }
        
        
        s.push({ num,i });
        if (flag) {
            s.pop();
        }
        
       
        cout << s.size() << "\n";
    }
    
    

    return 0;
}
