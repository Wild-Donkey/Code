#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const unsigned MOD1(1000000007);
unsigned Hash[26][200005], Bin[200005], m, n, Cnt(0), Len, A, B, C, D, t, Ans(0), Tmp(0), HashA[30], HashB[30];
char a[200005], Flg;
unsigned Find(unsigned L, unsigned R, unsigned *Ha) {
  register unsigned AnsF(Ha[R]);
  AnsF += MOD1 - ((unsigned long long)Ha[L - 1] * Bin[R - L + 1] % MOD1);
  if(AnsF >= MOD1) AnsF -= MOD1;
  return AnsF;
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(); 
  scanf("%s", a + 1);
  Bin[0] = 1;
  for (register unsigned i(1); i <= n; ++i) {Bin[i] = Bin[i - 1] << 1; if(Bin[i] >= MOD1) Bin[i] -= MOD1;}
  for (register unsigned i(0); i < 26; ++i) Hash[i][0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    for (register char j(0); j < 26; ++j) {
      Hash[j][i] = (Hash[j][i - 1] << 1) + (((a[i] - 'a') ^ j) ? 0 : 1);
      if(Hash[j][i] >= MOD1) Hash[j][i] -= MOD1;
    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), Len = RD(), C = A + Len - 1, D = B + Len - 1, Flg = 0;
    for (register unsigned j(0); j < 26; ++j) {
      HashA[j] = Find(A, C, Hash[j]);
      HashB[j] = Find(B, D, Hash[j]);
    }
    sort(HashA, HashA + 26);
    sort(HashB, HashB + 26);
    for (register unsigned j(0); j < 26; ++j) {
      if(HashA[j] ^ HashB[j]) {Flg = 1;break;}
    }
    printf(Flg ? "NO\n" : "YES\n"); 
  }
  //  }
  return Wild_Donkey;
}


