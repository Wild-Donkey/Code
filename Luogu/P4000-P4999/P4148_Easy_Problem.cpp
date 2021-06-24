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
unsigned CntN(1), Rbd(0), RbFa(0), Root(1), List[200005], m, n, Cnt(0), A, B, Hd, t, Ans(0), Tmp(0), Opx, Opy, Opx_, Opy_, Opv;
char flg(1), nowDir(1), SonDir(0);
struct Node {
  unsigned LS, RS, Val, Sum, Size, x, y, Minx, Miny, Maxx, Maxy;
  char Dir;
}N[200005];
struct Stack {
  unsigned Val, x, y;
  inline const char operator <(const Stack &sx) const{
    return (nowDir) ? ((this->x ^ sx.x) ? (this->x < sx.x) : (this->y < sx.y)) : ((this->y ^ sx.y) ? (this->y < sx.y) : (this->x < sx.x));
  }
}S[200005];
inline void Clr() {}
unsigned Build(unsigned L, unsigned R) {
//  printf("Build[%u, %u]\n", L, R);
  register unsigned now(List[Hd--]);
  if(L == R) {
    N[now].Minx = N[now].Maxx = N[now].x = S[L].x;
    N[now].Miny = N[now].Maxy = N[now].y = S[L].y;
    N[now].Sum = N[now].Val = S[L].Val;
    N[now].Size = 1;
    N[now].LS = N[now].RS = 0;
    return now;
  }
  register unsigned Mid((L + R) >> 1);
   nowDir = rand() % 2;
  N[now].Dir = nowDir;
  nth_element(S + L, S + Mid, S + R + 1);
  N[now].Minx = N[now].Maxx = N[now].x = S[Mid].x;
  N[now].Miny = N[now].Maxy = N[now].y = S[Mid].y;
  N[now].Sum = N[now].Val = S[Mid].Val;
  N[now].Size = 1;
  if(Mid ^ L) {
    N[now].LS = Build(L, Mid - 1);
    N[now].Sum += N[N[now].LS].Sum;
    N[now].Size += N[N[now].LS].Size;
    N[now].Minx = min(N[now].Minx, N[N[now].LS].Minx);
    N[now].Maxx = max(N[now].Maxx, N[N[now].LS].Maxx);
    N[now].Miny = min(N[now].Miny, N[N[now].LS].Miny);
    N[now].Maxy = max(N[now].Maxy, N[N[now].LS].Maxy);
  } else {
    N[now].LS = 0;
  }
  N[now].RS = Build(Mid + 1, R);
  N[now].Sum += N[N[now].RS].Sum;
  N[now].Size += N[N[now].RS].Size;
  N[now].Minx = min(N[now].Minx, N[N[now].RS].Minx);
  N[now].Maxx = max(N[now].Maxx, N[N[now].RS].Maxx);
  N[now].Miny = min(N[now].Miny, N[N[now].RS].Miny);
  N[now].Maxy = max(N[now].Maxy, N[N[now].RS].Maxy);
  return now;
}
void DFS(unsigned now) {
  if(N[now].LS) DFS(N[now].LS);
  List[++Hd] = now, S[Hd].Val = N[now].Val, S[Hd].x = N[now].x, S[Hd].y = N[now].y;
  if(N[now].RS) DFS(N[now].RS);
}
unsigned Rebuild(unsigned now) {
//  printf("Rebuild %u\n", now - N); 
  Hd = 0, DFS(now);
  return Build(1, Hd);
}
void Insert(unsigned now, unsigned Fa, const char Dire) {
//  printf("Insert %u [%u %u], [%u, %u] %u\n", now - N, N[now].Minx, N[now].Maxx, N[now].Miny, N[now].Maxy, N[now].Sum);
  N[now].Sum += Opv;
  if(!((N[now].x ^ Opx) | (N[now].y ^ Opy))) {
    N[now].Val += Opv;
    return;
  }
  if(N[now].Dir) {
    if(Opx < N[now].x) {
      if(N[now].LS){
        N[now].Size -= N[N[now].LS].Size;
        Insert(N[now].LS, now, 0);
        N[now].Size += N[N[now].LS].Size;
      } else {
        ++(N[now].Size);
        N[now].LS = ++CntN;
        N[N[now].LS].Sum = N[N[now].LS].Val = Opv;
        N[N[now].LS].Size = 1;
        N[N[now].LS].Maxx = N[N[now].LS].Minx = N[N[now].LS].x = Opx;
        N[N[now].LS].Maxy = N[N[now].LS].Miny = N[N[now].LS].y = Opy;
      }
      N[now].Minx = min(N[now].Minx, N[N[now].LS].Minx);
      N[now].Miny = min(N[now].Miny, N[N[now].LS].Miny);
      N[now].Maxy = max(N[now].Maxy, N[N[now].LS].Maxy);
    } else {
      if(N[now].RS){
        N[now].Size -= N[N[now].RS].Size;
        Insert(N[now].RS, now, 1);
        N[now].Size += N[N[now].RS].Size;
      } else {
        ++(N[now].Size);
        N[now].RS = ++CntN;
        N[N[now].RS].Sum = N[N[now].RS].Val = Opv;
        N[N[now].RS].Size = 1;
        N[N[now].RS].Maxx = N[N[now].RS].Minx = N[N[now].RS].x = Opx;
        N[N[now].RS].Maxy = N[N[now].RS].Miny = N[N[now].RS].y = Opy;
      }
      N[now].Miny = min(N[now].Miny, N[N[now].RS].Miny);
      N[now].Maxy = max(N[now].Maxy, N[N[now].RS].Maxy);
      N[now].Maxx = max(N[now].Maxx, N[N[now].RS].Maxx); 
    }
  } else {
    if(Opy < N[now].y) {
      if(N[now].LS){
        N[now].Size -= N[N[now].LS].Size;
        Insert(N[now].LS, now, 0);
        N[now].Size += N[N[now].LS].Size;
      } else {
        ++(N[now].Size);
        N[now].LS = ++CntN;
        N[N[now].LS].Sum = N[N[now].LS].Val = Opv;
        N[N[now].LS].Size = 1;
        N[N[now].LS].Maxx = N[N[now].LS].Minx = N[N[now].LS].x = Opx;
        N[N[now].LS].Maxy = N[N[now].LS].Miny = N[N[now].LS].y = Opy;
      }
      N[now].Miny = min(N[now].Miny, N[N[now].LS].Miny);
      N[now].Minx = min(N[now].Minx, N[N[now].LS].Minx);
      N[now].Maxx = max(N[now].Maxx, N[N[now].LS].Maxx);
    } else {
      if(N[now].RS){
        N[now].Size -= N[N[now].RS].Size;
        Insert(N[now].RS, now, 1);
        N[now].Size += N[N[now].RS].Size;
      } else {
        ++(N[now].Size);
        N[now].RS = ++CntN;
        N[N[now].RS].Sum = N[N[now].RS].Val = Opv;
        N[N[now].RS].Size = 1;
        N[N[now].RS].Maxx = N[N[now].RS].Minx = N[N[now].RS].x = Opx;
        N[N[now].RS].Maxy = N[N[now].RS].Miny = N[N[now].RS].y = Opy;
      }
      N[now].Maxy = max(N[now].Maxy, N[N[now].RS].Maxy);
      N[now].Minx = min(N[now].Minx, N[N[now].RS].Minx);
      N[now].Maxx = max(N[now].Maxx, N[N[now].RS].Maxx); 
    }
  }
  if(N[now].Size > 3) {
    if(!((N[now].LS) && (N[now].RS))) {
      Rbd = now, RbFa = Fa, SonDir = Dire;
      return;
    }
    if((N[N[now].LS].Size * 3 < N[N[now].RS].Size) || (N[N[now].LS].Size > N[N[now].RS].Size * 3)){
      Rbd = now, RbFa = Fa, SonDir = Dire;
    }
  }
  return;
}
void Qry(unsigned now) {
//  printf("%u [%u %u], [%u, %u] %u\n", now, N[now].Minx, N[now].Maxx, N[now].Miny, N[now].Maxy, N[now].Sum);
  if(N[now].Minx >= Opx && N[now].Miny >= Opy && N[now].Maxx <= Opx_ && N[now].Maxy <= Opy_) {
    Ans += N[now].Sum;
    return;
  }
  if(N[now].Minx > Opx_ || N[now].Miny > Opy_ || N[now].Maxx < Opx || N[now].Maxy < Opy) {
    return;
  }
  if(N[now].x >= Opx && N[now].y >= Opy && N[now].x <= Opx_ && N[now].y <= Opy_) {
    Ans += N[now].Val;
  }
  if(N[now].LS) Qry(N[now].LS);
  if(N[now].RS) Qry(N[now].RS);
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P4148_1.in", "r", stdin);
//   freopen("P4148.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  srand(time(0));
  n = RD();
  N[1].Minx = N[1].Miny = N[1].Maxx = N[1].Maxy = N[1].Size = N[1].y = N[1].x = 1, N[1].Sum = N[1].Val = 0;
  while (1) {
    A = RD();
    ++Cnt;
    if(A & 1) {
      if(A ^ 3) {
        Opx = RD() ^ Ans, Opy = RD() ^ Ans, Opv = RD() ^ Ans;
//        Opx = RD(), Opy = RD(), Opv = RD();
//        printf("%u Insert (%u, %u) %u\n", Cnt, Opx, Opy, Opv);
        Rbd = 0, Insert(Root, 0, false);
        if(Rbd) {
          if(!RbFa) {
            Root = Rebuild(Rbd);
          }
          else {
            if(SonDir) {
              N[RbFa].RS = Rebuild(Rbd);
            } else {
              N[RbFa].LS = Rebuild(Rbd);
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
