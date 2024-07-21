#include <algorithm>
#include <cstring>
#include <iostream>
#define Lowbit(x) ((x) & ((~(x)) + 1))
using namespace std;
int n(1), m;
unsigned a[100005], b[100005], T[100005];
unsigned Find(unsigned x) {
  unsigned Rt(0);
  while (x) Rt = max(Rt, T[x]), x -= Lowbit(x);
  return Rt;
}
void Edit(unsigned x, unsigned y) {
  while (x <= m) T[x] = max(T[x], y), x += Lowbit(x);
}
int main() {
  while (cin >> a[n]) ++n;
  --n;
  for (unsigned i(1); i <= n; ++i) b[i] = a[i];
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (unsigned i(1); i <= n; ++i)
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
  for (unsigned i(n); i; --i) {
    unsigned Tmp(Find(a[i]));
    Edit(a[i], Tmp + 1);
  }
  cout << Find(m) << endl;
  memset(T, 0, (m + 1) << 2);
  for (unsigned i(1); i <= n; ++i) {
    unsigned Tmp(Find(a[i] - 1));
    Edit(a[i], Tmp + 1);
  }
  cout << Find(m) << endl;
  return 0;
}
