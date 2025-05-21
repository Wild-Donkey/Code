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
unsigned A, B, C, D;
unsigned m, n, t, Ans;
unsigned a[500005], b[500005], Tmpa[500005], Tmpb[500005], Prea[500005],
    Preb[500005];
inline void Clr() {}
char Go(unsigned nn, unsigned mm) {
  // printf("Go %u %u\n", nn, mm);
  // for (unsigned i(1); i <= nn; ++i) printf("%u ", Tmpa[i]);
  // putchar(0x0A);
  // for (unsigned i(1); i <= mm; ++i) printf("%u ", Tmpb[i]);
  // putchar(0x0A);
  Prea[0] = 0x3f3f3f3f, Preb[0] = 0;
  vector<pair<unsigned, unsigned> > Rsa, Rsb;
  unsigned Last(Tmpa[1]);
  Prea[1] = Tmpa[1], Rsa.push_back({1, Last});
  for (unsigned i(2); i <= nn; ++i) {
    Prea[i] = min(Prea[i - 1], Tmpa[i]);
    if (Tmpa[i] > Last) Rsa.push_back({i, Last = Tmpa[i]});
  }
  Last = 0x3f3f3f3f;
  for (unsigned i(1); i <= mm; ++i) {
    Preb[i] = max(Preb[i - 1], Tmpb[i]);
    if (Tmpb[i] < Last) Rsb.push_back({i, Last = Tmpb[i]});
  }
  unsigned Sa(Rsa.size()), Sb(Rsb.size());
  while (nn && mm) {
    if (Preb[mm] < Rsa[Sa - 1].second) {
      nn = Rsa[Sa - 1].first - 1, --Sa;
      continue;
    }
    if (Prea[nn] > Rsb[Sb - 1].second) {
      mm = Rsb[Sb - 1].first - 1, --Sb;
      continue;
    }
    return 0;
  }
  return 1;
}
char Solve() {
  // printf("Solve %u %u\n", n, m);
  unsigned *aa(a), *bb(b), mm(m), nn(n);
  if (aa[1] == bb[1]) return 0;
  if (aa[1] < bb[1]) swap(aa, bb), swap(mm, nn);
  unsigned Mxa(0), Mxb(0), Mna(0x3f3f3f3f), Mnb(0x3f3f3f3f);
  for (unsigned i(1); i <= nn; ++i)
    Mxa = max(Mxa, aa[i]), Mna = min(Mna, aa[i]);
  for (unsigned i(1); i <= mm; ++i)
    Mxb = max(Mxb, bb[i]), Mnb = min(Mnb, bb[i]);
  if (Mxa <= Mxb || Mna <= Mnb) return 0;
  unsigned La, Lb;
  char Rt(1);
  for (La = 1; aa[La] < Mxa; ++La) Tmpa[La] = aa[La];
  for (Lb = 1; bb[Lb] > Mnb; ++Lb) Tmpb[Lb] = bb[Lb];
  --La, --Lb;
  if (La && Lb) Rt &= Go(La, Lb);
  for (La = 1; aa[nn - La + 1] < Mxa; ++La) Tmpa[La] = aa[nn - La + 1];
  for (Lb = 1; bb[mm - Lb + 1] > Mnb; ++Lb) Tmpb[Lb] = bb[mm - Lb + 1];
  --La, --Lb;
  if (La && Lb) Rt &= Go(La, Lb);
  return Rt;
}
signed main() {
  // freopen("P9870_3.in", "r", stdin);
  // freopen("P9870.out", "w", stdout);
  RD(), n = RD(), m = RD(), t = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i) b[i] = RD();
  for (unsigned T(0); T <= t; ++T) {
    unsigned En, Em;
    vector<pair<unsigned, unsigned> > Ea, Eb;
    if (T) {
      En = RD(), Em = RD();
      for (unsigned i(0); i < En; ++i)
        A = RD(), B = RD(), Ea.push_back({A, B}), swap(a[A], Ea[i].second);
      for (unsigned i(0); i < Em; ++i)
        A = RD(), B = RD(), Eb.push_back({A, B}), swap(b[A], Eb[i].second);
    }
    // if (T == 3) {
    // printf("Cur %u %u %u\n", T, Ea.size(), Eb.size());
    // for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]);
    // putchar(0x0A);
    // for (unsigned i(1); i <= m; ++i) printf("%u ", b[i]);
    // putchar(0x0A);
    // }
    putchar('0' + Solve());
    if (T) {
      for (auto i : Ea) a[i.first] = i.second;
      for (auto i : Eb) b[i.first] = i.second;
    }
  }
  putchar(0x0A);
  //  system("pause");
  return Wild_Donkey;
}
/*
1 1 1 1
4
2
0 1
1 4

f_{i, j} = (f_{i - 1, j} | f_{i, j - 1})[a_i > b_j]

72
6161

1111
0101

869
174

111
101
111

8729
6581

1101
1101
0001
1111

10010
00000
10011
1

  1 1
111111
  1 1
111111
  1 1
111111
  1 1
*/