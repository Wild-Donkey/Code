#include <bits/stdc++.h>
using namespace std;
#define int int64_t
constexpr int maxn = 1e6 + 4;
int32_t  main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int n, m;
    cin >> n >> m;
    unsigned long long nm = (unsigned long long)n * m;
    if (__gcd(n, m) != 1) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    for (unsigned long long i = 1, I = 1; i <= n; ++i, I += m) cout << I % nm << " ";
    cout << '\n';
    for (unsigned long long i = 1, I = 1; i <= m; ++i, I += n) cout << I % nm << " ";
    cout << '\n';
    // set<unsigned> Se;
    // for (unsigned i = 1, I = 1; i <= n; ++i, I += m) {
    //   for (unsigned j = 1, J = 1; j <= m; ++j, J += n) {
    //     Se.insert(I * J % nm);
    //   }
    // }
    // cerr << (Se.size() == nm) << ' ' << Se.size() << '\n';
  }
  return 0;
}