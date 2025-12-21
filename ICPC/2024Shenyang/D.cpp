#include <bits/stdc++.h>
using namespace std;
#define int int64_t
constexpr int maxn = 5e5 + 4;
struct fwt {
  int c[maxn];
  int n;
  void clear(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i)
      c[n] = 0;
  }
  int lowbit(int x) {
    return x & (-x);
  }
  void add(int x, int v) {
    while (x <= n) {
      c[x] += v;
      x += lowbit(x);
    }
  }
  int getsum(int x) {
    int res = 0;
    while (x) {
      res += c[x];
      x -= lowbit(x);
    }
    return res;
  }
} as, bs;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T-- > 0) {
    int n;
    cin >> n;
    as.clear(n), bs.clear(n);
    int od = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      od ^= ((as.getsum(x)) & 1);
      as.add(x, 1);
    }
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      od ^= ((bs.getsum(x)) & 1);
      bs.add(x, 1);
    }
    cout << (od ? 'A' : 'B');
    for (int i = 1; i < n; ++i) {
      string t;
      int l, r, d;
      cin >> t >> l >> r >> d;
      l = r - l + 1;
      d %= l;
      od ^= (d * (l - d)) & 1;
      cout << (od ? 'A' : 'B');
    }
    cout << endl;
  }
  return 0;
}