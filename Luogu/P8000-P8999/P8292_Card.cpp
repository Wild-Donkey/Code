#include<algorithm>
#include<bitset> 
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const unsigned long long Mod(998244353);
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
inline void Mn(unsigned long long& x) { x -= ((x >= Mod) ? Mod : 0); }
inline unsigned RD() {
  unsigned RTmp(0);
  char ch(getchar());
  while (ch < '0' && ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') RTmp = RTmp * 10 + ch - '0', ch = getchar();
  return RTmp;
}
bitset<2005> No;
unsigned f[295][8200], PopC[8200], Two[1000005], b[18005];
unsigned Cont[2005], Ind[2005], a[2005], Pri[320];
unsigned CntP(0), n, m, A, B, C, Cur(0), Cond(0), Ans;
inline void Pre(unsigned* x) {
  for (unsigned i(1); i <= 4096; i <<= 1)
    for (unsigned j(0); j < 8191; ++j) if (!(j & i))
      x[j] += x[j ^ i];
  for (unsigned i(8191); ~i; --i) {
    if (PopC[i] & 1) x[i] = -x[i];
    for (unsigned j((i - 1)& i); j ^ i; j = ((j - 1) & i))
      if (PopC[j] & 1) x[i] -= x[j]; else x[i] += x[j];
  }
}
inline void DFS(unsigned Dep) {
  if (b[Dep] > 41) {
    //    if(!Cur) return;
    //    printf("Cond %u\n", Cond);
    unsigned Number(f[0][Cond]), FN(0);
    unsigned long long Sum(1);
    //    for (unsigned i(C); b[i] > 41; --i) printf("%u:%u ", i, b[i]); putchar(0x0A);
    for (unsigned i(C); b[i] > 41; --i)
      FN = f[Ind[b[i]] - 13][Cond], Sum = Sum * (Two[FN] - 1) % Mod, Number -= FN;
    Sum = Sum * Two[Number] % Mod;
    //    printf("Cur %llu Cond %u Cur %u %u %u\n", Sum, Cond, Cur, Number, f[Ind[59] - 13][Cond]);
    Mn(Ans += ((Cur & 1) ? (Mod - Sum) : Sum));
    return;
  }
  DFS(Dep + 1);
  Cond ^= (1 << (Ind[b[Dep]] - 1)), ++Cur;
  DFS(Dep + 1);
  Cond ^= (1 << (Ind[b[Dep]] - 1)), --Cur;
}
int main() {
  //  freopen("card.in", "r", stdin);
  //  freopen("card.out", "w", stdout);
  for (unsigned i(0); i < 8192; ++i) PopC[i] = PopC[i >> 1] + (i & 1);
  for (unsigned i(0); i < 8192; ++i) PopC[i] = PopC[i >> 1] + (i & 1);
  for (unsigned i(2); i <= 2000; ++i) {
    if (!No[i]) Pri[++CntP] = i;
    for (unsigned j(1), k(2); (j <= CntP) && (k * i <= 2000); k = Pri[++j]) {
      No[i * k] = 1;
      if (!(i % k)) break;
    }
  }
  for (unsigned i(1); i <= 303; ++i) Ind[Pri[i]] = i;
  for (unsigned i(1), k(1); i <= 13; ++i, k <<= 1)
    for (unsigned j((2000 / Pri[i])* Pri[i]); j; j -= Pri[i]) Cont[j] |= k;
  n = RD(), Two[0] = 1;
  for (unsigned i(1); i <= n; ++i) Two[i] = (Two[i - 1] << 1), Mn(Two[i]);
  for (unsigned i(1); i <= n; ++i) ++a[RD()];
  for (unsigned i(1); i <= 2000; ++i) f[0][Cont[i]] += a[i];
  //  for (unsigned j(0); j < 8; ++j) printf("%u ", f[0][j]); putchar(0x0A);
  Pre(f[0]);
  //  for (unsigned j(0); j < 8; ++j) printf("%u ", f[0][j]); putchar(0x0A);
  for (unsigned i(14); i <= 303; ++i) {
    for (unsigned j(2000 / Pri[i]); j; --j) f[i - 13][Cont[j]] += a[j * Pri[i]];
    Pre(f[i - 13]);
    //    for (unsigned j(0); j < 8; ++j) printf("%u ", f[i - 13][j]); putchar(0x0A);
  }
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    C = RD();
    Ans = Cur = 0;
    for (unsigned j(1); j <= C; ++j) b[j] = RD();
    sort(b + 1, b + C + 1), C = unique(b + 1, b + C + 1) - b - 1;
    b[C + 1] = 0x3f3f3f3f, Cur = 0, DFS(1);
    printf("%u\n", Ans);
  }
  return 0;
}
/*
5 4 0 0 3 2 0 0
5
10 2 10 5 46
4
2 2 5
2 2 23
1 3
1 23
*/
