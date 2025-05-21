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
  while (rdch < '0' || rdch > '9') { rdch = getchar(); }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned n, m;
unsigned A, B, C;
void *Stack[100005];
struct Node {
  Node *Son[2], *Fa;
  char Tag;
  unsigned Value, Sum;
  inline char RealFather() {
    return Fa && (Fa->Son[0] == this || Fa->Son[1] == this);
  }
  inline char Side() { return Fa->Son[1] == this; }
  void Update() {
    Sum = Value;
    if (Son[0]) Sum ^= Son[0]->Sum;
    if (Son[1]) Sum ^= Son[1]->Sum;
    return;
  }
  void Push_Down() {
    if (Tag) {
      Tag = 0, swap(Son[0], Son[1]);
      if (Son[0]) Son[0]->Tag ^= 1;
      if (Son[1]) Son[1]->Tag ^= 1;
    }
  }
  void Rotate() {
    Node *Father(Fa);
    char xSide(Side());
    if ((Fa = Father->Fa) && Father->RealFather()) Fa->Son[Father->Side()] = this;
    Father->Fa = this;
    if (Father->Son[xSide] = Son[xSide ^ 1]) Father->Son[xSide]->Fa = Father;
    Son[xSide ^ 1] = Father;
    Father->Update(), Update();
  }
  void Splay() {
    unsigned Head(0);
    Node *Cur(this);
    while (Cur->RealFather()) Stack[++Head] = Cur, Cur = Cur->Fa;
    Cur->Push_Down();
    if (!Head) return;
    for (unsigned i(Head); i; --i) ((Node *)Stack[i])->Push_Down();
    Cur = this;
    while (Cur->RealFather()) {
      if (Cur->Fa->RealFather())
        ((Cur->Side() ^ Cur->Fa->Side()) ? Cur : Cur->Fa)->Rotate();
      Cur->Rotate();
    }
  }
  void Access() {
    // printf("Access %u\n", this);
    Splay(), Son[1] = NULL, Update();  // Delete x's right son
    Node *Cur(this), *Father(Fa);
    while (Father) {
      Father->Splay(), Father->Son[1] = Cur;          // Change the right son
      Cur = Father, Father = Cur->Fa, Cur->Update();  // Go up
    }
    return Splay();
  }
  Node *Find_Root() {  // Find the root
    Access(), Push_Down();
    Node *Cur(this);
    while (Cur->Son[0]) Cur = Cur->Son[0], Cur->Push_Down();
    return Cur;
  }
} N[100005];
signed main() {
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Value = N[i].Sum = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    switch (A) {
      case 0: {                        // Query
        N[B].Access(), N[B].Tag ^= 1;  // Makeroot(B)
        N[C].Access();
        printf("%u\n", N[C].Sum);
        break;
      }
      case 1: {                        // Link
        N[B].Access(), N[B].Tag ^= 1;  // Makeroot(B)
        if (N[C].Find_Root() != N + B) N[B].Fa = N + C;
        break;
      }
      case 2: {                        // Cut
        N[B].Access(), N[B].Tag ^= 1;  // Makeroot(B)
        if (N[C].Find_Root() == N + B) {
          if (N[B].Fa == N + C && !(N[B].Son[1]))
            N[B].Fa = N[C].Son[0] = NULL, N[C].Update();
        }
        break;
      }
      case 3: {  // Change
        N[B].Splay(), N[B].Value = C, N[B].Update();
        break;
      }
    }
  }
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
