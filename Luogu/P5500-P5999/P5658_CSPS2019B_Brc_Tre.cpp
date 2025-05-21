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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned long long Tmp(0), Cur(0);
char a[500005];
struct Node;
Node *Stack[500005], **Top(Stack);
struct Node {
  char Type;
  Node *Fa, *Pre;
  vector<Node *> Son;
  unsigned Cnt;
  unsigned long long Ans;
  void DFS() {
    if (Type) {
      if (Top > Stack) {
        Pre = *(Top--);
        if (Pre->Fa && Pre->Fa->Type)
          Cnt = Pre->Fa->Cnt + 1;
        else
          Cnt = 1;
        Cur += Cnt;
      } else
        Pre = NULL, Cnt = 0;
    } else
      *(++Top) = this;
    Ans = Cur;
    for (auto i : Son) i->DFS();
    if (Type) {
      if (Pre) *(++Top) = Pre;
      Cur -= Cnt;
    } else
      --Top;
  }
} N[500005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  scanf("%s\n", a + 1);
  for (unsigned i(1); i <= n; ++i) N[i].Type = a[i] == ')';
  for (unsigned i(2); i <= n; ++i) (N[i].Fa = N + RD())->Son.push_back(N + i);
  N[1].DFS();
  for (unsigned i(1); i <= n; ++i) Tmp ^= i * N[i].Ans;
  printf("%llu\n", Tmp);
  //  }
  //  system("pause");
  return Wild_Donkey;
}