#include<bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned t = 1;
  unsigned n, a[100005];
  cin >> t;
  while (t--) {
    string First;
    cin >> n >> First;
    unsigned Flg = 0;
    for (unsigned i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] != i)
        ++Flg;
    }
    if (n == 2) {
      cout << "Alice\n";
      continue;
    }
    if (n == 3) {
      if ((Flg == 3 && First == "Alice") || (Flg == 2 && First == "Bob"))
        cout << "Bob\n";
      else
        cout << "Alice\n";
      continue;
    }
    if (Flg == 0 || (Flg == 2 && First == "Alice")) {
      cout << "Alice\n";
      continue;
    }
    cout << "Bob\n";
  }
  return 0;
}