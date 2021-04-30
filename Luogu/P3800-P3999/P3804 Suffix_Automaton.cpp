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
  unsigned Length, Times; // ����(�ȼ��������), ���ִ���
  char endNode;           // ��� (char �� bool ��) 
  Node *backToSuffix, *SAMEdge[26];
}N[2000005], *CntN(N), *Last(N), *now(N), *A, *C_c;
inline unsigned DFS(Node *x) {
  unsigned tmp(0);
  if(x->endNode) {      
    tmp = 1; 
  }
  for (register unsigned i(0); i < 26; ++i) {
    if(x->SAMEdge[i]) {               // ��ת�� i 
      if(x->SAMEdge[i]->Times > 0) {  // �������� 
        tmp += x->SAMEdge[i]->Times;  // ֱ��ͳ�� 
      }
      else {                          // δ������ 
        tmp += DFS(x->SAMEdge[i]);    // ���� 
      }
    }
  }
  if (tmp > 1) {                      // ���ִ�����Ϊ 1 
    Ans = max(Ans, tmp * x->Length);  // ���Ը��´� 
  }
  x->Times = tmp;                     // �洢������ 
  return tmp;                         // �����������������ϵĸ��׵�ͳ�� 
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (register unsigned i(0); i < n; ++i) {
    Last = now;                                       // Last ָ�������� 
    A = Last;                                         // s ��Ӧ�Ľڵ�
    nowCharacter = s[i] - 'a';                        // ȡ�ַ�, ת������ 
    now = (++CntN);                                   // s + c ��Ӧ�Ľڵ�
    now->Length = Last->Length + 1;                   // len[s + c] = len[s]
    while (A && !(A->SAMEdge[nowCharacter])) {        // ���� A ��ת�� c ������ 
      A->SAMEdge[nowCharacter] = now;                 // û��ת�� c, ����ת�� (Endpos = {len_s + 1})
      A = A->backToSuffix;
    }
    if(!A) {                                          // c �״γ��� 
      now->backToSuffix = N;                          // ��׺��������
      continue;                                       // ֱ�ӽ�����һ���ַ��ļ��� 
    }
    if (A->Length + 1 == A->SAMEdge[nowCharacter]->Length) {  
      now->backToSuffix = A->SAMEdge[nowCharacter];   // len[a] + 1 = len[a->c] �������
      continue;
    }
    (++CntN)->Length = A->Length + 1;                 // ���ѳ�һ���µ� 
    C_c = A->SAMEdge[nowCharacter];                   // ԭ���� A->c ��� C->c 
    memcpy(CntN->SAMEdge, C_c->SAMEdge, sizeof(CntN->SAMEdge));
    CntN->backToSuffix = C_c->backToSuffix;           // �̳�ת��, ��׺���� 
    C_c->backToSuffix = CntN;                         // C -> c �� A -> c ��׺�������ϵĶ���
    now->backToSuffix = CntN;                         // ���� s + c �ĺ�׺���� 
    while (A && A->SAMEdge[nowCharacter] == C_c) {    // ����Ҫ�� A ����ת�Ƶ� C->c �������ض��� A->c 
      A->SAMEdge[nowCharacter] = CntN;                // ����
      A = A->backToSuffix;                            // ���������� 
    }
  }
  while (now != N) {                                  // ���� 
    now->endNode = 1;                                 // �� s ������ (�� s �� root �������϶��ǽ�����)
    now = now->backToSuffix;
  }
  DFS(N);                                             // �� DFS, ͳ�� + ���� Ans 
  printf("%u\n", Ans);
  return Wild_Donkey;
}
