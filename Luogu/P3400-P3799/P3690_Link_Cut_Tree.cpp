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
unsigned a[10005], n, m, Cnt(0), Tmp(0), Mx;
bool b[10005];
char inch, List[155][75];
struct Node {
  Node *Son[2], *Fa;
  char Tag;
  unsigned Value, Sum;
}N[100005], *Stack[105];
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
inline void Push_Down(Node *x) {
  if(x->Tag) {
    printf("Push_Down %u\n", x - N);
    x->Tag = 0;
    register Node *TmpSon(x->Son[0]);
    x->Son[0] = x->Son[1];
    x->Son[1] = TmpSon; 
    if(x->Son[0]) {
      x->Son[0]->Tag ^= 1;
    }
    if(x->Son[1]) {
      x->Son[1]->Tag ^= 1;
    }
  }
}
inline void Make_Tag (Node *x) {
  printf("Make_Tag %u\n", x - N);
  x->Tag ^= 1;
  return;
}
inline void Rotate(Node *x) {
  printf("Rotate %u\n", x - N); 
  register Node *Father(x->Fa);
  x->Fa = Father->Fa; // x link to grandfather
  if(Father->Fa) {
    Father->Fa->Son[(Father->Fa->Son[0] == Father) ? 0 : 1] = x;  // grandfather link to x
  }
  if(Father->Son[0] == x) {
    Father->Son[0] = x->Son[1];
    x->Son[1] = Father;
    x->Sum = x->Son[0]->Sum;
  }
  else {
    Father->Son[1] = x->Son[0];
    x->Son[0] = Father; 
    x->Sum = x->Son[1]->Sum;
  }
  Update(Father);
  x->Sum ^= x->Value ^ Father->Value;
  return;
}
void Splay (Node *x) {
  printf("Splay %u\n", x - N);
  if(!x) {
    printf("What the hell you're doing?! NULL here\n");
  }
  register unsigned Head(0);
  while (x->Fa) {                                      // ����û��ͷ
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (ʵ�����ӵĶ���)
      Stack[++Head] = x;
      Update(x);
      x = x->Fa;
      continue;
    }
    break;
  }
  if(!Head) {
    Update(x);
    Push_Down(x);
    return;
  }
  Update(x->Fa);
  Push_Down(x->Fa); 
  printf("Fuck");
  for (register unsigned i(Head); i > 0; --i) {//Must be sure there's no tags alone Root-x, and delete Root->Fa for a while 
    Push_Down(Stack[i]);
  }
  x = Stack[1];
  if (x->Fa) {                                      // ����û��ͷ
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (ʵ�����ӵĶ���)
      while (x->Fa->Fa) {
        if (x->Fa->Fa->Son[0] == x->Fa) { // Father
          Rotate((x->Fa->Son[0] == x) ? x->Fa : x);
          continue;
        }
        if (x->Fa->Fa->Son[1] == x->Fa) { // Mother
          Rotate((x->Fa->Son[0] == x) ? x : x->Fa);
          continue;
        }
        break;                              // End
      }
      Rotate(x);  //���һ����ת
    }
  }
  return;
}
void Access (Node *x) {     // Let x be the bottom of the chain where the root at
  printf("Access %u\n", x - N);
  Node *Father(x->Fa);
  x->Son[1] = NULL;         // Delete x's right son
  Splay(x);
  while (Father) {
    Splay(Father);
    Father->Son[1] = x; // Change the right son
    x = Father;
    Father = x->Fa;     // Go up
    Update(x);
  }
  return;
}
void Make_Root(Node *x) {   // Let x be the new root
  printf("Make_Root %u\n", x - N);
  Access(x);
  Splay(x);
  Make_Tag(x);
  return;
}
Node *Find_Root(Node *x) {  // Find the root
  Access(x);
  Splay(x);
  Push_Down(x);
  while (x->Son[1]) {
    x = x->Son[1];
    Push_Down(x); 
  }
  return x;
}
int main() {
//   freopen("P3796_1.in", "r", stdin);
//   freopen("P3796.out", "w", stdout);
//  t = RD();
  n = RD();
  m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Sum = N[i].Value = RD();
  }
  register unsigned A, B, C;
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    C = RD();
//    printf("Action %u, Do %u, %u, %u\n", i, A, B, C);
    switch (A) {
      case 0: { // Query
        Make_Root(N + B); // x Ϊ�� 
        Access(N + C);    // y �� x Ϊͬһʵ������ 
        Splay(N + C);     // y Ϊ����ʵ���� Splay �ĸ� 
        printf("%u\n", N[C].Sum);
        break;
      }
      case 1: { // Link
        Make_Root(N + B);         // x Ϊ��, Ҳ������ Splay �ĸ� 
        if(Find_Root(N + C) != N + B) {// x, y ����ͨ, y �� Fink_Root ʱ�Ѿ��������� Splay �ĸ���, Ҳ����ԭ��������ʵ����, ������Ϊ�� 
          N[C].Son[1] = N + B;    // ���� y ���Ҷ��ӱ�� x
          Update(N + C);          // ���� y �� Sum 
        }
        break;
      }
      case 2: { // Cut
        Make_Root(N + B);                         // x Ϊ��, Ҳ������ Splay �ĸ� 
        if(Find_Root(N + C) == N + B) {           // x, y ��ͨ 
          if(N[B].Fa == N + C && !(N[B].Son[1])) {// y �� x �� Splay �ϵĸ���, x ��������, ������ֱ����
            N[B].Fa = N[C].Son[0] = NULL;         // �ϱ�
            Update(N + C);                        // ���� y (x ����������, �������) 
          } 
        }
        break;
      }
      case 3: { // Change
        Splay(N + B);   // ת������ 
        N[B].Value = C; // ��Ȩֵ 
        Update(N + B);  // ���� Sum 
        break;
      } 
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
