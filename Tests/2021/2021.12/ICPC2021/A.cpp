#include<iostream>
#include<cstdio>
using namespace std;
unsigned n, t, Ans(1);
signed main() {
  scanf("%u", &t);
  while(t--) {
    scanf("%u", &n), Ans = 1;
    for (unsigned i(1); i <= n; ++i) {
      if((n / i) ^ (n / (i + 1))) ++Ans;
    }
    printf("%u\n", Ans);
  }
  return 0;
} 
