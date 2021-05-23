#include "jumps.h"
#include <vector>
#include <cstdio>
#include <cstring>

int n;
int a[200005], Dest[200005];
struct Queue{
  int L, R, Adr;
}Que[200005];

void init(int N, std::vector<int> H) {
  n = N;
  for (int i(0); i < n; ++i) {
    a[i] = H[i];
  }
}
int minimum_jumps(int A, int B, int C, int D) {
  int Ans = 0x3f3f3f3f, Hd(0), Tl(0);
  memset(Dest, 0x3f, sizeof(Dest));
  for (int i(A); i <= B; ++i) {
    Que[++Tl].Adr = i;
    Que[Tl].L = i - 1;
    Que[Tl].R = i + 1;
    Dest[i] = 0;
  }
  int now, l, r;
  while (Hd < Tl) {
    now = Que[++Hd].Adr;
    l = Que[Hd].L;
    r = Que[Hd].R;
    while (l >= 0) {
      if(a[l] > a[now]) {
        if(Dest[l] >= 0x3f3f3f3f) {
          Que[++Tl].Adr = l;
          Que[Tl].L = l - 1;
          Que[Tl].R = Que[Hd].R;
          Dest[l] = Dest[now] + 1;
          if((C <= l) && (l <= D)) {
            return Dest[l];
          } 
        }
        break;
      }
      --l;
    }
    while (r < n) {
      if(a[r] > a[now]) {
        if(Dest[r] >= 0x3f3f3f3f) {
          Que[++Tl].Adr = r;
          Que[Tl].L = Que[Hd].L;
          Que[Tl].R = r + 1;
          Dest[r] = Dest[now] + 1;
          if((C <= r) && (r <= D)) {
            return Dest[r];
          }
        }
        break;
      }
      ++r;
    }
  }
  return -1;
}
