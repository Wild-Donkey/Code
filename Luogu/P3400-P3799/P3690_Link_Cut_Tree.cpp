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
}N[100005], *Stack[105];
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
    if(Father->Fa->Son[0] == Father || Father->Fa->Son[1] == Father) {
      Father->Fa->Son[(Father->Fa->Son[0] == Father) ? 0 : 1] = x;  // grandfather link to x
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
  if(flg) {
    printf("Splay %u\n", x - N);
  }
//  if(!x) {
//    printf("What the hell you're doing?! NULL here\n");
//  }
  register unsigned Head(0);
  while (x->Fa) {                                      // 父亲没到头
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (实边连接的儿子)
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
//  printf("See %u?\n", x - N);
  Push_Down(x); 
//  printf("Fuck\n");
  for (register unsigned i(Head); i > 0; --i) {//Must be sure there's no tags alone Root-x, and delete Root->Fa for a while 
//    printf("Stackpush %u\n", Stack[i] - N); 
    Push_Down(Stack[i]);
  }
  x = Stack[1];
  if (x->Fa) {                                      // 父亲没到头
    if(x->Fa->Son[0] == x || x->Fa->Son[1] == x) {  // x is the preferred-edge linked son (实边连接的儿子)
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
      Rotate(x);  //最后一次旋转
    }
  }
//  printf("Rotated?\n"); 
  return;
}
void Access (Node *x) {     // Let x be the bottom of the chain where the root at
  if(flg) { 
    printf("Access %u{\n", x - N);
  }
  Splay(x);
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
  if(flg) { 
    printf("}\n");
  }
  return;
}
void Make_Root(Node *x) {   // Let x be the new root
  if(flg) {
    printf("Make_Root %u\n", x - N);
  }
  Access(x);
  Splay(x);
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
  while (x->Son[1]) {
//    printf("While %u\n", x - N);
    x = x->Son[1];
    Push_Down(x); 
  }
//  printf("Found %u\n", x - N);
  return x;
}
int main() {
   freopen("P3690_1.in", "r", stdin);
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
    if(i >= 100000) {
      flg = 1;
      printf("Action %u, Do %u, %u, %u\n", i, A, B, C);
    }
//    Check();
    switch (A) {
      case 0: { // Query
        Make_Root(N + B); // x 为根 
        Access(N + C);    // y 和 x 为同一实链两端 
        Splay(N + C);     // y 为所在实链的 Splay 的根 
        printf("%u\n", N[C].Sum);
        break;
      }
      case 1: { // Link
        Make_Root(N + B);         // x 为根, 也是所在 Splay 的根
//        Check();
        if(Find_Root(N + C) != N + B) {// x, y 不连通, y 在 Fink_Root 时已经是它所在 Splay 的根了, 也是它原树根所在实链底, 右子树为空 
          N[C].Son[1] = N + B;    // 所以 y 的右儿子变成 x
          N[B].Fa = N + C;        // 父指针 
          Update(N + C);          // 更新 y 的 Sum 
        }
        break;
      }
      case 2: { // Cut
        Make_Root(N + B);                         // x 为根, 也是所在 Splay 的根
//        Check();
        if(Find_Root(N + C) == N + B) {           // x, y 连通 
          if(N[B].Fa == N + C && !(N[B].Son[1])) {// y 是 x 在 Splay 上的父亲, x 无右子树, 所以有直连边
            N[B].Fa = N[C].Son[0] = NULL;         // 断边
            Update(N + C);                        // 更新 y (x 的子树不变, 无需更新) 
          } 
        }
//        printf("Done\n");
        break;
      }
      case 3: { // Change
        Splay(N + B);   // 转到根上 
        N[B].Value = C; // 改权值 
        Update(N + B);  // 更新 Sum 
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
