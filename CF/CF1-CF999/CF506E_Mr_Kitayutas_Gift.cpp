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
const unsigned Mod(10007);
unsigned m, n, Hr, Up, Dw, Sz;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char a[205];
unordered_map <unsigned, unsigned> S[205][205];
pair <unsigned, unsigned> Link[205];
inline void Pls(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
unsigned Tmp[1000005], * STop(Tmp);
struct Matrix {
  unsigned* Val[305];
  inline Matrix() {}
  inline Matrix(unsigned* x) {
    for (unsigned i(0); i < Hr; ++i) Val[i] = x, x += Hr;
    STop = x;
  }
  inline void operator= (const Matrix& x) { memcpy(Val[0], x.Val[0], Sz); }
  inline Matrix operator * (Matrix x) {
    unsigned* Lst(STop);
    Matrix Rt(STop);
    for (unsigned i(0); i < Hr; ++i) for (unsigned j(i); j < Hr; ++j) {
      Rt.Val[i][j] = 0;
      for (unsigned k(i); k <= j; ++k)
        Rt.Val[i][j] = (Rt.Val[i][j] + Val[i][k] * x.Val[k][j]) % Mod;
    }
    STop = Lst;
    return Rt;
  }
};
Matrix Pow(Matrix x, unsigned y) {
  unsigned* Lst(STop);
  Matrix Rt(STop), Pw(STop);
  Pw = x, memset(Rt.Val[0], 0, Sz);
  for (unsigned i(0); i < Hr; ++i) Rt.Val[i][i] = 1;
  while (y) { if (y & 1) Rt = Rt * Pw; Pw = Pw * Pw, y >>= 1; }
  STop = Lst;
  return Rt;
}
signed main() {
  scanf("%s", a + 1);
  n = strlen(a + 1), m = RD() + n;
  for (unsigned i(1); i <= n; ++i) S[0][i][0] = 1;
  for (unsigned i(1); i <= n; ++i) S[1][i][0] = 1;
  for (unsigned Len(2); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      if (a[i] ^ a[i + Len - 1]) {
        for (auto j : S[Len - 1][i])
          S[Len][i][j.first + 1] = S[Len][i][j.first + 1] + j.second, Pls(S[Len][i][j.first + 1]);
        for (auto j : S[Len - 1][i + 1])
          S[Len][i][j.first + 1] = S[Len][i][j.first + 1] + j.second, Pls(S[Len][i][j.first + 1]);
      }
      else for (auto j : S[Len - 2][i + 1])
        S[Len][i][j.first] = S[Len][i][j.first] + j.second, Pls(S[Len][i][j.first]);
    }
  }
  for (auto j : S[n][1]) Link[++Cnt] = make_pair(j.first, j.second);
  sort(Link + 1, Link + Cnt + 1);
  Up = Link[Cnt].first, Dw = Up + ((n - Link[1].first + 1) >> 1), Hr = Dw + 2, Sz = (Hr * Hr) << 2;
  Matrix Tr(STop);
  memset(Tr.Val[0], 0, Sz);
  for (unsigned i(1); i <= Up; ++i) Tr.Val[i][i] = 24;
  for (unsigned i(Up + 1); i <= Dw; ++i) Tr.Val[i][i] = 25;
  Tr.Val[Hr - 1][Hr - 1] = 26;
  for (unsigned i(1); i <= Up; ++i) Tr.Val[i - 1][i] = 1;
  for (unsigned i(Up + 1); i <= Dw; ++i) Tr.Val[i][i + 1] = 1;
  for (unsigned i(1); i <= Cnt; ++i)
    Tr.Val[Link[i].first][Dw - ((n - Link[i].first + 1) >> 1) + 1] = Link[i].second;
  Ans = Pow(Tr, ((m + 1) >> 1) + 1).Val[0][Hr - 1];
  if (m & 1) {
    for (unsigned i(1); i <= Cnt; ++i) if ((n - Link[i].first) & 1)
      Tr.Val[Link[i].first][Dw - ((n - Link[i].first + 1) >> 1) + 1] = 0;
    Ans += Mod - Pow(Tr, (m >> 1) + 1).Val[0][Hr - 2];
  }
  printf("%u\n", Ans % Mod);
  return Wild_Donkey;
}