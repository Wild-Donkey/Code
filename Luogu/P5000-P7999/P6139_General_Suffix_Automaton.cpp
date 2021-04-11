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
  Node *To[26], *Father, *Link;                       // GSAM ת�Ʊ�, GSAM ����ָ��, ��׺����ָ�� 
  char Visited, Character, toAgain[26];               // �� char ����Ϊ���� bool ��, toAgain[] ��Ҫ�Ļ����Գ����� unsigned ״ѹ�������� 
  unsigned Length;
}N[2000005], *now(N), *CntN(N), *Queue[1000005], *A, *C_c;
inline void Clr() {}
int main() {
  n = RD();
  N[0].Length = 0; 
  for (register unsigned i(1); i <= n; ++i) {         // ���� + �� Trie 
    scanf("%s", s);                                   // �ַ�ת����Ȼ�� 
    len = strlen(s);
    now = N;
    for (register unsigned j(0); j < len; ++j) {
      s[j] -= 'a';
      if(!(now->To[s[j]])) {
        now->To[s[j]] = ++CntN;
        CntN->Father = now;
        CntN->Character = s[j];
        CntN->Length = now->Length + 1;               // ˳���ų�ʼ��һЩ��Ϣ 
      }
      now = now->To[s[j]];
    }
  }
  Queue[++queueTail] = N;                             // ��ʼ������, ׼�� BFS 
  while (queueHead < queueTail) {                     // �򵥵� BFS 
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
  for (register unsigned i(2); i <= queueTail; ++i) { // BFS ���µĶ��б��� BFS ��, �����һ����ͨ�ĺ�׺�Զ������� 
    now = Queue[i];                                   // �����е�˳����в���, ��֤ Link �����Ľڵ��Ѿ����� 
    A = now->Father; 
    while (A && !(A->toAgain[now->Character])) {      // �� Link �� + ��ת�Ʊ� 
      A->toAgain[now->Character] = 1;                 // ԭ���� Trie �߲����� GSAM ��, ����� toAgain Ϊ���˵�� GSAM �����ת�� 
      A->To[now->Character] = now;
      A = A->Link;
    }
    if(!A) {                                          // �޶�Ӧ�ַ�ת�� 
      now->Link = N;
      continue;
    }
    if((A->Length + 1) ^ (A->To[now->Character]->Length)) {
      C_c = A->To[now->Character];
      (++CntN)->Length = A->Length + 1;               // ���˺þõ�����, ��Ҫ���ض���֮ǰ����������ǰת�� A->c 
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
    now->Link = A->To[now->Character];                // ����ת��, ֱ���� Link 
  }
  for (register Node *i(N + 1); i <= CntN; ++i) {
    Ans += i->Length - i->Link->Length;               // ͳ���ִ��� 
  }
  printf("%llu\n", Ans);
  return Wild_Donkey;
}



