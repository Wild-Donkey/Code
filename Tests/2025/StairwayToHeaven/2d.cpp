#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
unsigned long long RDll() {
  unsigned long long RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
int RDsg() {
  int RTm = 0;
  char Rchr = getchar(), Flg = 0;
  while ((Rchr < '0' || Rchr > '9') && Rchr != '-') Rchr = getchar();
  if (Rchr == '-') Flg = 1, Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return Flg ? -RTm : RTm;
}
const unsigned long long Ten[20] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000 };
unsigned n;
unsigned long long A[20], B[20];
signed main() {
  n = RD();
  A[n] = RDll(), B[n] = RDll();
  for (unsigned i = n - 1; i; --i) {
    A[i] = A[i + 1] / 10;
    B[i] = B[i + 1] / 10;
  }
  A[0] = B[0] = 0;
  for (unsigned i = 0; i <= n; ++i) {
    if (A[i] >= Ten[i]) A[i] = Ten[i] - 1;
    if (B[i] >= Ten[i]) B[i] = Ten[i] - 1;
  }
  vector<unsigned long long> Lst[2];
  for (unsigned i = max(A[1], 1ull); i <= B[1]; ++i) Lst[1].push_back(i);
  for (unsigned i = 2; i <= n; ++i) {
    Lst[i & 1].clear();
    for (auto j : Lst[(i & 1) ^ 1]) {
      j *= 10;
      unsigned long long Lef = (j + 9) % i, Cur;
      // printf("Curj %llu Lef %llu\n", j, Lef);
      if (Lef >= 10) continue;
      else Cur = j + 9 - Lef;
      while (Cur >= j && Cur <= 0x3f3f3f3f3f3f3f3f) {
        if (Cur >= A[i] && Cur <= B[i]) Lst[i & 1].push_back(Cur);
        Cur -= i;
      }
    }
  }
  if (!Lst[n & 1].size()) {
    printf("No Solution\n");
    return 0;
  }
  sort(Lst[n & 1].begin(), Lst[n & 1].end());
  for (auto i : Lst[n & 1]) printf("%llu\n", i);
  return 0;
}