#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
const unsigned long long Mod(1000000007);
unsigned long long Bin[1000005], Ans(1);
unsigned m, n, Now;
unsigned A, B, C, D, t;
unsigned CntE(0), Cnt(0), Tmp(0);
char IO[2000005], Flg(0);
struct Node;
struct Edge {
  Node* To;
  char Chose;
}EP[2000005];
struct Node {
  vector <Edge*> E;
  char Dest;
}N[1000005];
inline char DFS(Node* x) {
  x->Dest |= 2, ++Cnt, CntE += x->E.size();
  char Need(x->Dest & 1);
  for (auto i:x->E) if(!(i->To->Dest & 2)) if(DFS(i->To)) i->Chose = 1, Need ^= 1;
  return Need;
}
signed main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
  n = RD(), m = RD(), Bin[0] = 1;
  scanf("%s%s", IO + 1, IO + 1000001);
  for (unsigned i(1); i <= m; ++i) {Bin[i] = Bin[i - 1] << 1; if(Bin[i] >= Mod) Bin[i] -= Mod;}
  for (unsigned i(1); i <= n; ++i) if(IO[i] ^ IO[1000000 + i]) N[i].Dest ^= 1, N[i + 1].Dest ^= 1;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD() + 1;
    EP[i << 1] = (Edge){N + B, 0};
    EP[(i << 1) - 1] = (Edge){N + A, 0};
    N[A].E.push_back(EP + (i << 1));
    N[B].E.push_back(EP + (i << 1) - 1);
  }
  for (unsigned i(n + 1); i; --i) if(!(N[i].Dest & 2)) {
    Cnt = CntE = 0;
    if(DFS(N + i)) {printf("0\nNO\n");return 0;}
    else Ans = Ans * Bin[(CntE >> 1) - Cnt + 1] % Mod;
  }
  printf("%llu\nYES\n", Ans);
  for (unsigned i(1); i <= m; ++i) putchar((EP[(i << 1) - 1].Chose | EP[i << 1].Chose) ? '1' : '0');
  return Wild_Donkey;
}
/*
2
0 5 10
6 7 10

8942 9040 28304
*/
