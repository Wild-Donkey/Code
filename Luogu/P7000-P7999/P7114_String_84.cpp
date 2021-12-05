#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<queue>
#define Lbt(x) ((x)&((~(x))+1))
using namespace std;
inline unsigned RD() {
  unsigned TmpRD(0);
  char TmpRC(getchar());
  while ((TmpRC < '0') || (TmpRC > '9')) TmpRC = getchar();
  while ((TmpRC >= '0') && (TmpRC <= '9'))
    TmpRD = (TmpRD << 3) + (TmpRD << 1) + TmpRC - '0', TmpRC = getchar();
  return TmpRD;
}
unsigned long long Tr[27], Ans(0);
unsigned n, m, t;
unsigned Hd(0), Tl(0), CntEn(0);
unsigned A, B, C, D;
unsigned Cnt[30], Chi(0);
unsigned Bd[1100005], Suf[1100005];
char a[1100005];
unsigned Set[1100005][27];
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) memset(Set[i], 0, sizeof(Set[i]));
  memset(Cnt, 0, sizeof(Cnt));
  memset(Tr, 0, sizeof(Tr));
  scanf("%s", a + 1), n = strlen(a + 1);
  Ans = Bd[0] = Bd[1] = Chi = 0;
}
signed main() {
//  freopen("string4.in", "r", stdin);
//  freopen("string.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(2), j; i <= n; ++i) {
      j = i - 1;
      while (j && (a[Bd[j] + 1] ^ a[i])) j = Bd[j];
      if(!j) Bd[i] = 0;
      else Bd[i] = Bd[j] + 1;
    }
    for (unsigned i(n); i > 2; --i) {
      if((++Cnt[a[i] - 'a']) & 1) ++Chi;
      else --Chi;
      Suf[i] = Chi;
      unsigned Per(i - 1 - Bd[i - 1]);
      if((i - 1) % Per) Per = i - 1;
      unsigned LP((i - 1) / Per), Sq(sqrt(LP));
      for (unsigned j(1); j <= Sq; ++j) if(!(LP % j)) {
        if((j * j) ^ LP) {
          ++Set[j * Per][Chi];
          ++Set[(i - 1) / j][Chi];
        } else ++Set[j * Per][Chi];
      }
    }
    memset(Cnt, 0, sizeof(Cnt));
    Chi = 0;
    for (unsigned j(1); j < n; ++j) {
      for (unsigned k(0); k <= 26; ++k) Ans += Tr[k] * Set[j][k];
//      for (unsigned k(0); k <= 26; ++k) printf("Set %u %u = %u\n", j, k, Set[j][k]);
      if((++Cnt[a[j] - 'a']) & 1) ++Chi;
      else --Chi;
      for (unsigned k(Chi); k <= 26; ++k) ++Tr[k];
    }
    printf("%llu\n", Ans);
  }
  return 0;
}
