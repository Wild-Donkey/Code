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
const unsigned Five[8] = {1, 5, 25, 125, 625, 3125, 15625, 78125};
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
unsigned Q[390626], *Tl(Q), *Hd(Q), f[390625];
unsigned a, b, c, d, m, n, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { a = RD(), b = RD(), c = RD(), d = RD(), m = RD(); }
inline char Get(unsigned x, unsigned y) { return x / Five[y] % 5; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  memset(f, 0x3f, sizeof(f));
  for (unsigned i(0); i < 390625; ++i) {
    char Flg(0);
    for (unsigned j(0); j < 8; ++j) {
      unsigned Cur(Get(i, j));
      if ((Cur ^ 4) && (Cur ^ (j >> 1))) {
        Flg = 1;
        break;
      }
    }
    if (!Flg) f[i] = 0, *(++Tl) = i;
  }
  while (Hd != Tl) {
    unsigned Cur(*(++Hd)), From, C[8];
    for (unsigned i(0), j(Cur); i < 8; ++i, j /= 5) C[i] = j % 5;
    // if (Cur == 390534) {
    // printf("f[%u] = %u, Hd %u\n", Cur, f[Cur], Hd - Q);
    // }
    if ((C[4] == 4) && (C[5] == 4)) {  // Operation 1 (4 -> 0, 5 -> 1)
      // if (Cur == 390534) {
      //   printf("Here\n");
      // }
      if (C[0] ^ 4) {
        From = Cur - (4 - C[0]) * Five[4];
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[0] * (4 - C[0]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
      }
      if (C[1] ^ 4) {
        // if (Cur == 390534) {
        // printf("From %u %u\n", From, f[From]);
        // }
        From = Cur - (4 - C[1]) * Five[5];
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[1] * (4 - C[1]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
      }
      if ((C[0] ^ 4) && (C[1] ^ 4)) {
        From = Cur - (4 - C[0]) * Five[4] - (4 - C[1]) * Five[5];
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[0] * (4 - C[0]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[1] * (4 - C[1]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From -= Five[0] * (4 - C[0]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
      }
    }
    if ((C[2] == 4) && (C[3] == 4)) {  // Operation 1 (2 -> 6, 3 -> 7)
      if (C[6] ^ 4) {
        From = Cur - (4 - C[6]) * Five[2];
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[6] * (4 - C[6]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
      }
      if (C[7] ^ 4) {
        From = Cur - (4 - C[7]) * Five[3];
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[7] * (4 - C[7]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
      }
      if ((C[6] ^ 4) && (C[7] ^ 4)) {
        From = Cur - (4 - C[6]) * Five[2] - (4 - C[7]) * Five[3];
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[6] * (4 - C[6]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From += Five[7] * (4 - C[7]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
        From -= Five[6] * (4 - C[6]);
        if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
      }
    }
    if ((C[6] ^ C[4]) || (C[5] ^ C[7])) {  // Operation 3
      From = Cur + C[4] * Five[6] + C[6] * Five[4] + C[5] * Five[7] +
             C[7] * Five[5] - C[4] * Five[4] - C[5] * Five[5] - C[6] * Five[6] -
             C[7] * Five[7];
      if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
    }
    if ((C[1] ^ C[3]) || (C[5] ^ C[7])) {  // Operation 4
      From = Cur + C[1] * Five[3] + C[3] * Five[1] + C[5] * Five[7] +
             C[7] * Five[5] - C[1] * Five[1] - C[5] * Five[5] - C[3] * Five[3] -
             C[7] * Five[7];
      // printf("Cur %u From %u\n", Cur, From);
      if (f[From] > f[Cur] + 1) f[From] = f[Cur] + 1, *(++Tl) = From;
    }
  }
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    char Flg(0);
    unsigned C[8], Cur(0);
    for (unsigned i(0); i < 8; ++i) C[i] = 4;
    while (a | b | m | c | d) {
      // printf("%u %u %u %u %u\n", a, b, c, d, m);
      unsigned j(((a & 1) << 2) | ((b & 1) << 1) | (m & 1)),
          k(((c & 1) << 1) | (d & 1));
      if ((C[j] ^ 4) && (C[j] ^ k))
        Flg = 1;
      else
        C[j] = k;
      if (Flg) break;
      a >>= 1, b >>= 1, c >>= 1, d >>= 1, m >>= 1;
    }
    for (unsigned i(7); ~i; --i) Cur *= 5, Cur += C[i];
    // printf("Here %u\n", Cur);
    if (Flg)
      printf("-1\n");
    else if (f[Cur] == 0x3f3f3f3f)
      printf("-1\n");
    else
      printf("%u\n", f[Cur]);
  }
  //  system("pause");
  return Wild_Donkey;
}