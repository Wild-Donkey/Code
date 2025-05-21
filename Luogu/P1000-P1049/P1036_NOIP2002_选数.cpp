#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int n, m, a[23];
unsigned Sum(0), Cur(0);
char Prime(unsigned x) {
  for (unsigned i(sqrt(x)); i > 1; --i)
    if (!(x % i)) return 0;
  return 1;
}
unsigned DFS(unsigned Dep) {
  unsigned Rt(0), Tmp(Cur);
  if (Dep == m + 1) return Prime(Sum);
  for (++Cur; Cur + (m - Dep) <= n; ++Cur) {
    Sum += a[Cur];
    Rt += DFS(Dep + 1);
    Sum -= a[Cur];
  }
  Cur = Tmp;
  return Rt;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << DFS(1);
  return 0;
}
