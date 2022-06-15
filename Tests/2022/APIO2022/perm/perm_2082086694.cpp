#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
std::vector<int> construct_permutation(long long k) {
  unsigned a[64], b[64], Cons[128], Bucket[128], Lg(0), Sc, Fs, n, m;
  vector<int> Rt;
  while (k) a[Lg++] = (k & 1), k >>= 1; Sc = Fs = Lg - 1;
  while (Sc && (!a[Sc - 1])) --Sc;
  if (!Sc) {
    for (unsigned i(1); i < Lg; ++i) Rt.push_back(i - 1);
    return Rt;
  }
  // printf("Fs %u Sc %u B:", Fs, Sc); for (unsigned i(0); i < Lg; ++i) printf("%u ", b[i]); putchar(0x0A);
  for (unsigned i(Fs); i >= Sc; --i) b[i] = 0;
  b[--Sc] = 1;
  // printf("Sc %u\n", Sc);
  // printf("B:"); for (unsigned i(0); i < Lg; ++i) printf("%u ", b[i]); putchar(0x0A);
  for (unsigned i(Sc - 1); ~i; --i) {
    if (!a[i]) { b[i] = 0; continue; }
    if (i && a[i - 1]) b[i] = 0, b[i - 1] = Fs, --i;
    else b[i] = 1, Fs = Sc, Sc = i;
  }
  // printf("B:"); for (unsigned i(0); i < Lg; ++i) printf("%u ", b[i]); putchar(0x0A);
  n = Lg - 3, b[m = Lg - 1] = 1;
  for (unsigned i(1); i < m; ++i) Cons[i - 1] = (i << 1);
  for (unsigned i(Lg - 1); ~i; --i) if (b[i] > 1) {
    // printf("b %u m %u\n", b[i], m);
    while (b[i] < m) Cons[++n] = (m << 1) + 1, b[m] = 0, m = b[i];
    Cons[++n] = (i << 1) + 1;
  }
  // for (unsigned i(0); i <= n; ++i) printf("%u ", Cons[i]); putchar(0x0A);
  for (unsigned i(Lg - 1); ~i; --i) if (b[i] == 1) Cons[++n] = (i << 1) + 1;
  // for (unsigned i(0); i <= n; ++i) printf("%u ", Cons[i]); putchar(0x0A);
  memset(Bucket, 0x3f, sizeof(Bucket));
  for (unsigned i(0); i <= n; ++i) Bucket[Cons[i]] = i;
  for (unsigned i(0), j(0); i < 128; ++i) if (Bucket[i] < 0x3f3f3f3f) Cons[Bucket[i]] = j++;
  for (unsigned i(0); i <= n; ++i) Rt.push_back(Cons[i]);
  // for (unsigned i(0); i <= n; ++i) printf("%u ", Cons[i]); putchar(0x0A);
  return Rt;
}
/*
signed main() {
  unsigned A;
  unsigned long long B;
  scanf("%u", &A);
  for (unsigned i(1); i <= A; ++i) {
    printf("A %u I %u\n", A, i);
    scanf("%llu", &B);
    vector <int> Op(construct_permutation(B));
    for (auto j : Op) printf("%u ", j); putchar(0x0A);
  }
  return 0;
}
*/
//2082086694 (is a joke, Fake Binary Search)
//g++ -DEVAL -std=gnu++17 -O2 -pipe -static -s -o perm grader.cpp perm_2082086694.cpp