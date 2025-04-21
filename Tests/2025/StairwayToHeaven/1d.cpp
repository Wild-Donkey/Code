#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
signed main() {
  unsigned A, B;
  A = RD(), B = 0;
  while (A) A >>= 1, ++B;
  A = 1, --B;
  while (B) A <<= 1, --B;
  printf("%u\n", A);
  return 0;
}