#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const unsigned long long Mod(1000000007);
inline void Mn(unsigned &x) {x -= ((x >= Mod) ? Mod : 0);}
inline void Mn(unsigned long long &x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned RD() {
  unsigned RTmp(0);
  char ch(getchar()); 
  while (ch < '0' && ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') RTmp = RTmp * 10 + ch - '0', ch = getchar(); 
  return RTmp;
}
unsigned FrTo(unsigned long long x, unsigned long long y) {return (((x + y) * (y - x + 1)) >> 1) % Mod;}
unsigned a[405], b[405][2], n, m, Cnt(0), Cond(0), A, B, Mx;
unsigned long long Tmp[2], Ans[2];
struct Node {
  vector<Node*> E;
  unsigned long long f, g;
  unsigned Lim[2];
  inline void DFS(Node* Fa) {
    unsigned L(max(Lim[0], A)), R(min(Lim[1], B));
    unsigned long long T1(R - L + 1), T2(FrTo(L, R));
    for (auto i:E) if(i != Fa) i->DFS(this);
    if(L > R) {f = g = 0; return;}
    Mn(Tmp[0] += (f = T1)), Mn(Tmp[1] += (g = T2));
    for (auto i:E) if(i != Fa) {
      Tmp[0] = (Tmp[0] + i->f * f) % Mod;
      Tmp[1] = (Tmp[1] + i->g * f + i->f * g) % Mod;
      f = (f + i->f * T1) % Mod, g = (g + i->f * T2 + T1 * i->g) % Mod;
    }
  }
}N[205];
int main() {
//  freopen("tree3.in", "r", stdin);
//  freopen("tree.out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    a[(i << 1) - 1] = N[i].Lim[0] = RD();
    Mx = max(Mx, a[i << 1] = N[i].Lim[1] = RD());
  }
  for (unsigned i(1); i < n; ++i) A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  m = min(m, Mx), Tmp[1] = Tmp[0] = 0;
  for (unsigned i(Mx - m); i; --i) A = i, B = i + m, N[1].DFS(NULL);
  Mn(Ans[0] += Tmp[0]), Mn(Ans[1] += Tmp[1]), Tmp[1] = Tmp[0] = 0;
  for (unsigned i(Mx - m); i >= 2; --i) A = i, B = i + m - 1, N[1].DFS(NULL);
  Mn(Ans[0] += Mod - Tmp[0]), Mn(Ans[1] += Mod - Tmp[1]);
  printf("%llu\n%llu\n", Ans[0], Ans[1]);
}
/*
3 1
2 3
3 5
4 6
1 2
1 3
*/
