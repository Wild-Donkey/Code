#include<iostream>
#include<cstdio>
using namespace std;
int a[2001], c[10] = { 6,2,5,5,4,5,6,3,7,6 };
int n, ans = 0, b;
int Get(int x) {
  if (!x) return 6;
  int Rt(0);
  while (x)
    Rt += c[x % 10], x /= 10;
  return Rt;
}
int main() {
  cin >> n;
  n -= 4;
  for (int i = 0;i <= 2000;i++) a[i] = Get(i);
  for (int i = 0;i <= 1000;i++)
    for (int j = 0;j <= 1000;j++) {
      b = i + j;
      ans += (a[i] + a[j] + a[b] == n);
    }
  cout << ans;
  return 0;
}