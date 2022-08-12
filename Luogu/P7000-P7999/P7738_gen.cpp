#include <cstdio>

typedef unsigned long long ull;
const int N = 400000;
bool s[N + 1][256];

ull myRand(ull& k1, ull& k2) {
  ull k3 = k1, k4 = k2;
  k1 = k4;
  k3 ^= (k3 << 23);
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}

void gen(int n, ull a1, ull a2) {
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 256; j++)
      s[i][j] = (myRand(a1, a2) & (1ull << 32)) ? 1 : 0;
  for (unsigned i(1); i <= n; ++i) {
    for (int j = 0; j < 256; j++) printf("%u,", s[i][j]); putchar(0x0A);
  }
}

int main() {
  gen(10, 123, 123);
  return 0;
}