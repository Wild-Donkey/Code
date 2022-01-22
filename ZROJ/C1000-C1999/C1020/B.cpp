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
const unsigned long long Mod(1000000007);
unsigned long long Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Tmp(0), LiC(0);
vector <unsigned> List[300005];
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned Dep, LiNu;
}N[300005];
inline void DFS(Node* x) {
//  printf("DFS %u\n", x - N);
  Node* Heavy(NULL);
  unsigned Mx(0);
  for(auto i:x->To) if(i != x->Fa) {
    i->Fa = x, i->Dep = x->Dep + 1, DFS(i);
    if(List[i->LiNu].size() > Mx) Mx = List[i->LiNu].size(), Heavy = i;
  }
  if(!Heavy) {
    List[++LiC].push_back(1), x->LiNu = LiC;
    return;
  }
  x->LiNu = Heavy->LiNu;
  List[x->LiNu].push_back(1);
  if(Mx >= m) {
    Ans += List[x->LiNu][Mx - m];
    if(Ans >= Mod) Ans -= Mod;
  }
  for(auto i:x->To) if((i != x->Fa) && (i != Heavy)) {
    for (unsigned j(List[i->LiNu].size() - 1), k(m - 1); (~j) && (~k); --j, --k) {
      if(Mx - k < List[x->LiNu].size()) Ans = (Ans + (unsigned long long)List[x->LiNu][Mx - k] * List[i->LiNu][j]) % Mod;
    }
    for (unsigned j(List[i->LiNu].size() - 1), k(1); (~j) && (k <= m); --j, ++k) {
      List[x->LiNu][Mx - k] += List[i->LiNu][j];
    }
  }
//  printf("List %u is %u\n", x - N, x->LiNu);
//  for (auto i:List[x->LiNu]) printf("%u ", i);
//  putchar(0x0A);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  N[1].Dep = 1, DFS(N + 1);
  printf("%llu\n", Ans * ((((unsigned long long)m * (m + 1)) >> 1) % Mod) % Mod);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

