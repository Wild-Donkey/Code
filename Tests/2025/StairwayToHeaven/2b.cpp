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
int Mid[100005], Down[100005];
unsigned Mn = 0, Dn = 0;
bitset<10000000> Up;
char Flg = 0;
unsigned n;
signed main() {
  n = RD();
  for (unsigned i = 1; i <= n; ++i) {
    int TmpA = RDsg();
    unsigned TmpB = RD();
    // printf("%u Get %d %u\n", i, TmpA, TmpB);
    if (TmpB == 0) Down[++Dn] = TmpA;
    if (TmpB == 1) Mid[++Mn] = TmpA;
    if (TmpB == 2) Up[TmpA + 5000000] = 1;
  }
  sort(Mid + 1, Mid + Mn + 1);
  sort(Down + 1, Down + Dn + 1);
  Mn = unique(Mid + 1, Mid + Mn + 1) - Mid - 1;
  Dn = unique(Down + 1, Down + Dn + 1) - Down - 1;
  // printf("M %u D %u\n", Mn, Dn);
  int Lst1 = 0xafafafaf, Lst2 = 0xafafafaf;
  int i = Mid[1], j;
  for (unsigned I = 1; I <= Mn; i = Mid[++I]) {
    if (i <= Lst1) break;
    Lst1 = i, j = Down[1];
    for (unsigned J = 1; J <= Dn; j = Down[++J]) {
      if (j <= Lst2) break;
      Lst1 = i;
      if (Up[i + (i - j) + 5000000]) {
        printf("[%d, 0] [%d, 1] [%d, 2]\n", j, i, i + (i - j));
        Flg = 1;
      }
    }
  }
  if (!Flg) printf("-1\n");
  return 0;
}