#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#define fys 0;
using namespace std;
inline unsigned long long IN() {
  unsigned long long Itmp(0);
  char Ichr(getchar());
  while (Ichr > '9' || Ichr < '0') {
    Ichr = getchar();
  }
  while (Ichr <= '9' && Ichr >= '0') {
    Itmp *= 10;
    Itmp += Ichr - '0';
    Ichr = getchar();
  }
  return Itmp;
}
unsigned int n, m, DoWt;
long long ans, Lans(0), Tag(0);
multiset<long long> N;
inline int Clr() { return fys; }
int main() {
  // while (1) {
  //   printf("%llu\n", IN());
  // }
  freopen("difficult1.in", "r", stdin);
  // freopen("difficult.out", "w", stdout);
  m = int(IN());
  for (register unsigned int i(1); i <= 1; ++i) {
    printf("%u\n", IN());
    // DoWt = int(IN()) ^ int(Lans);
    printf("i = %u, DoWt = %d, Lans = %d\n", i, DoWt, Lans);
    switch (DoWt) {
      case 1: {
        N.insert(IN() - Tag);
        break;
      }
      case 2: {
        N.erase(IN() - Tag);
        break;
      }
      case 3: {
        if (N.empty()) {
          printf("zay\n");
          break;
        }
        Lans = *N.begin() + Tag;
        printf("%lld\n", Lans);
      } break;
      case 4: {
        if (N.empty()) {
          printf("zay\n");
          break;
        }
        Lans = *N.end() + Tag;
        printf("%lld\n", Lans);
        break;
      }
      case 5: {
        ans = *(--N.lower_bound(IN() - Tag));
        if (ans) {
          Lans = ans + Tag;
          printf("%d\n", Lans);
        } else {
          printf("cuc\n");
        }
        break;
      }
      case 6: {
        ans = *N.upper_bound(IN() - Tag);
        if (ans) {
          Lans = ans + Tag;
          printf("%d\n", Lans);
        } else {
          printf("cyc\n");
        }
        break;
      }
      case 7: {
        Tag += IN();
        break;
      }
      default: {
        printf("FYSNB\n");
        break;
      }
    }
  }
  return fys;
}