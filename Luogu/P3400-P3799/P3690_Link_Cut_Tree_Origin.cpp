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
bool flg(0);
char inch, List[155][75];
struct Node {
  Node *Son[2], *Fa;
  char Tag;
  unsigned Value, Sum;
}N[100005], *Stack[100005];
inline void Check(Node *x) {
  printf("Node %u\n", x - N);
  printf("V %u S %u T %u\n", x->Value, x->Sum, x->Tag);
  printf("Fa %u Son %u %u\n", x->Fa - N, x->Son[0] - N, x->Son[1] - N);
  printf("\n\n\n");
  return;
}
inline void Check() {
  for (register unsigned i(1); i <= n; ++i) {
    Check(N + i);
  }
  return;
}
inline void Update(Node *x) {
//  printf("Update %u\n", x - N); 
  x->Sum = x->Value;
  if(x->Son[0]) {
    x->Sum ^= x->Son[0]->Sum;
  }
  if(x->Son[1]) {
    x->Sum ^= x->Son[1]->Sum;
  }
//  printf("Sum[%u] = %u\n", x - N, x->Sum);
  return;
}
inline void Push_Down(Node *x) {
  if(x->Tag) {
//    printf("Push_Down %u\n", x - N);
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
//  printf("Make_Tag %u\n", x - N);
  x->Tag ^= 1;
  return;
}
inline void Rotate(Node *x) {
//  if(x->Fa->Tag) {
//    printf("?\n?\n?\n");
//  }
//  printf("Rotate %u\n", x - N);
//  Check();
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
  x->Sum = 0;
  Father->Fa = x;
//  Check(x);
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
//  Check(x);
  Update(Father);
  x->Sum ^= x->Value ^ Father->Sum;
//  printf("Rotating Update Sum[%u] = %u\n", x - N, x->Sum);
  return;
}
void Splay (Node *x) {
//  if(flg) {
//    printf("Splay %u\n", x - N);
//  }
  if(!x) {
    printf("What the hell you're doing?! NULL here\n");
  }
  register unsigned Head(0);
  while (x->Fa) {                                      // ����û��ͷ
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (ʵ�����ӵĶ���)
//      Check(x);
//      Check(x->Fa);
      Stack[++Head] = x;
      x = x->Fa;
      continue;
    }
    break;
  }
  if(!Head) {
    Push_Down(x);
    return;
  }
//  printf("Head %u\n", Head);
//  printf("See %u?\n", x - N);
  Push_Down(x);
//  printf("Fuck\n");
  for (register unsigned i(Head); i > 0; --i) {//Must be sure there's no tags alone Root-x, and delete Root->Fa for a while 
//    printf("Stackpush %u\n", Stack[i] - N); 
    Push_Down(Stack[i]);
  }
  x = Stack[1];
  while (x->Fa) {                                      // ����û��ͷ
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (ʵ�����ӵĶ���)
      if (x->Fa->Fa) {
        if (x->Fa->Fa->Son[0] == x->Fa || x->Fa->Fa->Son[1] == x->Fa) { // Father
			    Rotate((x->Fa->Son[0] == x)^(x->Fa->Fa->Son[0] == x->Fa) ? x : x->Fa);
        }                      // End
      }
      Rotate(x);  //���һ����ת
    }
    else {
      break;
    }
  }
  Update(x);
//  printf("Rotated?\n"); 
  return;
}
void Access (Node *x) {     // Let x be the bottom of the chain where the root at
//  if(flg) { 
//    printf("Access %u{\n", x - N);
//  }
//  printf("Faq");
//  Check();
  Splay(x);
//  Check();
//  printf("Faq too\n");
  x->Son[1] = NULL;         // Delete x's right son
  Update(x);
  Node *Father(x->Fa);
  while (Father) {
//    printf("Access Step %u\n", x - N);
//    Check(Father);
    Splay(Father);
//    Check(Father);
    Father->Son[1] = x; // Change the right son
    x = Father;
    Father = x->Fa;     // Go up
    Update(x);
  }
//  if(flg) { 
//    printf("}\n");
//  }
  return;
}
void Make_Root(Node *x) {   // Let x be the new root
//  if(flg) {
//    printf("Make_Root %u\n", x - N);
//  }
  Access(x);
//  Check();
  Splay(x);
//  Check();
//  if(flg) {
//    Check();
////    Check(x->Fa);
//  }
  Make_Tag(x);
  return;
}
Node *Find_Root(Node *x) {  // Find the root
//  printf("Find_Root %u\n", x - N);
  Access(x);
//  printf("So why you down\n");
//  Check(); 
  Splay(x);
//  Check();
//  printf("Splayed\n");
  Push_Down(x);
//  printf("Pushed\n");
  while (x->Son[0]) {
//    printf("While %u\n", x - N);
    x = x->Son[0];
    Push_Down(x);   
  }
  Splay(x);
//  printf("Found %u\n", x - N);
  return x;
}
int main() {
   freopen("P3690_1.in", "r", stdin);
   freopen("my.out", "w", stdout);
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
    if(i == 100000) {
      flg = 1;
//      Check();
    }
//    printf("Action %u, Do %u, %u, %u\n", i, A, B, C);
//    Check();
    switch (A) {
      case 0: { // Query
        Make_Root(N + B); // x Ϊ�� 
//        Check();
        Access(N + C);    // y �� x Ϊͬһʵ������
//        printf("WTF\n");
//        Check(N + C);
//        Check(); 
        Splay(N + C);     // y Ϊ����ʵ���� Splay �ĸ� 
        printf("%u\n", N[C].Sum);
        break;
      }
      case 1: { // Link
//        swap(B, C);
        Make_Root(N + B);         // x Ϊ��, Ҳ������ Splay �ĸ�
        if(Find_Root(N + C) != N + B) {// x, y ����ͨ, x �� Fink_Root ʱ�Ѿ��������� Splay �ĸ���, Ҳ����ԭ��������ʵ����, ������Ϊ�� 
//          N[B].Son[0] = N + C;    // ���� x ������ӱ�� y 
          N[B].Fa = N + C;        // ��ָ�� 
//          Update(N + B);          // ���� x �� Sum 
        }
        break;
      }
      case 2: { // Cut
        Make_Root(N + B);                         // x Ϊ��, Ҳ������ Splay �ĸ�
//        Check();
        if(Find_Root(N + C) == N + B) {           // x, y ��ͨ 
          if(N[C].Fa == N + B && !(N[C].Son[0])) {// x �� y �� Splay �ϵĸ���, y ��������, ������ֱ����
            if(N[B].Tag) {
              printf("Faq\n");
              return 0;
            }
            N[C].Fa = N[B].Son[1] = NULL;         // �ϱ�
            Update(N + B);                        // ���� x (y ����������, �������) 
          } 
        }
//        printf("Done\n");
        break;
      }
      case 3: { // Change
//        Access(N + B);
        Splay(N + B);   // ת������ 
        N[B].Value = C; // ��Ȩֵ 
//        Update(N + B);  // ���� Sum 
        break;
      }
    }
//    Check();
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
// Main PC Before 36.64s
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
