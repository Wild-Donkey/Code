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
  int A, B, C;
  cin >> A >> B >> C;
  if (B == 1) {//out
    if (A <= 35 || C < 33) {
      cout << "Bu Re\n" << C << '\n';
      return 0;
    } else {
      cout << "Bu Tie\n" << A << '\n';
      return 0;
    }
  } else {//in
    if (A > 35 && C >= 33) {
      cout << "Shi Nei\n" << A << '\n';
      return 0;
    } else {
      cout << "Shu Shi\n" << C << '\n';
      return 0;
    }
  }
  return 0;
}