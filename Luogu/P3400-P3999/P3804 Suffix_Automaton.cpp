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
unsigned m, n, Cnt(0), t, Ans(0), Tmp(0);
short nowCharacter;
char s[1000005];
struct Node {
  unsigned Length, Times;
  char endNode;
  Node *backToSuffix, *SAMEdge[26];
}N[2000005], *CntN(N), *Last(N), *now(N), *A, *C_c;
unsigned DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  unsigned tmp(0);
  if(x->endNode) {
    tmp = 1; 
  }
  for (register unsigned i(0); i < 26; ++i) {
    if(x->SAMEdge[i]) {
//      printf("%u Times %u\n", x->SAMEdge[i] - N, x->SAMEdge[i]->Times);
      if(x->SAMEdge[i]->Times > 0 && x->SAMEdge[i]->Times < 0x3f3f3f3f) {
        tmp += x->SAMEdge[i]->Times;
      }
      else {
        tmp += DFS(x->SAMEdge[i]);
      }
    }
  }
  if (tmp > 1) {
    Ans = max(Ans, tmp * x->Length);
  }
  x->Times = tmp;
  return tmp;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (register unsigned i(0); i < n; ++i) {
    Last = now;
    A = Last;
    nowCharacter = s[i] - 'a';
    now = (++CntN);                                   // s + c 对应的节点
    now->Length = Last->Length + 1;
//    CntN->endNode = 1;
    while (A && !(A->SAMEdge[nowCharacter])) {
      A->SAMEdge[nowCharacter] = now;                 // 没有转移 c, 创造转移 (Endpos = {len_s + 1})
      A = A->backToSuffix;
    }
    if(!A) {
      now->backToSuffix = N;                          // 后缀链接连根
      continue;
    }
    if (A->Length + 1 == A->SAMEdge[nowCharacter]->Length) {  
      now->backToSuffix = A->SAMEdge[nowCharacter];   // 无需分裂
      continue;
    }
    (++CntN)->Length = A->Length + 1;
    C_c = A->SAMEdge[nowCharacter];
    memcpy(CntN->SAMEdge, C_c->SAMEdge, sizeof(CntN->SAMEdge));
    CntN->backToSuffix = C_c->backToSuffix;           // 继承父亲 
    C_c->backToSuffix = CntN;                         // C -> c 是 A -> c 后缀链接树上的儿子
    now->backToSuffix = CntN;                         // 连上 Link
    while (A && A->SAMEdge[nowCharacter] == C_c) {
      A->SAMEdge[nowCharacter] = CntN;                // 连边
      A = A->backToSuffix;
    }
  }
  while (now != N) {
    now->endNode = 1;
    now = now->backToSuffix;
  }
  DFS(N);
  printf("%u\n", Ans);
  return Wild_Donkey;
}
/*
babaabbbbbbabbaabaaaaabbbaabaabaabbabaaabababaaabbbbabbbaaabbbabbaababbbabbaabaaaaabbbaabaabaabbabbaabaaabbbbabbbaaabbbaababbbbbbaaababbbbabbaabaaaaabbbaabaabaabbabbababaabaaabbbbabbbaaabbbabbbaaaababaabbbbabbaabaaaaabbbaabaabaabbabbababaaabbbbabbbaaabbbaababbbabbaabaaaaabbbaabaabaabbababbabaaabbbbabbbaaabbbabaabaaaabbbbbabbaabaaaaabbbaabaabaabbabababaabaaabbbbabbbaaabbbbbaaabbbabbabbaabbbabbaabaaaaabbbaabaabaabbabbabbaaabbbbabbbaaabbbabbaaabbababbbabbaabaaaaabbbaabaabaabbabababbaaabbbbabbbaaabbbbaabbabaaabbbabbaabaaaaabbbaabaabaabbabaabaaabbbbabbbaaabbbbabbaabaaabbbabbaabaaaaabbbaabaabaabbabababbabbbbaaabbbbabbbaaabbbbbbbabbaaabbbabbaabaaaaabbbaabaabaabbabbbbaaabbbbabbbaaabbbabaabbabbbabbaabaaaaabbbaabaabaabbabbbbaabbababaaabbbbabbbaaabbbabbabaabbbabbaabaaaaabbbaabaabaabbabaabbbaaabbbbabbbaaabbbaaabbaababbbbbabbaabaaaaabbbaabaabaabbabaaabbaaabbbbabbbaaabbbbaaaababaabbbabbaabaaaaabbbaabaabaabbabbbaaabbbbabbbaaabbbaabbbbabbaabaaaaabbbaabaabaabbabbbabbbaaabbbbabbbaaabbbbabababbaabaaababa
*/
