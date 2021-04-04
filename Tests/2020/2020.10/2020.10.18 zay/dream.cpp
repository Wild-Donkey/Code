#include <iostream>
using namespace std;
inline int RD() {
  int intmp(0), insig;
  char inchar(getchar());
  while ((inchar > '9' || inchar < '0') && (inchar != '-')) {
    inchar = getchar();
  }
  if (inchar == '-') {
    insig = -1;
    inchar = getchar();
  } else {
    insig = 1;
  }
  while (inchar <= '9' && inchar >= '0') {
    intmp *= 10;
    intmp += inchar - '0';
    inchar = getchar();
  }
  return intmp * insig;
}
int ans(0), n, m, t, tmp, a[1000006], J(0), _Xor(0), Mx(0),
    Mn(0x3f3f3f3f), A, B;
void Chng(int l, int x) {
  /* for (register int i(1); i <= n; ++i) {
     printf("%d ", a[i]);
   }*/
  if (a[l] == 0) {
    ans--;
  }
  a[l] ^= x;
  if (a[l] == 0) {
    ans++;
  }
  if (a[l + 1] == 0) {
    ans--;
  }
  a[l + 1] ^= x;
  if (a[l + 1] == 0) {
    ans++;
  }
  /*printf("\n");
  for (register int i(1); i <= n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");*/
  return;
}
int Chck(int l) {
  register int _ans(0);
  for (register int i(l - 1), _tmp(a[l]); i >= 1; --i) {
    _tmp ^= a[i];
    if (_tmp == 0) {
      ++_ans;
    }
  }
  for (register int i(l + 2), _tmp(a[l + 1]); i <= n; ++i) {
    _tmp ^= a[i];
    if (_tmp == 0) {
      ++_ans;
    }
  }
  // printf("checked %d\n", _ans);
  return _ans;
}
/*int Chckfrc() {
  register int _ans(0);
   for (register int i(1); i <= n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  for (register int i(1); i <= n; ++i) {
    if (a[i] == 0) {
      ++_ans;
    }
  }
  for (register int i(1), _tmp(a[1]); i < n; ++i, _tmp = a[i]) {
    for (register int j(i + 1); j <= n; ++j) {
      _tmp ^= a[j];
      if (_tmp == 0) {
        // printf("%d %d\n", i, j);
        ++_ans;
      }
    }
  }
  return _ans;
}*/
int main() {
  freopen("dream.in", "r", stdin);
  freopen("dream.out", "w", stdout);
  n = RD();
  m = RD();
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  for (register int i(1), _tmp(a[i]); i < n; ++i, _tmp = a[i]) {
    for (register int j(i + 1); j <= n; ++j) {
      _tmp ^= a[j];
      if (_tmp == 0) {
        ++ans;
      }
    }
  }
  // printf("ans %d\n", ans);
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    // printf("bfr %d\n", tmp);
    ans -= Chck(A);
    Chng(A, B);
    ans += Chck(A);
    // printf("now %d\n", ans);
    Mx = max(ans, Mx);
    Mn = min(ans, Mn);
    if (ans % 2) {
      ++J;
    }
    _Xor = _Xor ^ ans;
  }
  printf("%d\n%d\n%d\n%d\n", _Xor, J, Mx, Mn);
  // system("pause");
  return 0;
}