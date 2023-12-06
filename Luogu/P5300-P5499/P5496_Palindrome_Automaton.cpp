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
unsigned m, n, Cnt(0), Ans(0), Tmp(0), Key;
bool flg(0);
char a[500005];
struct Node {
  Node *Link, *To[26];
  int Len;
  unsigned LinkLength;
} N[500005], *Order[500005], *CntN(N + 1), *Now(N), *Last(N);
int main() {
  fread(a + 1, 1, 500003, stdin);
  n = strlen(a + 1);
  N[0].Len = -1;
  N[1].Link = N;
  N[1].Len = 0;
  Order[0] = N + 1;
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] < 'a' || a[i] > 'z') { continue; }
    Now = Last = Order[i - 1];
    a[i] -= 'a';
    a[i] = ((unsigned)a[i] + Key) % 26;
    while (Now) {
      if (Now->Len + 1 < i) {
        if (a[i - Now->Len - 1] == a[i]) {  // 符合左端字符对应位置是 c
          if (Now->To[a[i]]) {  // 有转移 c, 不新建节点, 只记录 Order
            Order[i] = Now->To[a[i]];
            flg = 1;  // 标记表示本轮没有节点被新建
          } else {
            Now->To[a[i]] = ++CntN;    // 转移
            CntN->Len = Now->Len + 2;  // 长度 +2 (左右两端加 c)
            Order[i] = CntN;           // 记录 Order
          }
          break;
        }
      }
      Last = Now;  // 记录上一个节点, 优化下一次跳 Link 链的次数 (下一次跳是找
                   // Order_i 的 Link)
      Now = Now->Link;  // 跳 Link
    }
    if (!flg) {  // 有新节点, 连接这个点的 Link
      Now = Last;
      while (Now) {
        if (Now->To[a[i]]) {                         // 有转移 c
          if (Now->To[a[i]]->Len < Order[i]->Len) {  // 长度合法
            if (a[i - Now->Len - 1] ==
                a[i]) {  // 该节点左端包含于 Order_i->Link 的后缀
              Order[i]->Link = Now->To[a[i]];
              Order[i]->LinkLength = Now->To[a[i]]->LinkLength + 1;
              break;  // 找到 Link
            }
          }
        }
        Now = Now->Link;  // 跳 Link
      }
      if (!Now) {  // 无合适的 Link, 连向偶根
        Order[i]->Link = N + 1;
        Order[i]->LinkLength = 1;
      }
    } else {  // 有标记说明无新节点, 清空标记
      flg = 0;
    }
    Key = Order[i]->LinkLength;
    printf("%d ", Key);
  }
  return Wild_Donkey;
}
