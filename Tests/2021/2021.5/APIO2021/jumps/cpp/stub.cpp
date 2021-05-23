#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include "jumps.h"
#include <vector>
#include <cstdio>

int n, now;
int a[200005], Dest[200005], L[200005], R[200005], Que[200005];

void init(int N, std::vector<int> H) {
  n = N;
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
//    printf("%u %u\n", i, L[i]);
  }
  R[n - 1] = -1;
  for (int i(n - 2); i >= 0; --i) {
    now = i + 1;
    while ((now >= 0) && H[now] <= H[i]) {
      now = R[now];
    }
    R[i] = now;
//    printf("%u %u\n", i, R[i]);
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
      if(Dest[L[now]] >= 0x3f3f3f3f) {
        Que[++Tl] = L[now];
        Dest[L[now]] = Dest[now] + 1;
        if((C <= L[now]) && (L[now] <= D)) {
          return Dest[L[now]];
        } 
      }
    }
    if(a[R[now]] > a[now]) {
      if(Dest[R[now]] >= 0x3f3f3f3f) {
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



int main() {
  int N, Q;
  assert(2 == scanf("%d %d", &N, &Q));
  std::vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &H[i]));
  }
  init(N, H);
  for (int i = 0; i < Q; ++i) {
    int A, B, C, D;
    assert(4 == scanf("%d %d %d %d", &A, &B, &C, &D));
    printf("%d\n", minimum_jumps(A, B, C, D));
  }
  return 0;
}
/*
5 0
0 1 2 3 4

*/
