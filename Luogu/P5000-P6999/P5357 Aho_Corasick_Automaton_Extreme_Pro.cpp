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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned n, L(0), R(0), Tmp(0), Cnt(0);
char inch;
struct Node;
struct Edge {
  Edge *Nxt;
  Node *To;
}E[200005], *Cnte(E);
struct Node {
  Node *Son[26], *Fa, *Fail;
  char Ch;
  Edge *Fst;
  bool Exist;
  unsigned Size, Times;
}N[200005], *Q[200005], *now(N), *Cntn(N), *Find(N), *Ans[200005];
inline void Clr() {}
unsigned DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  Edge *Sid(x->Fst);  // 枚举当前节点所有出边 
  x->Size = x->Times; // 自己的扫描次数也要统计 
  now = x;
  while (Sid) {
    now = Sid->To;
    x->Size += DFS(now);  // 统计子节点的子树值 
    Sid = Sid->Nxt;
  }
  return x->Size;     // 返回自己的子树值 
} 
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while (inch < 'a' || inch > 'z') {//跳过无关字符 
      inch = getchar();
    }
    now = N;  // 从根开始 
    while (inch >= 'a' && inch <= 'z') {
      inch -= 'a';    // 字符转化为下标 
      if(!(now->Son[inch])) { // 新节点 
        now->Son[inch] = ++Cntn;
        Cntn->Ch = inch;
        Cntn->Fa = now;
      }
      now = now->Son[inch]; // 往下走 
      inch = getchar();
    }
    if (!(now->Exist)) { //新串 (原来不存在以这个点结尾的模式串)
      now->Exist = 1;
    }
    Ans[i] = now; // 记录第 i 个串尾所在节点 
  }
  for (register short i(0); i < 26; ++i) {  // 对第一层的特殊节点进行边界处理 
    if(N->Son[i]) {           // 根的儿子 
      Q[++R] = N->Son[i];     // 入队 
      N->Son[i]->Fail = N;    // Fail 往上连, 所以只能连向根
      (++Cnte)->Nxt = N->Fst; // 反向边, 用边表存 
      N->Fst = Cnte;
      Cnte->To = N->Son[i];
    }
  }
  while (L < R) { // BFS 连边, 建自动机 
    now = Q[++L]; // 取队首并弹出 
//    printf("BFS %u %u %u\n", L, R, now - N);
    for (register short i(0); i < 26; ++i) {
      if(now->Son[i]) {
        Q[++R] = now->Son[i];
      }
    }
    if(!(now->Fa)) {
      continue;
    }
    Find = now->Fa->Fail; // 从父亲的 Fail 开始往上跳, 直到找到 
    while (Find) {
      if(Find->Son[now->Ch]) {                    // 找到了 (边界)
//        printf("Got %u %u\n", Find-N, now-N);
        now->Fail = Find->Son[now->Ch];           // 正向边 (往上连)
        (++Cnte)->Nxt = Find->Son[now->Ch]->Fst;  // 反向边 (往下连) 
        Find->Son[now->Ch]->Fst = Cnte;
        Cnte->To = now;
        break;
      }
      Find = Find->Fail;  // 继续往前跳 
    }
    if(!(now->Fail)) {
      now->Fail = N;  // 所有找不到对应 Fail 的节点, Fail 均指向根 
      (++Cnte)->Nxt = N->Fst;
      N->Fst = Cnte;
      Cnte->To = now;
    }
//    printf("%u Fail %u\n", now-N, (now->Fail) - N);
  }
//  for (register Edge *i(E); i <= Cnte; ++i) {
//    printf("Edge %u %u %u\n", i - E, i->Nxt - E, i->To - N);
//  }
  while (inch < 'a' || inch > 'z') {
    inch = getchar();
  }
  now = N;
  while (inch >= 'a' && inch <= 'z') {  // 自动机扫一遍 
    inch -= 'a';
    if(!now) {  // 如果完全失配了, 则从根开始新的匹配, 否则接着前面已经匹配成功的节点继续匹配 
      now = N;
    }
//    printf("%u %c\n", now-N, inch + 'a'); 
    while(now) {              // 完全失配, 跳出 
      if(now->Son[inch]) {    // 匹配成功, 同样跳出 
        now = now->Son[inch]; // 自动机对应节点和字符串同步往下走 
        ++(now->Times);       // 记录节点扫描次数 
        break;
      }
      now = now->Fail;        // 跳 Fail 
    }
    inch = getchar();
  }
  DFS(N); // 统计互相包含的模式串 
  for (register unsigned i(1); i <= n; ++i) {
    printf("%u\n", Ans[i]->Size); // 根据之前记录的第 i 个模式串尾字符对应的节点的指针找到需要的答案 
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
