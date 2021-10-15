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
unsigned A, B;
pair<unsigned, unsigned> a[200005];
unsigned m, n;
unsigned C[2], t;
unsigned Cnt(0), Tmp(0), Set(0);
unsigned Ans[2][200005], Sum(0);
unsigned List[5000005];
char Jum(0), Ci(0);
unsigned Prt() {
  printf("%u ", C[1]);
  for (unsigned j(1); j <= C[1]; ++j) printf("%u ", Ans[1][j]);
  printf("\n%u ", C[0]);
  for (unsigned j(1); j <= C[0]; ++j) printf("%u ", Ans[0][j]);
  putchar(0x0a);
}
inline void Add(const unsigned& x) {
  for (unsigned i(0); i < x; ++i)
    if(Set & (1 << i)) Ans[Ci][++C[Ci]] = a[i + 1].second;
}
inline void DFS(unsigned Dep) {
  if(Dep == m) {
    unsigned TmpS(Set);
    if((Sum + A <= 5000000) && List[Sum + A]) {
      Tmp = List[Sum + A] & Set;
      Ci ^= 1, Jum = 1, Set ^= Tmp, Add(m);
      Ci ^= 1, Set = List[Sum + A] ^ Tmp, Add(m);
      return;
    }
    if((Sum > A) && List[Sum - A]) {
      Tmp = List[Sum - A] & Set;
      Jum = 1, Set ^= Tmp, Add(m);
      Ci ^= 1, Set = List[Sum - A] ^ Tmp, Add(m);
      return;
    }
    if(Sum == A) {Jum = 1, Add(m);return;}
    List[Sum] = Set;
    return;
  }
  DFS(Dep + 1); if(Jum) return;
  Set |= (1 << Dep), Sum += a[Dep + 1].first;
  DFS(Dep + 1); if(Jum) return;
  Set ^= (1 << Dep), Sum -= a[Dep + 1].first; 
}
inline void Force (unsigned Dep) {
  if(Dep == n) {
    if(List[Sum]) {
      Tmp = List[Sum] & Set;
      Jum = 1, Set ^= Tmp, Add(n);
      Ci ^= 1, Set = List[Sum] ^ Tmp, Add(n);
    }
    List[Sum] = Set;
    return;
  }
  Force(Dep + 1); if(Jum) return;
  Set |= (1 << Dep), Sum += a[Dep + 1].first;
  Force(Dep + 1); if(Jum) return;
  Set ^= (1 << Dep), Sum -= a[Dep + 1].first; 
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), m = min(RD(), (unsigned)25);
  for (unsigned i(1); i <= n; ++i) a[i].first = RD(), a[i].second = i;
  C[0] = C[1] = A = B = 0;
  if(n <= 27) {
    Force(0);
    if(Jum) Prt();
    else printf("-1\n");
    return 0;
  }
  sort(a + 1, a + n + 1);
  for (unsigned i(n); i > m; --i) {
    if (A < B) {
      Ans[0][++C[0]] = a[i].second;
      A += a[i].first;
    } else {
      Ans[1][++C[1]] = a[i].second;
      B += a[i].first;
    }
    Tmp = min(A, B), A -= Tmp, B -= Tmp;
  }
  if((!A) && (!B)) {
    Prt();
    return 0;
  }
  if(A) {
    Ci = 1, DFS(0);
    if(Jum) Prt();
    else printf("-1\n");
  } else {
    A = B, Ci = 0, DFS(0);
    if(Jum) Prt();
    else printf("-1\n");
  }
//  if(!Jum) {
//    printf("%u %u\n", A, B);
//    for (unsigned i(1); i <= m; ++i) printf("%u ", a[i].first);
//  }
  return Wild_Donkey;
}
/*
10 2
76 9 67 86 98 57 78 23 1 2
*/
