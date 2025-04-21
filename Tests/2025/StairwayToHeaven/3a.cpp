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
unsigned A, B, C, D;
unsigned n, m, q, Money;
unsigned Mat[505][505], Emo[505][505];
signed main() {
  Money = RD(), n = RD(), m = RD(), q = RD();
  memset(Mat, 0x3f, sizeof(Mat));
  memset(Emo, 0x3f, sizeof(Emo));
  for (unsigned i = 1; i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    Mat[A][B] = Mat[B][A] = C;
    Emo[A][B] = Emo[B][A] = D;
  }
  for (unsigned i = 1; i <= n; ++i) {
    for (unsigned j = 1; j <= n; ++j) if (j != i) {
      for (unsigned k = 1; k < j; ++k) if (k != i) {
        if (Mat[j][k] == Mat[j][i] + Mat[i][k]) {
          Emo[k][j] = Emo[j][k] = max(Emo[j][k], Emo[j][i] + Emo[i][k]);
        } else if (Mat[j][k] > Mat[j][i] + Mat[i][k]) {
          Mat[k][j] = Mat[j][k] = Mat[j][i] + Mat[i][k];
          Emo[k][j] = Emo[j][k] = Emo[j][i] + Emo[i][k];
        }
      }
    }
  }
  for (unsigned i = 1; i <= q; ++i) {
    A = RD();
    vector<unsigned> OuTmp, ETmp;
    unsigned MaxEmo = 0;
    for (unsigned j = 1; j <= n; ++j) if (Mat[A][j] <= Money) {
      OuTmp.push_back(j);
      MaxEmo = max(MaxEmo, Emo[A][j]);
    }
    if (!OuTmp.size()) {
      printf("T_T\n");
      continue;
    }
    for (auto j : OuTmp) if (Emo[A][j] == MaxEmo) {
      ETmp.push_back(j);
    }
    printf("%u", OuTmp[0]);
    for (unsigned j = 1; j < OuTmp.size(); ++j) {
      printf(" %u", OuTmp[j]);
    }
    putchar(0x0A);
    printf("%u", ETmp[0]);
    for (unsigned j = 1; j < ETmp.size(); ++j) {
      printf(" %u", ETmp[j]);
    }
    putchar(0x0A);
  }
  return 0;
}