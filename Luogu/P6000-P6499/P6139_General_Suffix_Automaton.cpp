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
unsigned a[10005], m, n, Cnt(0), t, Tmp(0), len(0), queueHead(0), queueTail(0);
unsigned long long Ans(0); 
bool b[10005];
char s[1000006];
struct Node {
  Node *To[26], *Father, *Link;                       // GSAM 转移边, GSAM 父亲指针, 后缀链接指针 
  char Visited, Character, toAgain[26];               // 用 char 是因为它比 bool 快, toAgain[] 必要的话可以尝试用 unsigned 状压代替数组 
  unsigned Length;
}N[2000005], *now(N), *CntN(N), *Queue[1000005], *A, *C_c;
inline void Clr() {}
int main() {
  n = RD();
  N[0].Length = 0; 
  for (register unsigned i(1); i <= n; ++i) {         // 读入 + 建 Trie 
    scanf("%s", s);                                   // 字符转成自然数 
    len = strlen(s);
    now = N;
    for (register unsigned j(0); j < len; ++j) {
      s[j] -= 'a';
      if(!(now->To[s[j]])) {
        now->To[s[j]] = ++CntN;
        CntN->Father = now;
        CntN->Character = s[j];
        CntN->Length = now->Length + 1;               // 顺带着初始化一些信息 
      }
      now = now->To[s[j]];
    }
  }
  Queue[++queueTail] = N;                             // 初始化队列, 准备 BFS 
  while (queueHead < queueTail) {                     // 简单的 BFS 
    now = Queue[++queueHead];
    for (register char i(0); i < 26; ++i) {
      if(now->To[i]) {
        if(!(now->To[i]->Visited)) {
          Queue[++queueTail] = now->To[i];
          now->To[i]->Visited = 1;
        }
      }
    }
  }
  for (register unsigned i(2); i <= queueTail; ++i) { // BFS 留下的队列便是 BFS 序, 这便是一个普通的后缀自动机构建 
    now = Queue[i];                                   // 按队列的顺序进行插入, 保证 Link 跳到的节点已经插入 
    A = now->Father; 
    while (A && !(A->toAgain[now->Character])) {      // 跳 Link 边 + 连转移边 
      A->toAgain[now->Character] = 1;                 // 原来的 Trie 边不代表 GSAM 边, 这里的 toAgain 为真才说明 GSAM 有这个转移 
      A->To[now->Character] = now;
      A = A->Link;
    }
    if(!A) {                                          // 无对应字符转移 
      now->Link = N;
      continue;
    }
    if((A->Length + 1) ^ (A->To[now->Character]->Length)) {
      C_c = A->To[now->Character];
      (++CntN)->Length = A->Length + 1;               // 调了好久的问题, 不要在重定向之前自作主张提前转移 A->c 
      CntN->Link = C_c->Link;
      memcpy(CntN->To, C_c->To, sizeof(C_c->To));
      memcpy(CntN->toAgain, C_c->toAgain, sizeof(C_c->toAgain));
      now->Link = CntN;
      C_c->Link = CntN;
      CntN->Character = C_c->Character;
      while (A && A->To[C_c->Character] == C_c) {
        A->To[C_c->Character] = CntN;
        A = A->Link; 
      }
      continue;
    }
    now->Link = A->To[now->Character];                // 连续转移, 直接连 Link 
  }
  for (register Node *i(N + 1); i <= CntN; ++i) {
    Ans += i->Length - i->Link->Length;               // 统计字串数 
  }
  printf("%llu\n", Ans);
  return Wild_Donkey;
}



