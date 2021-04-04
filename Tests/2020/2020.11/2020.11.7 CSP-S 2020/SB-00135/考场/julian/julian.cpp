#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
inline long long RD() {
  long long Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-')&&((Ichr > '9')||(Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while (Ichr >= '0' && Ichr <= '9') {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
long long Q, R;
long long Mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long BC(1721424)/*1720245 + 1179*/, year4(1461), year100(36524), year400(146097), _1582(577738)/*577460 + 273 + 4*/, year3(1095);
long long tmpy4, tmpy, ans, tmpy100, tmpy400;
void Clr () {
  ans = 0;
}
void Gtmd (int x) {
  for (register int i(1); i <= 12; ++i) {
    if (x > Mth[i]) {
      x -= Mth[i];
      continue;
    } else {
      printf("%d %d ", x, i);
      return;
    }
  }
  return;
}
int main() {
  freopen("julian3.in", "r", stdin);
  freopen("julian.out", "w", stdout);
  Q = (int)RD();
  for (register int i(1); i <= Q; ++i) {
    //printf("%d\n", i - 1);
    Clr();
    R = RD();
    R++;
    if(R <= BC) {
      tmpy4 = (R - 1) / year4;
      R -= year4 * tmpy4;
      tmpy = (R - 2) / 365;
      R -= 365 * tmpy;
      //printf("%d\n", R);
      ans += tmpy;
      ans += tmpy4 * 4;
      //printf("%d\n", ans);
      if (ans % 4 == 0) {
        if (R < 60) {
          Gtmd(R);
          printf("%d BC\n", 4713 - ans);
        }
        if (R == 60) {
          printf("29 2 %d BC\n", 4713 - ans);
        }
        if (R > 60) {
          Gtmd(R - 1);
          printf("%lld BC\n", 4713 - ans);
        }
      } else {
        //printf("faq\n");
        Gtmd(R - 1);
        printf("%lld BC\n", 4713 - ans);
      }
    } else {
      R -= BC;
      if (R >= _1582) {
        // printf("ops\n");
        R += 288;
        R -= _1582;
        //Gtmd(R);
        //printf("%d\n", R);
        if(R <= 365) {//1582
          Gtmd(R);
          printf("1582\n");
          continue;
        }
        R -= 365;
        if(R <= 365) {
          Gtmd(R);
          printf("1583\n");
          continue;
        }
        R-=365;
        ans = 1584;
        if (R <= 5844) {
          //printf("here\n");
          tmpy4 = (R - 1) / year4;
          R -= tmpy4 * year4;
          tmpy = (R - 2) / 365;
          R -= 365 * tmpy;
          ans += tmpy4 * 4 + tmpy;
          if(tmpy) {
            R--;
            Gtmd(R);
            printf("%d\n", ans);
          } else {
            if (R < 60) {
              Gtmd(R);
              printf("%d\n", ans);
            }
            if (R == 60) {
              printf("29 2 %d\n", ans);
            }
            if (R > 60) {
              Gtmd(R - 1);
              printf("%lld\n", ans);
            }
          }
          continue;
        }
        R -= 5844;
        ans = 1600;
        tmpy400 = (R - 1) / year400;//400
        R -= tmpy400 * year400;
        tmpy100 = (R - 2) / year100;//100
        R -= tmpy100 * year100;
        if(tmpy100) {
          R--;
        }
        tmpy4 = R / year4;
        R -= tmpy4 * year4;
        if (tmpy4 && tmpy100) {
          R++;
        }
        tmpy = (R - 2) / 365;
        R -= tmpy * 365;
        if(tmpy) {
          if(tmpy100) {
            if(!tmpy4)
              R++;
          } else {
            if(tmpy4) {
              //R--;
            }
          }
        }
        if(tmpy100) {
          if(!tmpy4) {
            if(!tmpy) {
              R++;
            }
          }
        }
        ans += tmpy + 4 * tmpy4 + 100 * tmpy100 + 400 * tmpy400;
        if(R == 0) {
          ans--;
          printf("31 12 %d\n", ans);
          continue;
        }
        if (tmpy100 == 0 && tmpy4 == 0 && tmpy == 0) {//400
          ans += tmpy400 * 400;
          if (R < 60) {
            Gtmd(R);
            printf("%d\n", ans);
          }
          if (R == 60) {
            printf("29 2 %d\n", ans);
          }
          if (R > 60) {
            if(R == 1) {
              ans--;
              printf("31 12 %d\n", ans);
              continue;
            }
            Gtmd(R - 1);
            printf("%lld\n", ans);
          }
          continue;
        }
        if(tmpy4 == 0 && tmpy == 0) {//100
          R--;
          Gtmd(R);
          printf("%d\n", ans);
          continue;
        }
        if(tmpy == 0) {//4
          if (R < 60) {
            Gtmd(R);
            printf("%d\n", ans);
          }
          if (R == 60) {
            printf("29 2 %d\n", ans);
          }
          if (R > 60) {
            if(R == 1) {
              ans--;
              printf("31 12 %d\n", ans);
              continue;
            }
            Gtmd(R - 1);
            printf("%lld\n", ans);
          }
          continue;
        }
        R--;
        Gtmd(R);
        printf("%d\n", ans);
        continue;

      } else {
        if (R <= year3) {
          tmpy = (R - 1) / 365;
          R -= 365 * tmpy;
          ans += tmpy;
          Gtmd(R);
          printf("%lld\n", ans + 1);
        } else {
          R -= year3;
          ans += 3;
          tmpy4 = (R - 1) / year4;
          R -= year4 * tmpy4;
          tmpy = (R - 1) / 365;
          R -= 365 * tmpy;
          //printf("%d\n", R);
          ans += tmpy;
          ans += tmpy4 * 4;
          //printf("%d\n", ans);
          if (ans % 4 == 3) {
            if (R < 60) {
              Gtmd(R);
              printf("%d\n", ans + 1);
            }
            if (R == 60) {
              printf("29 2 %d\n", ans + 1);
            }
            if (R > 60) {
              Gtmd(R - 1);
              printf("%lld\n", ans + 1);
            }
          } else {
            //printf("faq\n");
            Gtmd(R - 1);
            printf("%lld\n", ans + 1);
          }
        }
      }
    }
  }
  return 0;
}
