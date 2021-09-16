#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
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
long long Ans(0x3f3f3f3f3f3f3f3f), Tmp1(0), Tmp2(0);
long long Left, Right, Tmp;
unsigned m, n, Pos, Cnt(0);
unsigned A, B, C, D, t;
unsigned Range[1000005][2], End[1000005];
struct Node {
  Node* LS, * RS;
  long long ValUp, ValDown;
}N[2000005], * CntN(N);
void PushDown(Node* x) {
  if (x->ValUp <= 0x3f3f3f3f3f3f3f3f) {
    x->LS->ValUp = x->RS->ValUp = x->ValUp;
    x->LS->ValDown = x->RS->ValDown = x->ValDown;
    x->ValUp = x->ValDown = 0x4000000000000000;
  }
}
void Build(Node* x, unsigned L, unsigned R) {
  x->ValUp = x->ValDown = 0x4000000000000000;
  if (L == R) { x->ValUp = L * Left, x->ValDown = -L * Right;return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid), Build(x->RS = ++CntN, Mid + 1, R);
}
void Change(Node* x, unsigned L, unsigned R) {
  if ((A <= L) && (R <= B)) { x->ValUp = Tmp1, x->ValDown = Tmp2; return; }
  unsigned Mid((L + R) >> 1);
  PushDown(x);
  if (A <= Mid) Change(x->LS, L, Mid);
  if (B > Mid) Change(x->RS, Mid + 1, R);
}
void Find(Node* x, unsigned L, unsigned R) {
  if (L == R) { Tmp = min(x->ValUp - L * Left, x->ValDown + L * Right); return; }
  unsigned Mid((L + R) >> 1);
  PushDown(x);
  if (Pos <= Mid) Find(x->LS, L, Mid);
  else Find(x->RS, Mid + 1, R);
}
void Print(Node* x, unsigned L, unsigned R) {
  if (L == R) { Ans = min(Ans, min(x->ValUp - L * Left, x->ValDown + L * Right)); return; }
  unsigned Mid((L + R) >> 1);
  PushDown(x), Print(x->LS, L, Mid), Print(x->RS, Mid + 1, R);
}
signed main() {
  n = RD(), Left = RD(), Right = RD();
  for (unsigned i(1); i <= n; ++i) {
    End[i] = End[i - 1] + RD();
    for (unsigned j(End[i - 1] + 1); j <= End[i]; ++j)
      Range[j][0] = RD(), Range[j][1] = RD();
    m = max(m, Range[End[i]][1]);
  }
  Build(N, 1, m);
  for (unsigned i(1); i <= n; ++i) {
    A = 1, B = Range[End[i - 1] + 1][0] - 1;
    if (A <= B) {
      Pos = B + 1, Find(N, 1, m), Tmp1 = Tmp + (B + 1) * Left;
      Tmp2 = 0x3f3f3f3f3f3f3f3f, Change(N, 1, m);
    }
    for (unsigned j(End[i - 1] + 1); j < End[i]; ++j) {
      A = Range[j][1] + 1, B = Range[j + 1][0] - 1;
      if (A <= B) {
        Pos = A - 1, Find(N, 1, m), Tmp2 = Tmp - (A - 1) * Right;
        Pos = B + 1, Find(N, 1, m), Tmp1 = Tmp + (B + 1) * Left;
        Change(N, 1, m);
      }
    }
    A = Range[End[i]][1] + 1, B = m;
    if (A <= B) {
      Pos = A - 1, Find(N, 1, m), Tmp2 = Tmp - (A - 1) * Right;
      Tmp1 = 0x3f3f3f3f3f3f3f3f, Change(N, 1, m);
    }
  }
  Print(N, 1, m);
  printf("%lld\n", Ans);
  return 0;
}