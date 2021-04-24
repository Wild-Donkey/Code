#include <cstdio>
#include <iostream>
#define Wild_Donkey 0
using namespace std;
unsigned n, Cnt(0), Ans(0), Tmp(0), List[1000005], Pos(0);
char Character;
int Sum[1000005], Low[1000005];
struct DNA {
  unsigned Number;  // 编号 
  int SE;           // s or e, 即权值 
}a[1000005];
int main() {
  scanf("%u", &n);
  for (register unsigned i(1); i <= n; ++i) { // 读入 
    Character = getchar();
    while (Character != 's' && Character != 'e') {
      Character = getchar();
    }
    if(Character == 's') {                    // 上括号 
      a[i].SE = 1;
    }
    else {                                    // 下括号 
      a[i].SE = -1;
    }
    scanf("%u", &a[i].Number);
    if(!Low[a[i].Number]) {                   // 这个编号的基因首次出现
      Low[a[i].Number] = 1;                   // 打标记表示这个编号的基因出现过 
      List[++Cnt] = a[i].Number;              // 记录在基因列表中 
    }
  }
  Pos = 1;
  for (register unsigned i(1); i <= n; ++i) {
    Sum[a[i].Number] += a[i].SE;              // 累计总和 
    Low[a[i].Number] = min(Low[a[i].Number], Sum[a[i].Number]); // 更新前缀和历史最小值 
  }
  for (register unsigned i(1); i <= Cnt; ++i) {// 真核生物  (枚举基因编号)
    if(Low[List[i]] == 0 && Sum[List[i]] == 0) {// 同时满足两个条件 
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
      Pos = i + 1;
      Ans = Tmp;
    }
  }
  printf("%u %u", Pos, Ans);
  return Wild_Donkey;
}
