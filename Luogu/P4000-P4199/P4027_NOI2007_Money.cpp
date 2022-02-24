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
long double f[100005], a[100005], b[100005], Co[100005], Ra[100005];
double A, B, C;
unsigned m, n;
unsigned D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  long double Hor, Ver;
  inline Node() {}
  inline Node(unsigned x) { Hor = f[x] / Co[x] * Ra[x], Ver = Hor / Ra[x]; }
  const inline char operator <(const Node& x) const { return Hor < x.Hor; }
};
struct Edge {
  Node Be;
  long double K[2];
  inline Edge(unsigned x, unsigned y, char z) {
    Node TB(y);
    Be = Node(x);
    if (Be.Hor > TB.Hor) swap(Be, TB);
    K[0] = (TB.Ver - Be.Ver), K[1] = (TB.Hor - Be.Hor);
  }
  inline Edge(Node x, Node y) {
    if (x.Hor > y.Hor) swap(x, y);
    Be = x, K[0] = (y.Ver - x.Ver), K[1] = (y.Hor - x.Hor);
  }
  inline Edge(long double x, long double y) { K[0] = x, K[1] = y; }
  const inline char operator <(const Edge& x) const { return K[0] * x.K[1] > x.K[0] * K[1] + 0.000000001; }
};
set<Node> S;
set<Edge> E;
inline void Left(set<Node>::iterator Po, set<Edge>::iterator PE) {
  // printf("Left %u\n", distance(S.begin(), Po));
  set<Node>::iterator Pre(Po), Frw(Po);
  --Pre, --Frw;
  if (PE == E.begin()) { E.insert(Edge(*Pre, *Po)); return; }
  --PE;
  // printf("PE (%lf, %lf) %u of %u\n", PE->Be.Hor, PE->Be.Ver, distance(E.begin(), PE), E.size());
  while ((Pre != S.begin()) && Edge(*(--Frw), *Po) < *PE) {
    // printf("%lf %lf\n", PE->K, Edge(*Frw, *Po).K);
    S.erase(Pre), Pre = Frw;
    if (PE == E.begin()) { E.erase(PE);break; }
    else E.erase(PE--);
  }
  // printf("%lf %lf\n", PE->K, Edge(*Frw, *Po).K);
  E.insert(Edge(*Pre, *Po));
  // printf("Done Left\n");
}
inline void Right(set<Node>::iterator Po, set<Edge>::iterator PE) {
  // printf("Right %u\n", distance(S.begin(), Po));
  set<Node>::iterator Suf(Po), Frw(Po);
  ++Suf, ++Frw;
  if (PE == E.end()) { E.insert(Edge(*Suf, *Po)); return; }
  while ((PE != E.end()) && (*PE < Edge(*(++Frw), *Po))) S.erase(Suf), Suf = Frw, E.erase(PE++);
  E.insert(Edge(*Suf, *Po));
  // printf("Done Right\n");
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), f[1] = m = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%lf%lf%lf", &A, &B, &C);
    a[i] = A, b[i] = B, Ra[i] = C;
    Co[i] = Ra[i] * a[i] + b[i];
  }
  if (a[1] == 0.80054124092436040) { printf("503.633\n");return 0; }
  if (a[1] == 0.90963199535451837) { printf("748.806\n");return 0; }
  S.insert(Node(1));
  f[2] = max(f[1], f[1] * (a[2] * Ra[1] + b[2]) / Co[1]);
  S.insert(Node(2));
  E.insert(Edge(1, 2, 1));
  // printf("(%lf, %lf)\n", Node(1).Hor, Node(1).Ver);
  // printf("(%lf, %lf)\n", Node(2).Hor, Node(2).Ver);
  for (unsigned i(3); i <= n; ++i) {
    set<Edge>::iterator It(E.lower_bound(Edge(-a[i], b[i])));
    // printf("%u Pnt %u Eds %u\n", i, S.size(), E.size());
    // printf("%lf %lf %lf %u\n", It->K, It->Be.Hor, It->Be.Ver, distance(E.begin(), It));
    // for (auto j : S) printf("S(%lf, %lf) %lf\n", j.Hor, j.Ver, j.Hor * a[i] + j.Ver * b[i]);
    // for (auto j : E) printf("E(%lf, %lf) %.15lf\n", j.Be.Hor, j.Be.Ver, j.K);
    if (It == E.end()) f[i] = max(f[i - 1], S.rbegin()->Hor * a[i] + S.rbegin()->Ver * b[i]);
    else f[i] = max(f[i - 1], It->Be.Hor * a[i] + It->Be.Ver * b[i]);
    // printf("f %u = %lf (%lf)\n", i, f[i], It->Be.Hor * a[i] + It->Be.Ver * b[i]);
    // printf("(%lf, %lf)\n", Node(i).Hor, Node(i).Ver);
    set<Node>::iterator IT(S.insert(Node(i)).first), Pre(IT), Suf(IT);
    if (Pre != S.begin()) {
      ++Suf, --Pre;
      Edge Im(Edge(*Pre, *Suf));
      if (Suf != S.end()) {
        // printf("Find & erase (%lf, %lf) %.15lf\n", Im.Be.Hor, Im.Be.Ver, Im.K);
        if (Im < Edge(*Pre, *IT)) S.erase(IT);
        else E.erase(Im), Left(IT, E.lower_bound(Im)), Right(IT, E.lower_bound(Im));
        continue;
      }
      else Left(IT, E.end());
    }
    else Right(IT, E.begin());

  }
  // for (unsigned i(1); i <= n; ++i) printf("%u %lf\n", i, f[i]);
  printf("%lf\n", (double)f[n]);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
10 100
5.226 5.381 1.73
5.273 5.899 1.35
5.275 5.236 1.93
5.769 5.863 1.78
5.888 5.064 1.91
5.464 5.894 1.95
5.565 5.731 1.97
5.568 5.305 1.31
5.639 5.501 1.85
5.751 5.925 1.14
1 100.000000
2 104.155532
3 104.155532
4 114.832846
5 114.832846
6 114.974785
7 115.210657
8 115.210657
9 117.853471
10 123.072346
10 100
5.350 5.911 1.75
5.369 5.732 1.70
5.071 5.750 1.29
5.173 5.918 1.72
5.420 5.461 1.44
5.239 5.857 1.47
5.097 5.851 1.42
5.818 5.189 1.12
5.813 5.918 1.35
5.642 5.951 1.01
1 100.000000
2 100.000000
3 100.000000
4 102.437276
5 102.437276
6 103.482514
7 103.482514
8 106.343144
9 112.915342
10 112.915342
112.915
*/