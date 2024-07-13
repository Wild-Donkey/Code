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
unsigned Fa[1005], Stack[1005], * Top(Stack);
unsigned m, n;
long long A, B;
unsigned  C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Find(unsigned x) {
  while (Fa[x] ^ x) *(++Top) = x, x = Fa[x];
  while (Top > Stack) Fa[*(Top--)] = x;
  return x;
}
void Merge(unsigned x, unsigned y) {
  // printf("Merge %u %u\n", x, y);
  x = Find(x), y = Find(y);
  if (x ^ y) Fa[x] = y;
}
struct Node {
  long long x, y, z;
  void Ins() {
    x = RDsg(), y = RDsg(), z = RDsg();
  }
}N[1005];
inline void Clr() {
  n = RD(), A = RD(), B = RD();
  for (unsigned i(n + 1); ~i; --i) Fa[i] = i;
}
long long Sqr(long long x) { return x * x; }
char Judge(Node* a, Node* b) {
  return Sqr(a->x - b->x) + Sqr(a->y - b->y) + Sqr(a->z - b->z) <= B;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      N[i].Ins();
      if (N[i].z <= B && N[i].z >= -B) Merge(0, i);
      if (N[i].z <= A + B && N[i].z >= A - B) Merge(n + 1, i);
    }
    B = Sqr(B << 1);
    for (unsigned i(1); i < n; ++i) {
      for (unsigned j(i + 1); j <= n; ++j) {
        if (Judge(N + i, N + j)) Merge(i, j);
      }
    }
    printf(Find(0) == Find(n + 1) ? "Yes\n" : "No\n");
  }
  //  system("pause");
  return Wild_Donkey;
}