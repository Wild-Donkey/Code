#include <bits/stdc++.h>
using namespace std;
#define int int64_t
constexpr int maxn = 1e6 + 4;
unsigned a[1000005];
int32_t  main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    unsigned n, m;
    cin >> n >> m;
    a[0] = 1 - m;
    for (unsigned i(1); i <= n; ++i)
      a[i] = a[i - 1] + m;
    for (unsigned i(1); i < n * m; ++i) {
      printf("%3u: ", i);
      for (unsigned j(1); j <= n; ++j) {
        printf("%3u", i * a[j] % (n * m));
      }
      putchar(0x0A);
    }
  }
  return 0;
}