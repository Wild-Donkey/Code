#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
unsigned n, m, a[100005], Tmp[100005], To[100005];
unsigned A, B, C, D;
void ShiftR(unsigned Stt, unsigned Dis) {
  for (unsigned i = n; i >= Stt; --i) {
    a[i + Dis] = a[i];
  }
  n += Dis;
}
void ShiftL(unsigned Stt, unsigned Dis) {
  for (unsigned i = Stt; i <= n; ++i) {
    a[i - Dis] = a[i];
  }
  n -= Dis;
}
signed main() {
  n = RD(), m = RD();
  for (unsigned i = 1; i <= n; ++i) a[i] = RD();
  // printf("Done\n");
  for (unsigned i = 1; i <= m; ++i) {
    // for (unsigned i = 1; i < n; ++i) printf("%u ", a[i]);
    // printf("%u\n", a[n]);
    A = RD();
    // printf("Opt %u is %u\n", i, A);
    if (A == 1) {
      B = RD();
      for (unsigned j = 1; j <= B; ++j) Tmp[j] = RD();
      C = RD();
      for (unsigned j = 1; j <= C; ++j) To[j] = RD();
      unsigned Pos = 0, ToP = 0, J = 1;
      for (unsigned j = 1; j <= n; ++j) {
        if (J == B + 1) {
          Pos = j, ToP = j - B;
          break;
        }
        if (a[j] == Tmp[J]) ++J;
        else J = 1;
      }
      if ((!Pos) && (J == B + 1)) {
        Pos = n + 1, ToP = n + 1 - B;
      }
      if (Pos) {
        if (B < C)
          ShiftR(Pos, C - B);
        else
          ShiftL(Pos, B - C);
        for (unsigned j = ToP, J = 1; J <= C; ++j, ++J) {
          a[j] = To[J];
        }
      }
      continue;
    }
    if (A == 2) {
      B = 1;
      for (unsigned i = 1; i < n; ++i) {
        Tmp[B] = a[i];
        if ((a[i] + a[i + 1]) & 1) ++B;
        else {
          Tmp[++B] = ((a[i] + a[i + 1]) / 2);
          ++B;
        }
      }
      Tmp[B] = a[n];
      n = B;
      memcpy(a, Tmp, (n + 1) << 2);
      continue;
    }
    B = RD(), C = RD();
    for (unsigned j = B, J = C; j < J; ++j, --J) swap(a[j], a[J]);
  }
  for (unsigned i = 1; i < n; ++i) printf("%u ", a[i]);
  printf("%u\n", a[n]);
  return 0;
}