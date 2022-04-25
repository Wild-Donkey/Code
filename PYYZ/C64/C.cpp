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
unsigned Hr[300005], Ve[300005], a[300005], b[300005], m, n;
vector<unsigned> Add[300005];
bitset<300005> Ban;
unsigned Cur[300005], Ls[300005], Rs[300005], Stack[300005], *STop(Stack);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  A = RD(), B = RD(), n = RD();
  for (unsigned i(1); i <= n; ++i) Hr[i] = a[i] = RD(), Ve[i] = b[i] = RD();
  Ve[0] = Hr[0] = 0, Hr[n + 1] = A, Ve[n + 1] = B;
  sort(Hr, Hr + n + 2), C = unique(Hr, Hr + n + 2) - Hr;
  sort(Ve, Ve + n + 2), D = unique(Ve, Ve + n + 2) - Ve;
  for (unsigned i(1); i < D; ++i) Ans = max(A + Ve[i] - Ve[i - 1], Ans);
  for (unsigned i(1); i <= n; ++i)
    Add[lower_bound(Hr, Hr + C, a[i]) - Hr].push_back(lower_bound(Ve, Ve + D, b[i]) - Ve);
//  printf("Hr:"); for (unsigned i(0); i < C; ++i) printf("%u ", Hr[i]); putchar(0x0A);
//  printf("Ve:"); for (unsigned i(0); i < D; ++i) printf("%u ", Ve[i]); putchar(0x0A);
  for (unsigned i(0); i < C; ++i) {
//    printf("Cur %u %u\n", i, a[i]);
    Cur[0] = Cur[D - 1] = 0x3f3f3f3f;
//    for (unsigned j(0); j < D; ++j) printf("%u ", Cur[j]); putchar(0x0A);
    *(STop = (Stack + 1)) = 0;
    for (unsigned j(1); j < D - 1; ++j) {
//      printf("Cur %u\n", j);
      while(Cur[*STop] <= Cur[j]) {
//        printf("STop %u\n", *STop);
        if(Cur[*STop] == Cur[j]) Ban[*STop] = 1;
        --STop;
      }
      Ls[j] = *STop, *(++STop) = j;
    }
    *(STop = (Stack + 1)) = D - 1;
    for (unsigned j(D - 2); j; --j) {
      while(Cur[*STop] < Cur[j]) --STop;
      Rs[j] = *STop, *(++STop) = j;
    }
//    for (unsigned j(0); j < D; ++j) printf("%u ", Ls[j]); putchar(0x0A);
//    for (unsigned j(0); j < D; ++j) printf("%u ", Rs[j]); putchar(0x0A);
    for (unsigned j(1); j < D - 1; ++j) {
      if(Ban[j]) Ban[j] = 0;
      else Ans = max(Ans, Hr[i] - Hr[Cur[j]] + Ve[Rs[j]] - Ve[Ls[j]]);// printf("[%u, %u] [%u, %u] %u\n", Hr[Cur[j]], Hr[i], Ve[Ls[j]], Ve[Rs[j]], Ans);
    }
    for (auto j:Add[i]) Cur[j] = i;
  }
  printf("%u\n", Ans << 1);
//  }
  return Wild_Donkey;
}
/*
10 10 4
1 6
4 1
6 9
9 4
*/
