#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n(1), m;
unsigned f[100005], a[100005];
int main() {
  while (cin >> a[n]) ++n;
  --n, memset(f, 0x3f, (n + 2) << 2), f[0] = 0;
  for (unsigned i(n); i; --i) {
    unsigned Tmp(upper_bound(f, f + n + 1, a[i]) - f);
    if (a[i] >= f[Tmp - 1]) f[Tmp] = a[i];
  }
  for (unsigned i(n); i; --i)
    if (f[i] < 0x3f3f3f3f) {
      cout << i << endl;
      break;
    }
  memset(f, 0x3f, (n + 2) << 2), f[0] = 0;
  for (unsigned i(1); i <= n; ++i) {
    unsigned Tmp(lower_bound(f, f + n + 1, a[i]) - f);
    if (a[i] >= f[Tmp - 1]) f[Tmp] = a[i];
  }
  for (unsigned i(n); i; --i)
    if (f[i] < 0x3f3f3f3f) {
      cout << i << endl;
      return 0;
    }
}
