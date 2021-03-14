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
/*
And the univers said I love you.
And the univers said you are the daylight.
And the univers said you are not alone.
And the univers said you are the night.
*/
using namespace std;
int n, m ,k , ans = 0, Maxps, Maxst;
bool flg;
char ch;
string s;
struct Psger {
	int Tim, St, Ar;
}P[10005];
struct Stt {
	int Dist, ManCnt, LeTi, ManOff, ManOn, Latst;
}S[1005];
bool cmpp (Psger x, Psger y) {
	if (x.St == y.St) {
		return x.Tim < y.Tim;
	}
	return x.St < y.St;
}
bool cmps (Stt x, Stt y) {
	return x.ManCnt > y.ManCnt;
} 
inline int In() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  m = In();
  n = In();
  k = In();
  memset(S, 0, sizeof(S));
  memset(P, 0, sizeof(P));
  for (register int i(1); i < m; ++i) {
  	S[i].Dist = In();//Time for travel from the station (i) to the station (i + 1)
	}
  for (register int i(1); i <= n; ++i) {
		P[i].Tim = In();//When this guy arrive 
		P[i].St = In();//The start station
		P[i].Ar = In();//The final station
		++S[P[i].Ar].ManOff;
		++S[P[i].St].ManOn;
	}
	sort(P + 1, P + n + 1, cmpp);//Sort by the start station
	for (register int i(1),j(1); i <= m; ++i) {
		ans += S[i - 1].ManCnt * S[i - 1].Dist;//Traveling
		S[i].ManCnt = S[i - 1].ManCnt - S[i].ManOff;
		S[i].LeTi = S[i - 1].LeTi + S[i - 1].Dist;
		while (P[j].St == i) {//The bus waits for passengers
			if (P[j].Tim > S[i].LeTi) {
				ans += S[i].ManCnt * (P[j].Tim - S[i].LeTi);
				S[i].LeTi = P[j].Tim;
			}
			else {
				ans += S[i].LeTi - P[j].Tim;
			}
			++S[i].ManCnt;
			//printf("sta:%d psg:%d tim:%d S[%d].manoff:%d\n", i, j, ans, i, S[i].ManOff);
			++j;
		}
		S[i].Latst = P[j - 1].Tim;
	}
	//printf("%d\n", ans);
	while (k) {//Use the N2
		for (register int i(1); i < m; ++i) {//Where to use
			if (S[i].Dist <= 0) {
				continue;
			}
			int j(i + 1), tmp(0);
			tmp += S[i + 1].ManOff;
			while (S[j].LeTi > S[j].Latst && j < m) {//Passengers wait for the bus
				tmp += S[j + 1].ManOff;
				//tmp += S[j].ManOn;
				++j;
			}
			if (tmp > Maxps) {
				Maxps = tmp;
				Maxst = i;
			}
		}
		if (Maxps <= 0) {
			break;
		}
		ans -= Maxps;
		--S[Maxst].Dist;
		Maxps = 0;
		for (register int i(Maxst + 1); i <= m; ++i) {
			--S[i].LeTi;
			if (S[i].LeTi < S[i].Latst) {
				S[i].LeTi = S[i].Latst;
				break;
			}
		}
		Maxst = 0;
		--k;
	}
	printf("%d\n", ans);
	// fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
3 3 2
1 4
0 1 3
1 1 2
5 2 3

10
*/
