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
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const char HexList[17] = "084C2A6E195D3B7F";
unsigned long long A, B;
unsigned C, D, t;
char Pp[65536], Hex[256], a[256], Flg(0);
inline unsigned long long myRand() {
  unsigned long long k3(A), k4(B);
  A = k4, k3 ^= (k3 << 23);
  B = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return B + k4;
}
unsigned n, m;
struct Word {
  unsigned short Val[16];
  inline void Rd() {
    scanf("%s", a), C = RD();
    for (unsigned i(63); ~i; --i) Val[i >> 2] <<= 4, Val[i >> 2] |= Hex[a[i]];
    if (Flg)
      for (unsigned i(0); i < 16; ++i) Val[i] ^= 0xFFFF;
  }
  inline const unsigned Diff(const Word& x) const {
    unsigned Rt(0);
    for (unsigned i(0); i < 16; ++i) Rt += Pp[Val[i] ^ x.Val[i]];
    return Rt;
  }
} Wd[400005], Q;
vector<unsigned> List[16][65536];
inline char Find() {
  for (unsigned j(0); j <= C; ++j)
    for (auto i : List[j][Q.Val[j]])
      if (Q.Diff(Wd[i]) <= C) return 1;
  return 0;
}
//  inline void Clr() {}
signed main() {
  // freopen("Test.in", "r", stdin);
  // freopen("P7738_-2.in", "r", stdin);
  // freopen("P7738.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  for (unsigned i(0); i < 65536; ++i) Pp[i] = Pp[i >> 1] + (i & 1);
  for (unsigned i(0); i < 16; ++i) Hex[HexList[i]] = i;
  n = RD(), m = RD(), A = RDll(), B = RDll();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j < 256; ++j)
      a[j] = (myRand() & ((unsigned long long)1 << 32)) ? 1 : 0;
    for (unsigned j(255); ~j; --j)
      Wd[i].Val[j >> 4] <<= 1, Wd[i].Val[j >> 4] |= a[j];
    for (unsigned j(0); j < 16; ++j) List[j][Wd[i].Val[j]].push_back(i);
  }
  for (unsigned i(1); i <= m; ++i) Q.Rd(), printf("%u\n", Flg = Find());
  //  }
  //  system("pause");
  return Wild_Donkey;
}
// g++ P7738_Drawer.cpp -o faq -std=c++14 -O2 -Wl,--stack=1024000000