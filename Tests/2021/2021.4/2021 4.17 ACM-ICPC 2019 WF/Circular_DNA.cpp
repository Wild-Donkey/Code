#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), List[1000005], Pos(0);
char Character;
int Sum[1000005], Lend[1000005];
struct DNA {
  unsigned Number;  // 编号 
  int SE;           // s or e, 即权值 
}a[1000005];
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {   // 读入 
    Character = getchar();
    while (Character != 's' && Character != 'e') {
      Character = getchar();
    }
    if(Character == 's') {
      a[i].SE = 1;
    }
    else {
      a[i].SE = -1;
    }
    a[i].Number = RD();
    if(!Lend[a[i].Number]) {
      Lend[a[i].Number] = 1;
      List[++Cnt] = a[i].Number;
    }
  }
  Pos = 1;
  memset(Lend, 0x3f, sizeof(Lend));           //
  for (register unsigned i(1); i <= n; ++i) {
    Sum[a[i].Number] += a[i].SE;
    Lend[a[i].Number] = min(Lend[a[i].Number], Sum[a[i].Number]);
  }
  for (register unsigned i(1); i <= Cnt; ++i) {
    if(Lend[List[i]] == 0 && Sum[List[i]] == 0) {
      ++Tmp;
    }
  }
  Pos = 1, Ans = Tmp;
  for (register unsigned i(1); i < n; ++i) {  // 枚举断点 
    if(!(Sum[a[i].Number] ^ 0)) {             // 优化常数, 等价于 if(Sum[a[i].Number] == 0) 
      if(a[i].SE ^ (-1)) {                    // 
      
        if(!(Lend[a[i].Number] == 0)) {
          --Tmp;
        }
        --Lend[a[i].Number];
      }
      else {
        ++Lend[a[i].Number];
        if(!(Lend[a[i].Number] ^ 0)) {
          ++Tmp;
        }
      }
    }
    if(Tmp > Ans) { 
      Pos = i + 1;
      Ans = Tmp;
    }
  }
  printf("%u %u", Pos, Ans);
  return Wild_Donkey;
}
