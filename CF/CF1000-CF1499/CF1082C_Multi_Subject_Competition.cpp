#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
vector<int> a[100005];
int Ans[100005], AnsS(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) A = RD(), a[A].push_back(10000 - RDsg());
  for (unsigned i(1); i <= m; ++i)
    if (a[i].size()) {
      sort(a[i].begin(), a[i].end()), a[i][0] = 10000 - a[i][0];
      if (a[i][0] > 0) Ans[0] += a[i][0];
      for (unsigned j(1); j < a[i].size(); ++j) {
        a[i][j] = a[i][j - 1] + 10000 - a[i][j];
        if (a[i][j] > 0) Ans[j] += a[i][j];
      }
    }
  for (unsigned i(0); i <= n; ++i) AnsS = max(Ans[i], AnsS);
  printf("%d\n", AnsS);
  return Wild_Donkey;
}