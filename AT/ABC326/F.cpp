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
unordered_map<long long, unsigned> Mp;
pair<long long, char> List[4194304], List2[4194304];
char XA[55], YA[55];
long long X, Y, AnsX, AnsY;
long long a[55], b[55];
unsigned n, A(0), B(0);
char Flg(0);
//  inline void Clr() {}
inline void Udt(pair<long long, char> *f, pair<long long, char> *g,
                unsigned len, long long x) {
  for (unsigned i(0); i < len; ++i)
    g[i << 1] = {f[i].first + x, 0}, g[(i << 1) ^ 1] = {f[i].first - x, 1};
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), X = RDsg(), Y = RDsg();
  for (unsigned i(1); i <= n; ++i) {
    if (i & 1)
      b[++B] = RD();
    else
      a[++A] = RD();
  }

  pair<long long, char> *Cur1(List), *Cur2(List2);
  List[0] = {0, 0};
  for (unsigned i(1); i <= (A >> 1); ++i) {
    Udt(Cur1, Cur1 + (1 << (i - 1)), 1 << (i - 1), a[i]);
    Cur1 += (1 << (i - 1));
  }
  for (unsigned i(0); i < (1 << (A >> 1)); ++i) Mp[Cur1[i].first] = i + 1;
  List2[0] = {X, 0};
  for (unsigned i(1); i <= ((A + 1) >> 1); ++i) {
    Udt(Cur2, Cur2 + (1 << (i - 1)), 1 << (i - 1), a[A - i + 1]);
    Cur2 = Cur2 + (1 << (i - 1));
  }
  unsigned L1, L2;
  for (unsigned i(0); i < (1 << ((A + 1) >> 1)); ++i)
    if (Mp[Cur2[i].first] != 0) {
      Flg = 1, L2 = i, L1 = Mp[Cur2[i].first] - 1;
      break;
    }
  if (!Flg) {
    printf("No\n");
    return 0;
  }
  for (unsigned i(A >> 1); i; --i)
    XA[i] = Cur1[L1].second, Cur1 -= (1 << (i - 1)), L1 >>= 1;
  for (unsigned i((A + 1) >> 1); i; --i)
    XA[A - i + 1] = (Cur2[L2].second ^ 1), Cur2 -= (1 << (i - 1)), L2 >>= 1;

  Cur1 = List, Cur2 = List2, Mp.clear(), Flg = 0;
  List[0] = {0, 0};
  for (unsigned i(1); i <= (B >> 1); ++i) {
    Udt(Cur1, Cur1 + (1 << (i - 1)), 1 << (i - 1), b[i]);
    Cur1 = Cur1 + (1 << (i - 1));
  }
  // for (unsigned i(0); i < (1 << (B >> 1)); ++i) printf("%lld ",
  // Cur1[i].first); putchar(0x0A);
  for (unsigned i(0); i < (1 << (B >> 1)); ++i) Mp[Cur1[i].first] = i + 1;
  List2[0] = {Y, 0};
  for (unsigned i(1); i <= ((B + 1) >> 1); ++i) {
    Udt(Cur2, Cur2 + (1 << (i - 1)), 1 << (i - 1), b[B - i + 1]);
    Cur2 = Cur2 + (1 << (i - 1));
  }
  // for (unsigned i(0); i < (1 << ((B + 1) >> 1)); ++i)
  //   printf("%lld ", Cur2[i].first);
  // putchar(0x0A);
  for (unsigned i(0); i < (1 << ((B + 1) >> 1)); ++i)
    if (Mp[Cur2[i].first] != 0) {
      Flg = 1, L2 = i, L1 = Mp[Cur2[i].first] - 1;
      // printf("L1 L2 in Y %u %u\n", L1, L2);
      break;
    }
  if (!Flg) {
    printf("No\n");
    return 0;
  }
  for (unsigned i(B >> 1); i; --i)
    YA[i] = Cur1[L1].second, Cur1 -= (1 << (i - 1)), L1 >>= 1;
  for (unsigned i((B + 1) >> 1); i; --i)
    YA[B - i + 1] = (Cur2[L2].second ^ 1), Cur2 -= (1 << (i - 1)), L2 >>= 1;
  // printf("A B %u %u\n", A, B);
  // for (unsigned i(1); i <= A; ++i) putchar('0' + XA[i]);
  // putchar(0x0A);
  // for (unsigned i(1); i <= B; ++i) putchar('0' + YA[i]);
  // putchar(0x0A);
  printf("Yes\n");
  char Dire(0);
  for (unsigned i(2); i <= n + 1; ++i) {
    if (i & 1) {
      putchar((XA[i >> 1] ^ Dire) ? 'L' : 'R'), Dire = XA[i >> 1];
    } else
      putchar((YA[i >> 1] ^ Dire) ? 'R' : 'L'), Dire = YA[i >> 1];
  }
  putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}