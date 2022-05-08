#include<algorithm>
#include<cstring>
#include<string>
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
inline unsigned long long Inv(unsigned long long x) {
  unsigned y(1000000005);
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
unsigned FrTo(unsigned long long x, unsigned long long y) {return (((x + y) * (y - x + 1)) >> 1) % Mod;}
unsigned a[405], b[805], Dot[2][205];
unsigned n, m, Cnt(0), Cond(0), A, B, Mx;
unsigned long long ClT[2], Tmp[2], Ans[2];
struct Node {
  vector<Node*> E;
  unsigned long long f, g;
  unsigned Lim[2];
  inline void DFS(Node* Fa) {
    unsigned L(max(Lim[0], A)), R(min(Lim[1], B));
    unsigned long long T1(R - L + 1), T2(FrTo(L, R));
    for (auto i:E) if(i != Fa) i->DFS(this);
    if(L > R) {f = g = 0; return;}
    Mn(ClT[0] += (f = T1)), Mn(ClT[1] += (g = T2));
    for (auto i:E) if(i != Fa) {
      ClT[0] = (ClT[0] + i->f * f) % Mod;
      ClT[1] = (ClT[1] + i->g * f + i->f * g) % Mod;
      f = (f + i->f * T1) % Mod, g = (g + i->f * T2 + T1 * i->g) % Mod;
    }
  }
}N[205];
inline unsigned long long Lagrange(unsigned* x, unsigned Len, unsigned Qry) {
  unsigned long long F(1), SumI(0);
  for (unsigned i(0); i <= Len; ++i) F = F * (Qry + Mod - i) % Mod;
  for (unsigned i(0); i <= Len; ++i) {
    unsigned long long Mul(Inv(x[i]) * (Qry + Mod - i) % Mod);
    for (unsigned j(0); j <= Len; ++j) if(i ^ j) Mul = Mul * (i + Mod - j) % Mod;
    Mn(SumI += Inv(Mul));
  }
  return F * SumI % Mod;
}
inline void Calc(unsigned x, unsigned L, unsigned R) {
  if(R < L) return;
  if(R <= n + 2 + L) {
    ClT[0] = ClT[1] = 0;
    for (A = L; A <= R; ++A) B = A + x, N[1].DFS(NULL);
    Mn(Tmp[0] += ClT[0]), Mn(Tmp[1] += ClT[1]);
    return;
  }
  for (unsigned i(0); i <= n + 2; ++i) {
    ClT[0] = ClT[1] = 0, A = L + i, B = A + x, N[1].DFS(NULL);
    Dot[0][i] = ClT[0], Dot[1][i] = ClT[1];
  }
  for (unsigned i(1); i <= n + 1; ++i) Mn(Dot[0][i] += Dot[0][i - 1]);
  Mn(Tmp[0] += Lagrange(Dot[0], n + 1, R - L));
  for (unsigned i(1); i <= n + 2; ++i) Mn(Dot[1][i] += Dot[1][i - 1]);
  Mn(Tmp[1] += Lagrange(Dot[1], n + 2, R - L));
}
inline void Solve(unsigned x, unsigned L, unsigned R) {
  unsigned Nc(Cnt);
  for (unsigned i(Cnt); i && (a[i] >= x); --i) b[++Nc] = a[i] - x;
  memcpy(b + 1, a + 1, Cnt << 2), sort(b + 1, b + Nc + 1), Nc = unique(b + 1, b + Nc + 1) - b - 1;
  if(b[1]) Calc(x, L, b[1] - 1);
  for (unsigned i(1); i < Nc; ++i) Calc(x, b[i], b[i + 1] - 1);
  Calc(x, b[Nc], R);
}
int main() {
  n = RD(), m = RD(), Cnt = (n << 1);
  for (unsigned i(1); i <= n; ++i)
    a[(i << 1) - 1] = N[i].Lim[0] = RD(), a[i << 1] = (N[i].Lim[1] = RD()) + 1;
  for (unsigned i(1); i < n; ++i)
    A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  sort(a + 1, a + Cnt + 1), Cnt = unique(a + 1, a + Cnt + 1) - a - 1, m = min(m, Mx = a[Cnt]);
  Tmp[1] = Tmp[0] = 0, Solve(m, 1, Mx - m), Mn(Ans[0] += Tmp[0]), Mn(Ans[1] += Tmp[1]);
  Tmp[1] = Tmp[0] = 0, Solve(m - 1, 2, Mx - m), Mn(Ans[0] += Mod - Tmp[0]), Mn(Ans[1] += Mod - Tmp[1]);
  printf("%llu\n%llu\n", Ans[0], Ans[1]);
}
