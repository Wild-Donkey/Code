#include <cstdio>
#include <iostream>
using namespace std;
int l, n, a[5005], mi = 0, ma = 0;
int main() {
  cin >> l >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) mi = max(min(a[i], l - a[i] + 1), mi);
  for (int i = 1; i <= n; i++) ma = max(max(a[i], l - a[i] + 1), ma);
  cout << mi << " " << ma;
  return 0;
}