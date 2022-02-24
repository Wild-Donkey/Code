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
map<unsigned, vector<unsigned> > a;
unsigned Bin[32], B[31], n, D, CL, CR;
unsigned Cnt(0), Ans(0);
int A;
inline void Ins(unsigned x) {
  // printf("Ins %u\n", x);
  for (unsigned i(30); (~i) && x; --i) if (x >> i) {
    // printf("%u %u\n", i, x);
    if (B[i]) x ^= B[i];
    else { B[i] = x; return; }
  }
}
struct Node {
  vector <unsigned> Val;
  Node* LS, * RS;
  inline void Chg(unsigned L, unsigned R) {
    if ((CL <= L) && (R <= CR)) { Val.push_back(D); return; }
    unsigned Mid((L + R) >> 1);
    if (CL <= Mid) LS->Chg(L, Mid);
    if (CR > Mid) RS->Chg(Mid + 1, R);
  }
  inline void DFS() {
    // printf("DFS %u\n", this);
    // for (unsigned i(0); i <= 30; ++i) printf("%u ", B[i]); putchar(0x0A);
    unsigned Bf[31];
    memcpy(Bf, B, sizeof(B));
    for (auto i : Val) Ins(i);
    if (!LS) {
      Ans = 0;
      for (unsigned i(30); ~i; --i) if (B[i] && (!(Ans & Bin[i]))) Ans ^= B[i];
      printf("%u\n", Ans);
    }
    else LS->DFS(), RS->DFS();
    memcpy(B, Bf, sizeof(B));
    return;
  }
}N[1000005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
signed main() {
  // freopen("P4184_1.in", "r", stdin);
  // freopen("P4184.my", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Bin[0] = 1;
  for (unsigned i(1); i <= 30; ++i) Bin[i] = (Bin[i - 1] << 1);
  // for (unsigned i(0); i <= 30; ++i) printf("Bin %u = %u\n", i, Bin[i]);
  n = RD(), Build(N, 1, n);
  for (unsigned i(1); i <= n; ++i) {
    A = RDsg(), Ans = 0;
    if (A < 0) D = -A, CL = a[D].back(), CR = i - 1, N->Chg(1, n), a[D].pop_back();
    else D = A, a[D].push_back(i);
  }
  for (auto i : a) { D = i.first;  for (auto j : i.second) CL = j, CR = n, N->Chg(1, n); }
  fprintf(stderr, "Done\n");
  N->DFS();
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
12
13
10
-13
7
14
8
12
-7
8
-8
11
-10
*/