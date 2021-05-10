#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#define Wild_Donkey 0
using namespace std;
unsigned m, n, Cnt(0), t, Ans(0), Tmp(0);
short nowCharacter;
char s[1000005];
struct Node {
  unsigned Length, Times; // 长度(等价类中最长的), 出现次数
  char endNode;           // 标记 (char 比 bool 快) 
  Node *backToSuffix, *SAMEdge[26];
}N[2000005], *CntN(N), *Last(N), *now(N), *A, *C_c;
inline unsigned DFS(Node *x) {
  unsigned tmp(0);
  if(x->endNode) {      
    tmp = 1; 
  }
  for (register unsigned i(0); i < 26; ++i) {
    if(x->SAMEdge[i]) {               // 有转移 i 
      if(x->SAMEdge[i]->Times > 0) {  // 被搜索过 
        tmp += x->SAMEdge[i]->Times;  // 直接统计 
      }
      else {                          // 未曾搜索 
        tmp += DFS(x->SAMEdge[i]);    // 搜索 
      }
    }
  }
  if (tmp > 1) {                      // 出现次数不为 1 
    Ans = max(Ans, tmp * x->Length);  // 尝试更新答案 
  }
  x->Times = tmp;                     // 存储子树和 
  return tmp;                         // 子树和用于搜索树上的父亲的统计 
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (register unsigned i(0); i < n; ++i) {
    Last = now;                                       // Last 指针往后移 
    A = Last;                                         // s 对应的节点
    nowCharacter = s[i] - 'a';                        // 取字符, 转成整数 
    now = (++CntN);                                   // s + c 对应的节点
    now->Length = Last->Length + 1;                   // len[s + c] = len[s]
    while (A && !(A->SAMEdge[nowCharacter])) {        // 跳到 A 有转移 c 的祖先 
      A->SAMEdge[nowCharacter] = now;                 // 没有转移 c, 创造转移 (Endpos = {len_s + 1})
      A = A->backToSuffix;
    }
    if(!A) {                                          // c 首次出现 
      now->backToSuffix = N;                          // 后缀链接连根
      continue;                                       // 直接进入下一个字符的加入 
    }
    if (A->Length + 1 == A->SAMEdge[nowCharacter]->Length) {  
      now->backToSuffix = A->SAMEdge[nowCharacter];   // len[a] + 1 = len[a->c] 无需分裂
      continue;
    }
    (++CntN)->Length = A->Length + 1;                 // 分裂出一个新点 
    C_c = A->SAMEdge[nowCharacter];                   // 原来的 A->c 变成 C->c 
    memcpy(CntN->SAMEdge, C_c->SAMEdge, sizeof(CntN->SAMEdge));
    CntN->backToSuffix = C_c->backToSuffix;           // 继承转移, 后缀链接 
    C_c->backToSuffix = CntN;                         // C -> c 是 A -> c 后缀链接树上的儿子
    now->backToSuffix = CntN;                         // 连上 s + c 的后缀链接 
    while (A && A->SAMEdge[nowCharacter] == C_c) {    // 这里要将 A 本来转移到 C->c 的祖先重定向到 A->c 
      A->SAMEdge[nowCharacter] = CntN;                // 连边
      A = A->backToSuffix;                            // 继续往上跳 
    }
  }
  while (now != N) {                                  // 打标记 
    now->endNode = 1;                                 // 从 s 向上跳 (从 s 到 root 这条链上都是结束点)
    now = now->backToSuffix;
  }
  DFS(N);                                             // 跑 DFS, 统计 + 更新 Ans 
  printf("%u\n", Ans);
  return Wild_Donkey;
}
