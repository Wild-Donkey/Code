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
unsigned n, Cnt(0), Ans(0), Tmp(0), List[1000005], Pos(0);
char Character;
int Sum[1000005], Low[1000005];
struct DNA {
  unsigned Number;  // 编号 
  int SE;           // s or e, 即权值 
}a[1000005];
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) { // 读入 
    Character = getchar();
    while ((Character ^ 's') && (Character ^ 'e')) {
      Character = getchar();
    }
    a[i].SE = (Character ^ 's') ? -1 : 1, a[i].Number = RD();
    if(!Low[a[i].Number]) {                   // 这个编号的基因首次出现
      Low[a[i].Number] = 1, List[++Cnt] = a[i].Number;              // 记录在基因列表中 
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    Sum[a[i].Number] += a[i].SE, Low[a[i].Number] = (Low[a[i].Number] < Sum[a[i].Number]) ? Low[a[i].Number] : Sum[a[i].Number]; // 更新前缀和历史最小值 
  }
  for (register unsigned i(1); i <= Cnt; ++i) {// 真核生物  (枚举基因编号)
    if(!((Low[List[i]] | Sum[List[i]]) ^ 0)) {// 同时满足两个条件 
      ++Tmp;
    }
  }
  Pos = 1, Ans = Tmp;                         // 对于真核生物的运行结果
  for (register unsigned i(1); i < n; ++i) {  // 枚举断点, 这里是从 i 后面切断, 所以原左端基因是 a[i] 
    if(!(Sum[a[i].Number] ^ 0)) {             // 优化常数, 等价于 if(Sum[a[i].Number] == 0) 
      if(a[i].SE ^ (-1)) {                    // 优化同上, 这是 sx 的情况 
        if(!(Low[a[i].Number] ^ 0)) {         // 原本完美, 修改后不完美了 
          --Tmp;
        }
        --Low[a[i].Number];                   // 最后修改 Low[x] 
      }
      else {                                  // 这是 ex 的情况 
        ++Low[a[i].Number];                   // 先修改 Low[x] 
        if(!(Low[a[i].Number] ^ 0)) {         // 原本不是完美匹配, 但是现在完美了 
          ++Tmp;
        }
      }
    }
    if(Tmp > Ans) {                           // 新断点严格优于原先才更新 
      Pos = i + 1, Ans = Tmp;
    }
  }
  printf("%u %u", Pos, Ans);
  return Wild_Donkey;
}
