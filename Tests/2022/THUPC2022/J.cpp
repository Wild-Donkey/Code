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
struct Seg{
  unsigned L, R, Pos;
  char Type;
  const inline char NeqLR (const Seg& x) const {return ((L ^ x.L) || (R ^ x.R)); }
  const inline char NFrm (const Seg& x, const Seg& y) const {return ((x.Pos ^ L) || (y.Pos ^ R) || (Pos ^ x.L) || (x.L ^ y.L)); }
  const inline char NTo  (const Seg& x, const Seg& y) const {return ((x.Pos ^ L) || (y.Pos ^ R) || (Pos ^ x.R) || (x.R ^ y.R)); }
}a[100005], H[10], V[10], Stk[20];
vector<pair<unsigned, unsigned>> Hor[200005], Ver[200005];
unsigned bx[200005], by[200005], Cn[10][10], m, n;
unsigned A, B, C, D, t;
unsigned CntT(0), CntH(0), CntU(0), CntP(0), CntC(0);
unsigned Cntx(0), Cnty(0), STop(0), HC(0), VC(0), Ans(0), Tmp(0);
char Vis[20], Map[105][105];
inline void DFS(unsigned x, char Type) {
  Stk[++STop] = Type ? V[x] : H[x];
  if(Type) {++A, Vis[x] = 1; for (unsigned i(1); i <= 7; ++i) if((Cn[x][i]) && (!Vis[i + 8])) DFS(i, 0);}
  else     {++B, Vis[x + 8] = 1; for (unsigned i(1); i <= 8; ++i) if(Cn[i][x] && (!Vis[i])) DFS(i, 1); }
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    a[i].Type = RD();
    if(a[i].Type) by[++Cnty] = a[i].L = RDsg() + 1000000000, by[++Cnty] = a[i].R = RDsg() + 1000000000, bx[++Cntx] = a[i].Pos = RDsg() + 1000000000;
    else          bx[++Cntx] = a[i].L = RDsg() + 1000000000, bx[++Cntx] = a[i].R = RDsg() + 1000000000, by[++Cnty] = a[i].Pos = RDsg() + 1000000000;
  }
  sort(bx + 1, bx + Cntx + 1), Cntx = unique(bx + 1, bx + Cntx + 1) - bx;
  sort(by + 1, by + Cnty + 1), Cnty = unique(by + 1, by + Cnty + 1) - by;
  for (unsigned i(1); i <= n; ++i) {
    if(a[i].Type) a[i].L = lower_bound(by + 1, by + Cnty, a[i].L) - by, a[i].R = lower_bound(by + 1, by + Cnty, a[i].R) - by, a[i].Pos = lower_bound(bx + 1, bx + Cntx, a[i].Pos) - bx;
    else          a[i].L = lower_bound(bx + 1, bx + Cntx, a[i].L) - bx, a[i].R = lower_bound(bx + 1, bx + Cntx, a[i].R) - bx, a[i].Pos = lower_bound(by + 1, by + Cnty, a[i].Pos) - by;
  }
  for (unsigned i(1); i <= n; ++i) {
    if(a[i].Type) Ver[a[i].Pos].push_back({a[i].L, a[i].R});
    else          Hor[a[i].Pos].push_back({a[i].L, a[i].R});
  }
  for (unsigned i(1); i < Cntx; ++i) if(Ver[i].size()) {
    sort(Ver[i].begin(), Ver[i].end());
    unsigned Bg(Ver[i][0].first), To(Ver[i][0].second);
    for (auto j:Ver[i]) {
      if(j.first > To) {
        V[++VC] = {Bg, To, i, 1};
        if(VC > 8) {printf("No\n"); return 0;}
        Bg = j.first, To = j.second;
      } else To = max(To, j.second);
    }
    V[++VC] = {Bg, To, i, 1};
    if(VC > 8) {printf("No\n"); return 0;}
  }
  for (unsigned i(1); i < Cnty; ++i) if(Hor[i].size()) {
//    printf("%u : \n", i);
    sort(Hor[i].begin(), Hor[i].end());
    unsigned Bg(Hor[i][0].first), To(Hor[i][0].second);
    for (auto j:Hor[i]) {
//      printf("[%u, %u]\n", Bg, To);
      if(j.first > To) {
        H[++HC] = {Bg, To, i, 0};
        if(HC > 7) {printf("No\n"); return 0;}
        Bg = j.first, To = j.second;
      } else To = max(To, j.second);
    }
    H[++HC] = {Bg, To, i, 0};
    if(HC > 7) {printf("No\n"); return 0;}
  }
//  for (unsigned i(1); i <= VC; ++i) 
//    for (unsigned j(V[i].L * 3); j <= V[i].R * 3; ++j) Map[j][V[i].Pos * 3] = 'a' + i - 1;
//  for (unsigned i(1); i <= HC; ++i)
//    for (unsigned j(H[i].L * 3); j <= H[i].R * 3; ++j) Map[H[i].Pos * 3][j] = 'a' + i - 1;
//  for (unsigned i((Cnty - 1) * 3); i; --i) { 
//    for (unsigned j(1); j <= (Cntx - 1) * 3; ++j) putchar(Map[i][j]); 
//    putchar(0x0A);
//  }
//  printf("%u %u\n", VC, HC);
  if(VC < 8 || HC < 7) {printf("No\n"); return 0;}
  for (unsigned i(1); i <= 8; ++i) if(V[i].L == V[i].R) {printf("No\n"); return 0;}
  for (unsigned j(1); j <= 7; ++j) if(H[j].L == H[j].R) {printf("No\n"); return 0;}
  for (unsigned i(1); i <= 8; ++i) for (unsigned j(1); j <= 7; ++j)
    if(V[i].L <= H[j].Pos && V[i].R >= H[j].Pos && H[j].L <= V[i].Pos && H[j].R >= V[i].Pos) Cn[i][j] = 1;
  for (unsigned i(1); i <= 8; ++i) if(!Vis[i]) {
//    printf("%u %u %u %u %u\n", CntT, CntH, CntU, CntP, CntC);
    STop = A = B = 0, DFS(i, 1);
//    printf("A %u, B %u, ST %u\n", A, B, STop);
    if(STop > 4) {printf("No\n"); return 0;}
    if(STop == 4) {
      if(A ^ 2) {printf("No\n"); return 0;}
      if(Stk[1].Type && Stk[2].Type) swap(Stk[1], Stk[3]), swap(Stk[2], Stk[4]);
      if(Stk[1].Type && Stk[3].Type) swap(Stk[1], Stk[4]);
      if(Stk[1].Type && Stk[4].Type) swap(Stk[1], Stk[3]);
      if(Stk[1].Pos > Stk[2].Pos) swap(Stk[1], Stk[2]);
      if(Stk[3].Pos > Stk[4].Pos) swap(Stk[3], Stk[4]);
      if(Stk[1].NeqLR(Stk[2])) {printf("No\n"); return 0;}
      if(Stk[2].NTo(Stk[3], Stk[4])) {printf("No\n"); return 0;}
      if(Stk[4].NTo(Stk[1], Stk[2])) {printf("No\n"); return 0;}
      if(Stk[3].L >= Stk[1].Pos) {printf("No\n"); return 0;}
      ++CntP;
      continue;
    }
    if(A == 1) {
      if(B == 1) {//T
        if(Stk[1].Type) swap(Stk[1], Stk[2]);
//        printf("OK\n");
        if(Stk[1].Pos ^ Stk[2].R) {printf("No\n"); return 0;}
        if(Stk[1].Pos == Stk[2].L){printf("No\n"); return 0;}
//        printf("[%u %u] %u\n", Stk[1].L, Stk[1].R, Stk[2].Pos);
        if((Stk[1].L < Stk[2].Pos) && (Stk[1].R > Stk[2].Pos)) ++CntT;
        else {printf("No\n"); return 0;}
        continue;
      }
      if(B == 2) {//C
        if(Stk[1].Type) swap(Stk[1], Stk[2]);
        if(Stk[2].Type) swap(Stk[2], Stk[3]);
        if(Stk[1].Pos > Stk[2].Pos) swap(Stk[1], Stk[2]);
        if(Stk[1].NeqLR(Stk[2])) {printf("No\n"); return 0;}
        if(Stk[3].NFrm(Stk[1], Stk[2])) {printf("No\n"); return 0;}
        ++CntC;
        continue;
      }
      printf("No\n"); return 0;
    }
    if(A ^ 2){printf("No\n"); return 0;}
    if(B ^ 1){printf("No\n"); return 0;}
    if(Stk[1].Type && Stk[2].Type) swap(Stk[1], Stk[3]);
    if(Stk[1].Type) swap(Stk[1], Stk[2]);
    if(Stk[2].Pos > Stk[3].Pos) swap(Stk[2], Stk[3]);
    if(Stk[2].NeqLR(Stk[3])) {printf("No\n"); return 0;}
    if((Stk[1].L ^ Stk[2].Pos) && (Stk[1].R ^ Stk[3].Pos)){printf("No\n"); return 0;}
    if(Stk[1].Pos == Stk[2].L) {++CntU;continue; }
    if((Stk[1].Pos >= Stk[2].R) || (Stk[1].Pos <= Stk[2].L)){printf("No\n"); return 0;}
    ++CntH;
  }
//  printf("%u %u %u %u %u\n", CntT, CntH, CntU, CntP, CntC);
  if(CntT == 1 && CntH == 1 && CntU == 1 && CntP == 1 && CntC == 1) printf("Yes\n");
  else printf("No\n");
//  }
//  system("pause");
  return Wild_Donkey;
}

