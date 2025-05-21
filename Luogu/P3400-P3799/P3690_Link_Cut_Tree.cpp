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
unsigned a[10005], n, m, Cnt(0), Tmp(0), Mx;
bool flg(0);
char inch, List[155][75];
struct Node {
  Node *Son[2], *Fa;
  char Tag;
  unsigned Value, Sum;
}N[100005], *Stack[100005];
inline void Update(Node *x) {
  x->Sum = x->Value;
  if(x->Son[0]) {
    x->Sum ^= x->Son[0]->Sum;
  }
  if(x->Son[1]) {
    x->Sum ^= x->Son[1]->Sum;
  }
  return;
}
inline void Push_Down(Node *x) {  // Push_Down the spliting tag
  if(x->Tag) {
    register Node *TmpSon(x->Son[0]);
    x->Tag = 0, x->Son[0] = x->Son[1], x->Son[1] = TmpSon; 
    if(x->Son[0]) {
      x->Son[0]->Tag ^= 1;
    }
    if(x->Son[1]) {
      x->Son[1]->Tag ^= 1;
    }
  }
}
inline void Rotate(Node *x) {
  register Node *Father(x->Fa);
  x->Fa = Father->Fa; // x link to grandfather
  if(Father->Fa) {
    if(Father->Fa->Son[0] == Father) {
      Father->Fa->Son[0] = x;  // grandfather link to x
    }
    if(Father->Fa->Son[1] == Father) {
      Father->Fa->Son[1] = x;  // grandfather link to x
    }
  }
  x->Sum = 0, Father->Fa = x;
  if(Father->Son[0] == x) {
    Father->Son[0] = x->Son[1];
    if(Father->Son[0]) {
      Father->Son[0]->Fa = Father;
    }
    x->Son[1] = Father;
    if(x->Son[0]) {
      x->Sum = x->Son[0]->Sum;
    }
  }
  else {
    Father->Son[1] = x->Son[0];
    if(Father->Son[1]) {
      Father->Son[1]->Fa = Father;
    }
    x->Son[0] = Father;
    if(x->Son[1]) {
      x->Sum = x->Son[1]->Sum;
    }
  }
  Update(Father);
  x->Sum ^= x->Value ^ Father->Sum;
  return;
}
void Splay (Node *x) {
  register unsigned Head(0);
  while (x->Fa) {                                       // ����û��ͷ
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {      // x is the preferred-edge linked son (ʵ�����ӵĶ���)
      Stack[++Head] = x;
      x = x->Fa;
      continue;
    }
    break;
  }
  Push_Down(x);
  if(Head) {
    for (register unsigned i(Head); i > 0; --i) {//Must be sure there's no tags alone Root-x, and delete Root->Fa for a while 
      Push_Down(Stack[i]);
    }
    x = Stack[1];
    while (x->Fa) {                                     // ����û��ͷ
      if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (ʵ�����ӵĶ���)
        if (x->Fa->Fa) {
          if (x->Fa->Fa->Son[0] == x->Fa || x->Fa->Fa->Son[1] == x->Fa) { // Father
  			    Rotate((x->Fa->Son[0] == x)^(x->Fa->Fa->Son[0] == x->Fa) ? x : x->Fa);
          }                      // End
        }
        Rotate(x);               //���һ����ת
      }
      else {
        break;
      }
    }
  }
  return;
}
void Access (Node *x) {     // Let x be the bottom of the chain where the root at
  Splay(x), x->Son[1] = NULL, Update(x);         // Delete x's right son
  Node *Father(x->Fa);
  while (Father) {
    Splay(Father), Father->Son[1] = x; // Change the right son
    x = Father, Father = x->Fa, Update(x);     // Go up
  }
  return;
}
Node *Find_Root(Node *x) {  // Find the root
  Access(x), Splay(x), Push_Down(x);
  while (x->Son[0]) {
    x = x->Son[0], Push_Down(x);
  }
  return x;
}
int main() {
  n = RD();
  m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Value = RD();
  }
  register unsigned A, B, C;
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    C = RD();
    switch (A) {
      case 0: { // Query
        Access(N + B), Splay(N + B), N[B].Tag ^= 1; // x Ϊ�� 
        Access(N + C);    // y �� x Ϊͬһʵ������
        Splay(N + C);     // y Ϊ����ʵ���� Splay �ĸ� 
        printf("%u\n", N[C].Sum);
        break;
      }
      case 1: { // Link
        Access(N + B), Splay(N + B), N[B].Tag ^= 1;         // x Ϊ��, Ҳ������ Splay �ĸ�
        if(Find_Root(N + C) != N + B) {// x, y ����ͨ, x �� Fink_Root ʱ�Ѿ��������� Splay �ĸ���, Ҳ����ԭ��������ʵ����, ������Ϊ�� 
          N[B].Fa = N + C;        // ��ָ��
        }
        break;
      }
      case 2: { // Cut
        Access(N + B), Splay(N + B), N[B].Tag ^= 1;                         // x Ϊ��, Ҳ������ Splay �ĸ�
        if(Find_Root(N + C) == N + B) {           // x, y ��ͨ 
          if(N[B].Fa == N + C && !(N[B].Son[1])) {
            N[B].Fa = N[C].Son[0] = NULL;         // �ϱ�
            Update(N + C);
          }
        }
        break;
      }
      case 3: { // Change
        Splay(N + B);   // ת������ 
        N[B].Value = C; // ��Ȩֵ 
        break;
      }
    }
  }
  return Wild_Donkey;
}
// Main PC Before 36.64s
// Main PC After 0.278s
// Main PC no splay after find_root 0.27s
/*
2 7
1
2
1 1 2
0 1 2
3 1 4
0 1 2
2 1 2
1 1 2
0 1 2

2 6
1
2
1 1 2
0 1 2
0 1 1
2 1 2
0 1 1
0 2 2
*/
