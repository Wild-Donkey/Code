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
unsigned m, n, Stack[500005], Head(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[500005];
struct Node {
  Node* LS, * RS;
  unsigned f[2], g[2];
  inline void Add(Node* x) {
    if (LS) RS = x;
    else LS = x;
  }
  inline void DFS() {
    if (!LS) {
      g[0] = f[0] = 1, g[1] = f[1] = 0;
      return;
    }
    LS->DFS();
    if (!RS) {
      f[0] = LS->f[1] + 1;
      f[1] = max(LS->f[0], LS->f[1]);
      g[0] = LS->g[1] + 1;
      g[1] = min(LS->g[0], LS->g[1]);
      return;
    }
    RS->DFS();
    f[0] = LS->f[1] + RS->f[1] + 1;
    f[1] = max(LS->f[0] + RS->f[1], LS->f[1] + RS->f[0]);
    g[0] = LS->g[1] + RS->g[1] + 1;
    g[1] = min(LS->g[0] + RS->g[1], LS->g[1] + RS->g[0]);
  }
}N[500005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  scanf("%s", a + 1);
  n = strlen(a + 1), Stack[++Head] = 1;
  for (unsigned i(2); i <= n; ++i) {
    // printf("Link %u From %u Head %u %c\n", Stack[Head], i, Head, a[Stack[Head]]);
    N[Stack[Head]].Add(N + i), --a[Stack[Head]];
    while (Head && (a[Stack[Head]] <= '0')) --Head;
    if (a[i] > '0') Stack[++Head] = i;
  }
  N[1].DFS();
  printf("%u %u\n", max(N[1].f[0], N[1].f[1]), min(N[1].g[0], N[1].g[1]));
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
11201111111112012120222001102010202212200010112122102121201002121122102222002212100102001200001100122000122111211220000011111201122010221211121011001102222022110021020002120100211121110220210210210121010022121020022120000111111122101121021211121022220200212000202220120001100201100112121120022000111112102011111211020111220022101221122222220100202202211112101120201011212112001120121010222100120122222001200211102201201011200100100120012210200022101011122111000210200211210102000121010122200200112010
*/