#include "jumps.h"
#include <vector>
#include <cstdio>
#include <cstring>

int n, a[200005], Dest[200005], L[200005], R[200005], Que[200005];

void init(int N, std::vector<int> H) {
  n = N;
  int now;
  for (int i(0); i < n; ++i) {
    a[i] = H[i];
  }
  L[0] = -1;
  for (int i(1); i < n; ++i) {
    now = i - 1;
    while ((now >= 0) && H[now] <= H[i]) {
      now = L[now];
    }
    L[i] = now;
  }
  R[n - 1] = -1;
  for (int i(n - 2); i >= 0; --i) {
    now = i + 1;
    while ((now >= 0) && H[now] <= H[i]) {
      now = R[now];
    }
    R[i] = now;
  }
}
int minimum_jumps(int A, int B, int C, int D) {
  int Ans = 0x3f3f3f3f, Hd(0), Tl(0);
  memset(Dest, 0x3f, sizeof(Dest));
  for (int i(A); i <= B; ++i) {
    Que[++Tl] = i;
    Dest[i] = 0;
  }
  int now;
  while (Hd < Tl) {
    now = Que[++Hd];
    if(a[L[now]] > a[now]) {
      if(Dest[L[now]] > Dest[now] + 1) {
        Que[++Tl] = L[now];
        Dest[L[now]] = Dest[now] + 1;
        if((C <= L[now]) && (L[now] <= D)) {
          return Dest[L[now]];
        } 
      }
    }
    if(a[R[now]] > a[now]) {
      if(Dest[R[now]] > Dest[now] + 1) {
        Que[++Tl] = R[now];
        Dest[R[now]] = Dest[now] + 1;
        if((C <= R[now]) && (R[now] <= D)) {
          return Dest[R[now]];
        }
      }
    }
  }
  return -1;
}
