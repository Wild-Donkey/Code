#include<bits/stdc++.h>
using namespace std;
unsigned f[5005][5005];
unsigned Gcd[5005][5005];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned t = 1;
  cin >> t;
  for (unsigned i(0); i <= 5000; ++i) {
    Gcd[i][i] = i;
    for (unsigned j(0); j < i; ++j)
      Gcd[i][j] = __gcd(i, j);
  }
  for (unsigned i(0); i <= 5000; ++i)
    for (unsigned j(i + 1); j <= 5000; ++j)
      Gcd[i][j] = Gcd[j][i];
  while (t--) {
    unsigned long long a, b;
    unsigned Ans = 0x3f3f3f3f;
    cin >> a >> b;
    for (unsigned i = 0; i <= a; ++i) {
      memset(f[i], 0x3f, (a + 1) * sizeof(unsigned));
    }
    f[0][0] = 0;
    for (unsigned i = 0; i <= a; ++i) {
      for (unsigned j = 0; j <= a; ++j) {
        unsigned gTmp = (a - i) ? Gcd[a - i][(b - j) % (a - i)] : (b - j);
        if (gTmp + i <= a)
          f[i + gTmp][j] = min(f[i + gTmp][j], f[i][j] + 1);
        if (gTmp + j <= a)
          f[i][j + gTmp] = min(f[i][j + gTmp], f[i][j] + 1);
      }
    }
    // for (unsigned i = 0; i <= a; ++i) {
    //   for (unsigned j = 0; j <= a; ++j)
    //     cerr << f[i][j] << ' ';
    //   cerr << '\n';
    // }
    for (unsigned i = 0; i <= a; ++i) {
      Ans = min(Ans, f[a][i]);
    }
    cout << Ans + 1 << '\n';
  }
  return 0;
}
/*
2
3 4
12 20

114 514
*/