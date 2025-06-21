#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
stack <char> s;
int use[27];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string ch;
	cin >> ch;
	int flag = 1;

	for (int i = 0; i < ch.size(); i++) {
		if (!flag) {
			break;
		}

		if (ch[i] == ')') {
			while (1) {
				if (s.empty()) {
					flag = 0;
					break;
				}

				char cur = s.top();
				s.pop();
				if (cur == '(') {
					break;
				}
				else {
					use[cur - 'a'] = 0;
				}
			}
		}

		else {
			s.push(ch[i]);
			if (ch[i] == '(') {
				continue;
			}
			else if (use[ch[i] - 'a']) {
				flag = 0;
				break;
			}
			use[ch[i] - 'a'] = 1;
		}
	}


	if (flag) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

	return 0;
}

