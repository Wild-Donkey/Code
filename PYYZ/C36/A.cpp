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
#define IO 10000
#define Wild_Donkey 0
char _ibuf[IO], _obuf[IO], * _i = _ibuf, * _o = _obuf;
inline void initIO() { fread(_ibuf, sizeof(char), IO, stdin); }
inline void endIO() { fwrite(_obuf, sizeof(char), _o - _obuf, stdout); }
static inline char getch() {
  if (_i == _ibuf + IO) {
    memset(_ibuf, 0, sizeof(_ibuf));
    fread(_ibuf, sizeof(char), IO, stdin);
    _i = _ibuf;
  }
  return *_i++;
}
static inline void putch(char ch) {
  if (_o == _obuf + IO) { fwrite(_obuf, sizeof(char), IO, stdout), _o = _obuf; }
  *_o++ = ch;
}
inline unsigned short RD() {
  unsigned short intmp(0);
  char rdch(getch());
  while (rdch < '0' || rdch > '9') rdch = getch();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getch();
  return intmp;
}
inline unsigned RDl() {
  unsigned intmp(0);
  char rdch(getch());
  while (rdch < '0' || rdch > '9') rdch = getch();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getch();
  return intmp;
}
inline void putint(unsigned short val) {
  if (val >= 10) putint(val / 10);
  putch(val % 10 + '0');
}
unsigned n, m, Cur(0);
unsigned short a[10005], List[10000005], * Hd(List), * Tl(List), Stack[10000005], * STop(Stack);
char s;
//  inline void Clr() {}
signed main() {
  // freopen("staqueue3.in", "r", stdin);
  // freopen("staqueue.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  initIO(), n = RDl();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  m = RDl();
  if (!m) return Wild_Donkey;
  // s = getch();
  for (unsigned i(1); i <= m; ++i) {
    s = getch();// printf("Now %u %c\n", i, s[i]);
    switch (s) {
    case '1': {
      ++Cur, Cur -= (Cur > n) ? n : 0, * (++Tl) = a[Cur];
      break;
    }
    case '2': {
      *(++STop) = *(++Hd);
      break;
    }
    case '3': {
      *(++STop) = *(Tl--);
      break;
    }
    case '4': {
      char Flg(0);
      for (unsigned short* j(Stack + 1); j <= STop; ++j) if (Flg || (*j)) Flg = 1, putint(*j);
      if (!Flg) putint(0);
      putch(0x0A), STop = Stack;
      break;
    }
    }
  }
  endIO();
  //  }
  //  system("pause");
  return Wild_Donkey;
}