#include<iostream>
#include<cstring> 
#include<stack>
using namespace std;
string s;
int main() {
	cin >> s;
	int len = s.length(), a[305];
	stack<int> sta;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
			a[i] = 1;
		else if (s[i] == ')')
			a[i] = 2;
		else
			a[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		if (a[i] == 1) {
			sta.push(i);
		}
		else if (a[i] == 2)
		{
			if (sta.empty()) {
				if (i == (len - 1)) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
				return 0;
			}
			else {
				sta.pop();
			}
		}
	}
	if (sta.empty()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}