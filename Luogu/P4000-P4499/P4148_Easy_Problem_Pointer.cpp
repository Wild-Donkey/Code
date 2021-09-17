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
const unsigned MOD1(1000000007);
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
unsigned List[200005], m, n, Cnt(0), Rand(time(0)), A, B, Hd, t, Ans(0), Tmp(0), Opx, Opy, Opx_, Opy_, Opv;
char flg(1), nowDir(0), SonDir(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, Sum, Size, x, y, Minx, Miny, Maxx, Maxy;
  char Dir;
}N[200005], *CntN(N), *Rbd(NULL), *RbFa(NULL), *Root(N);
struct Stack {
  unsigned Val, x, y;
  inline const char operator <(const Stack &sx) const{
    return (nowDir) ? ((this->x ^ sx.x) ? (this->x < sx.x) : (this->y < sx.y)) : ((this->y ^ sx.y) ? (this->y < sx.y) : (this->x < sx.x));
  }
}S[200005];
inline void Clr() {}
Node *Build(unsigned L, unsigned R) {
  register Node *now(N + List[Hd--]);
  if(L == R) {
    now->Minx = now->Maxx = now->x = S[L].x;
    now->Miny = now->Maxy = now->y = S[L].y;
    now->Sum = now->Val = S[L].Val;
    now->Size = 1;
    now->LS = now->RS = NULL;
    return now;
  }
  register unsigned Mid((L + R) >> 1);
  Rand = Rand * MOD1;
  nowDir = (Rand >> 1) % 2;
  now->Dir = nowDir;
  nth_element(S + L, S + Mid, S + R + 1);
  now->Minx = now->Maxx = now->x = S[Mid].x;
  now->Miny = now->Maxy = now->y = S[Mid].y;
  now->Sum = now->Val = S[Mid].Val;
  now->Size = 1;
  if(Mid ^ L) {
    now->LS = Build(L, Mid - 1);
    now->Sum += now->LS->Sum;
    now->Size += now->LS->Size;
    now->Minx = min(now->Minx, now->LS->Minx);
    now->Maxx = max(now->Maxx, now->LS->Maxx);
    now->Miny = min(now->Miny, now->LS->Miny);
    now->Maxy = max(now->Maxy, now->LS->Maxy);
  } else {
    now->LS = NULL; 
  }
  now->RS = Build(Mid + 1, R);
  now->Sum += now->RS->Sum;
  now->Size += now->RS->Size;
  now->Minx = min(now->Minx, now->RS->Minx);
  now->Maxx = max(now->Maxx, now->RS->Maxx);
  now->Miny = min(now->Miny, now->RS->Miny);
  now->Maxy = max(now->Maxy, now->RS->Maxy);
  return now;
}
void DFS(Node *now) {
  if(now->LS) DFS(now->LS);
  List[++Hd] = now - N, S[Hd].Val = now->Val, S[Hd].x = now->x, S[Hd].y = now->y;
  if(now->RS) DFS(now->RS);
}
Node *Rebuild(Node *now) {
//  printf("Rebuild %u\n", now - N); 
  Hd = 0, DFS(now);
  return Build(1, Hd);
}
void Insert(Node *now, Node *Fa, const char Dire) {
//  printf("Insert %u [%u %u], [%u, %u] %u\n", now - N, now->Minx, now->Maxx, now->Miny, now->Maxy, now->Sum);
  now->Sum += Opv;
  if(!((now->x ^ Opx) | (now->y ^ Opy))) {
    now->Val += Opv;
    return;
  }
  if(now->Dir) {
    if(Opx < now->x) {
      if(now->LS){
        now->Size -= now->LS->Size;
        Insert(now->LS, now, 0);
        now->Size += now->LS->Size;
      } else {
        ++(now->Size);
        now->LS = ++CntN;
        now->LS->Sum = now->LS->Val = Opv;
        now->LS->Size = 1;
        now->LS->Maxx = now->LS->Minx = now->LS->x = Opx;
        now->LS->Maxy = now->LS->Miny = now->LS->y = Opy;
      }
      now->Minx = min(now->Minx, now->LS->Minx);
      now->Miny = min(now->Miny, now->LS->Miny);
      now->Maxy = max(now->Maxy, now->LS->Maxy);
    } else {
      if(now->RS){
        now->Size -= now->RS->Size;
        Insert(now->RS, now, 1);
        now->Size += now->RS->Size;
      } else {
        ++(now->Size);
        now->RS = ++CntN;
        now->RS->Sum = now->RS->Val = Opv;
        now->RS->Size = 1;
        now->RS->Maxx = now->RS->Minx = now->RS->x = Opx;
        now->RS->Maxy = now->RS->Miny = now->RS->y = Opy;
      }
      now->Miny = min(now->Miny, now->RS->Miny);
      now->Maxy = max(now->Maxy, now->RS->Maxy);
      now->Maxx = max(now->Maxx, now->RS->Maxx); 
    }
  } else {
    if(Opy < now->y) {
      if(now->LS){
        now->Size -= now->LS->Size;
        Insert(now->LS, now, 0);
        now->Size += now->LS->Size;
      } else {
        ++(now->Size);
        now->LS = ++CntN;
        now->LS->Sum = now->LS->Val = Opv;
        now->LS->Size = 1;
        now->LS->Maxx = now->LS->Minx = now->LS->x = Opx;
        now->LS->Maxy = now->LS->Miny = now->LS->y = Opy;
      }
      now->Miny = min(now->Miny, now->LS->Miny);
      now->Minx = min(now->Minx, now->LS->Minx);
      now->Maxx = max(now->Maxx, now->LS->Maxx);
    } else {
      if(now->RS){
        now->Size -= now->RS->Size;
        Insert(now->RS, now, 1);
        now->Size += now->RS->Size;
      } else {
        ++(now->Size);
        now->RS = ++CntN;
        now->RS->Sum = now->RS->Val = Opv;
        now->RS->Size = 1;
        now->RS->Maxx = now->RS->Minx = now->RS->x = Opx;
        now->RS->Maxy = now->RS->Miny = now->RS->y = Opy;
      }
      now->Maxy = max(now->Maxy, now->RS->Maxy);
      now->Minx = min(now->Minx, now->RS->Minx);
      now->Maxx = max(now->Maxx, now->RS->Maxx); 
    }
  }
  if(now->Size > 3) {
    if(!((now->LS) && (now->RS))) {
      Rbd = now, RbFa = Fa, SonDir = Dire;
      return;
    }
    if((now->LS->Size * 3 < now->RS->Size) || (now->LS->Size > now->RS->Size * 3)){
      Rbd = now, RbFa = Fa, SonDir = Dire;
    }
  }
  return;
}
void Qry(Node *now) {
//  printf("%u [%u %u], [%u, %u] %u\n", now - N, now->Minx, now->Maxx, now->Miny, now->Maxy, now->Sum);
  if(now->Minx >= Opx && now->Miny >= Opy && now->Maxx <= Opx_ && now->Maxy <= Opy_) {
    Ans += now->Sum;
    return;
  }
  if(now->Minx > Opx_ || now->Miny > Opy_ || now->Maxx < Opx || now->Maxy < Opy) {
    return;
  }
  if(now->x >= Opx && now->y >= Opy && now->x <= Opx_ && now->y <= Opy_) {
    Ans += now->Val;
  }
  if(now->LS) Qry(now->LS);
  if(now->RS) Qry(now->RS);
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P4148_1.in", "r", stdin);
//   freopen("P4148.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  N[0].Minx = N[0].Miny = N[0].Maxx = N[0].Maxy = N[0].Size = N[0].y = N[0].x = 1, N[0].Sum = N[0].Val = 0;
  while (1) {
    A = RD();
    if(A & 1) {
      if(A ^ 3) {
        ++Cnt;
        Opx = RD() ^ Ans, Opy = RD() ^ Ans, Opv = RD() ^ Ans;
//        Opx = RD(), Opy = RD(), Opv = RD();
//        printf("%u Insert (%u, %u) %u\n", Cnt, Opx, Opy, Opv);
        Rbd = NULL, Insert(Root, NULL, false);
        if(Rbd) {
          if(!RbFa) {
            Root = Rebuild(Rbd);
          }
          else {
            if(SonDir) {
              RbFa->RS = Rebuild(Rbd);
            } else {
              RbFa->LS = Rebuild(Rbd);
            }
          }
        }
      } else break;
    } else {
      Opx = RD() ^ Ans, Opy = RD() ^ Ans, Opx_ = RD() ^ Ans, Opy_ = RD() ^ Ans;
//      Opx = RD(), Opy = RD(), Opx_ = RD(), Opy_ = RD();
//      printf("%u Query (%u, %u) (%u, %u)\n", Cnt, Opx, Opy, Opx_, Opy_);
      Ans = 0, Qry(Root);
      printf("%u\n", Ans);
    }
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
//
