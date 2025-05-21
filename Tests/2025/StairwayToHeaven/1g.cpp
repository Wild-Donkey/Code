#include<bits/stdc++.h>
using namespace std;
unsigned long long RD() {
  unsigned long long RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
unsigned long long n;
unsigned long long Pow[32][105];
unsigned long long P(unsigned long long x, unsigned long long y) {
  if (y == 4) return x * x * x * x;
  if (y == 3) return x * x * x;
  if (y == 2) return x * x;
  return x;
}
void Prt(unsigned x, unsigned y) {
  for (unsigned j = 1; j < x; ++j) printf("%u^%u+", j, y);
  printf("%u^%u\n", x, y);
}
signed main() {
  n = RD();
  for (unsigned i = 2, j; i <= 100; ++i) {
    Pow[0][i] = 1, j = 1;
    do {
      Pow[j][i] = Pow[j - 1][i] * i, ++j;
      // printf("Cur %u %llu\n", j - 1, Pow[j - 1][i]);
    } while (Pow[j - 1][i] <= ((unsigned long long)1 << 31));
  }
  for (unsigned i = 1; i <= 31; ++i) {
    Pow[i][1] = 1;
    for (unsigned j = 2; j <= 100; ++j) {
      if (Pow[i][j] == 0) break;
      Pow[i][j] += Pow[i][j - 1];
      // printf("%llu ", Pow[i][j]);
      if (Pow[i][j] > ((unsigned long long)1 << 31)) break;
    }
    // putchar(0x0A);
  }
  for (unsigned i = 30; i >= 5; --i) {
    unsigned Pos = 0;
    for (unsigned j = 2; Pow[i][j]; ++j) {
      if (Pow[i][j] == n) {
        Pos = j; break;
      }
    }
    if (Pos) {
      Prt(Pos, i);
      return 0;
    }
  }
  for (unsigned i = 4; i; --i) {
    unsigned long long Sum = 0;
    unsigned Pos = 0;
    for (unsigned j = 1; Sum < n; ++j) {
      Sum += P(j, i);
      if (Sum == n) {
        Pos = j;
        break;
      }
    }
    if (Pos) {
      Prt(Pos, i);
      return 0;
    }
  }
  printf("Impossible for %llu.\n", n);
  return 0;
}