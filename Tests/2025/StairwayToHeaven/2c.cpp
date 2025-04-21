#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
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
vector<pair<unsigned, char> > Lst;
unsigned n;
signed main() {
  n = RD();
  for (unsigned i = 1; i <= n; ++i) {
    unsigned A, B, C;
    A = RD() * 3600, B = RD() * 60, C = RD();
    Lst.push_back({ A + B + C, 0 });
    A = RD() * 3600, B = RD() * 60, C = RD();
    Lst.push_back({ A + B + C, 1 });
  }
  sort(Lst.begin(), Lst.end());
  unsigned Cnt = 0, Ans = 0;
  for (auto i : Lst) {
    if (i.second == 0) ++Cnt;
    else --Cnt;
    Ans = max(Ans, Cnt);
  }
  printf("%u\n", Ans);
  return 0;
}