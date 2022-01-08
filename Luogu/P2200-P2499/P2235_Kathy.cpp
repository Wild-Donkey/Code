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
unsigned m(0), C, D, t;
unsigned Cnt(0), Ans(0);
char BTT[355][115];
struct Bin {
  bitset<355> Nu;
  inline Bin() { Nu = 0; }
  inline Bin(unsigned x) { Nu = x; }
  const inline char operator < (const Bin& x)const {
    for (unsigned i(350); ~i; --i) if (Nu[i] ^ x.Nu[i]) return x.Nu[i];
    return 0;
  }
  inline Bin operator << (const unsigned& x) {
    Bin New(*this);
    New.Nu <<= x;
    return New;
  }
  inline Bin operator >> (const unsigned& x) {
    Bin New(*this);
    New.Nu >>= x;
    return New;
  }
  inline Bin operator + (const Bin& x) {
    Bin New(x);
    bitset <355> Tmp(Nu), Tmp2;
    while (Tmp.count()) {
      Tmp2 = New.Nu & Tmp;
      New.Nu ^= Tmp;
      Tmp = Tmp2 << 1;
    }
    return New;
  }
  inline void operator += (const unsigned& x) {
    Bin X(x);
    unsigned Tmp(0), Up(0);
    for (unsigned i(0); i <= 350; ++i) {
      Tmp = Nu[i] + Up + X.Nu[i];
      Nu[i] = Tmp & 1;
      Up = Tmp >> 1;
    }
  }
  inline void operator += (const Bin& x) {
    bitset <355> Tmp(x.Nu), Tmp2;
    while (Tmp.count()) {
      Tmp2 = Nu & Tmp;
      Nu ^= Tmp;
      Tmp = Tmp2 << 1;
    }
  }
  inline void operator -= (const unsigned& x) {
    Bin X(x);
    int Tmp;
    unsigned Up(0);
    for (unsigned i(0); i <= 350; ++i) {
      Tmp = Nu[i] - Up - X.Nu[i];
      Up = 0;
      while (Tmp < 0) Tmp += 2, ++Up;
      Nu[i] = Tmp & 1;
    }
  }
  inline Bin operator * (const unsigned x) {
    Bin New;
    New.Nu = 0;
    for (unsigned i(0); i <= 31; ++i) if (x & (1 << i)) New += ((*this) << i);
    return New;
  }
  inline void operator *= (const unsigned x) {
    Bin Tmp(*this);
    Nu = 0;
    for (unsigned i(0); i <= 31; ++i) if (x & (1 << i)) (*this) += (Tmp << i);
  }
  inline void RD() {
    char rdch[115];
    unsigned L(0), R(0);
    memset(rdch, 0, sizeof(rdch));
    scanf("%s", rdch);
    Nu = 0;
    while (rdch[L] < '0' || rdch[L] > '9') ++L; R = L;
    while (rdch[R] >= '0' && rdch[R] <= '9')++R;
    // printf("[%u, %u)", L, R);
    for (unsigned i(L); i < R; ++i) {
      (*this) *= 10, (*this) += rdch[i] - '0';
    }
    // for (unsigned i(0); i <= 100; ++i) putchar(Nu[i] ? '1' : '0');
    // putchar(0x0A);
  }
  inline void Print() {
    unsigned List[115], Mx(0);
    memset(List, 0, sizeof(List));
    for (unsigned i(0); i <= 350; ++i) if (Nu[i])
      for (unsigned j(0); j <= 110; ++j) List[j] += BTT[i][j];
    for (unsigned i(0), Up(0); i <= 110; ++i) {
      List[i] = List[i] + Up;
      Up = List[i] / 10;
      List[i] %= 10;
      if (List[i]) Mx = i;
    }
    for (unsigned i(Mx); ~i; --i) putchar('0' + List[i]);
    putchar('\n');
  }
}n, A, B;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  BTT[0][0] = 1;
  for (unsigned i(1); i <= 350; ++i) {
    // printf("%u :", i);
    for (unsigned j(0), Up(0); j <= 110; ++j) {
      BTT[i][j] = (BTT[i - 1][j] << 1) + Up;
      Up = BTT[i][j] / 10;
      BTT[i][j] %= 10;
      // putchar(BTT[i][j] + '0');
    }
    // putchar('\n');
  }
  n.RD();
  for (unsigned i(0); i <= 350; ++i) if (n.Nu[i]) m = i;
  B = 0, A = n;// printf("%u\n", m);
  for (unsigned i(m >> 1); ~i; --i) A.Nu[i] = A.Nu[m - i];
  for (unsigned i(m >> 1); ~i; --i) B.Nu[i] = A.Nu[i + ((m + 1) >> 1)];
  B.Nu[m >> 1] = 0;
  B += 1;
  if (n < A) B -= 1;
  A = 0, A.Nu[0] = 1;
  for (unsigned i(0); i < m; ++i) {
    B += A;
    if (i & 1) A.Nu <<= 1;
  }
  B.Print();
  //  }
  // system("pause");
  return Wild_Donkey;
}