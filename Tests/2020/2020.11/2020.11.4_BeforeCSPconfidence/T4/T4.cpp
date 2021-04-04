#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
inline int RD() {
	int Itmp(0), Isig(1);
	char Ichr(getchar());
	while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
		Ichr = getchar();
	}
	if (Ichr == '-') {
		Isig = -1;
		Ichr = getchar();
	}
	while ((Ichr >= '0') && (Ichr <= '9')) {
		Itmp = Itmp * 10 + Ichr - '0';
		Ichr = getchar();
	}
	return Itmp * Isig;
}
inline void PR(long long Prtmp, bool SoE) {
	long long Prstk(0), Prlen(0);
	if (Prtmp < 0) {
		putchar('-');
		Prtmp = -Prtmp;
	}
	do {
		Prstk = Prstk * 10 + Prtmp % 10;
		Prtmp /= 10;
		++Prlen;
	} while (Prtmp);
	//printf("%d", Prtmp);
	do {
		putchar(Prstk % 10 + '0');
		Prstk /= 10;
		--Prlen;
	} while (Prlen);
	if (SoE) {
		putchar('\n');
	} else {
		putchar(' ');
	}
	return;
}
const char C[5][3] = {"HS","TS","HP","TP"};
int n, m, A, _1_1, _1_m1, _1_m, _n_1, _n1_1, _n_m, _n1_m, _n1_m1, _n_m1;
int Fd[5][5][5] = {0};
int cnt(0), stk[105][5] = {0};
int main() {
	freopen("data2.in", "r", stdin);
	//freopen("4.out", "w", stdout);
	n = RD();
	m = RD();
	_1_1 = RD() + 1;
	for (register int i(2); i < m; ++i) {
		A = RD();
	}
	_1_m = RD() + 1;
	if(m % 2) {
	  _1_m1 = A + 1;
	}
	for (register int i(2); i < n; ++i) {
	  A = RD();
  }
  if(n % 2) {
    _n1_1 = A + 1;
  }
  _n_1 = RD() + 1;
	bool flg;
	for(register int i(1); i <= 4; ++i) {
		for (register int j(i); j <= 4; ++j) {
			for (register int k(j); k <= 4; ++k) {
				for (register int l(k); l <= 4; ++l) {
					flg = 0;
					if((i!=j)&&(j!=k)&&(k!=l)) {
						flg = 1;
					}
					if((i==j)&&(k==l)) {
						if(k - i == 2 || (k - i == 1 && i != 2)) {//2|3
							flg = 1;
						}
					}
					if(j==k) {
						if((i==j)&&(i + l == 5)) {
							flg = 1;
						}
						if((k==l)&&(i + l == 5)) {
							flg = 1;
						}
					}
					if(flg) {
						stk[++stk[0][0]][1] = i;
						stk[stk[0][0]][2] = j;
						stk[stk[0][0]][3] = k;
						stk[stk[0][0]][4] = l;
					}
				}
			}
		}
	}
	for(register int i(1); i <= stk[0][0]; ++i) {
		//printf("%d %d %d %d\n", stk[i][1], stk[i][2], stk[i][3], stk[i][4]);
		Fd[stk[i][1]][stk[i][2]][stk[i][3]] = stk[i][4];
		Fd[stk[i][1]][stk[i][3]][stk[i][2]] = stk[i][4];
		Fd[stk[i][2]][stk[i][1]][stk[i][3]] = stk[i][4];
		Fd[stk[i][2]][stk[i][3]][stk[i][1]] = stk[i][4];
		Fd[stk[i][3]][stk[i][2]][stk[i][1]] = stk[i][4];
		Fd[stk[i][3]][stk[i][1]][stk[i][2]] = stk[i][4];
		Fd[stk[i][1]][stk[i][2]][stk[i][4]] = stk[i][3];
		Fd[stk[i][1]][stk[i][4]][stk[i][2]] = stk[i][3];
		Fd[stk[i][2]][stk[i][1]][stk[i][4]] = stk[i][3];
		Fd[stk[i][2]][stk[i][4]][stk[i][1]] = stk[i][3];
		Fd[stk[i][4]][stk[i][2]][stk[i][1]] = stk[i][3];
		Fd[stk[i][4]][stk[i][1]][stk[i][2]] = stk[i][3];
		Fd[stk[i][1]][stk[i][4]][stk[i][3]] = stk[i][2];
		Fd[stk[i][1]][stk[i][3]][stk[i][4]] = stk[i][2];
		Fd[stk[i][4]][stk[i][1]][stk[i][3]] = stk[i][2];
		Fd[stk[i][4]][stk[i][3]][stk[i][1]] = stk[i][2];
		Fd[stk[i][3]][stk[i][4]][stk[i][1]] = stk[i][2];
		Fd[stk[i][3]][stk[i][1]][stk[i][4]] = stk[i][2];
		Fd[stk[i][3]][stk[i][2]][stk[i][4]] = stk[i][1];
		Fd[stk[i][3]][stk[i][4]][stk[i][2]] = stk[i][1];
		Fd[stk[i][2]][stk[i][3]][stk[i][4]] = stk[i][1];
		Fd[stk[i][2]][stk[i][4]][stk[i][3]] = stk[i][1];
		Fd[stk[i][4]][stk[i][2]][stk[i][3]] = stk[i][1];
		Fd[stk[i][4]][stk[i][3]][stk[i][2]] = stk[i][1];
	}
	int tmp[2];
	/*for (register int i(1); i <= 4; ++i) {
	  for (register int j(1); j <= 4; ++j) {
	    for (register int k(1); k <= 4; ++k) {
	      printf("%d %d %d %d  ",i,j,k,Fd[i][j][k]);
	  }
	  printf("\n");
	}
	printf("\n");
	}*/
	/*for (register int i(2); i <= n; ++i) {
		tmp[1] = a[1];
		a[1] = RD() + 1;
		for (register int j(2); j <= m; ++j) {
			tmp[j % 2] = a[j];
			a[j] = Fd[a[j - 1]][a[j]][tmp[(j + 1) % 2]];
		}
	}*/
	if(m % 2) {
	  if(n % 2) {
	    _n1_m1 = Fd[_1_1][_1_m1][_n1_1];
	    _n1_m = Fd[_1_m1][_1_m][_n1_m1];
	    _n_m1 = Fd[_n1_1][_n_1][_n1_m1];
	    _n_m = Fd[_n1_m1][_n_m1][_n1_m];
    }
    else {
	    _n_m1 = Fd[_1_1][_1_m1][_n_1];
	    _n_m = Fd[_1_m1][_n_m1][_1_m];
    }
  }
	else {
	  if(n % 2) {
	    _n1_m = Fd[_1_1][_1_m][_n1_1];
	    _n_m = Fd[_n1_m][_n1_1][_n_1];
    }
    else {
	    _n_m = Fd[_1_1][_1_m][_n_1];
    }
  }
	cout <</*a[m]<<"  "<< */C[_n_m - 1] << "\n";
	return 0;
}
/*
Can
1 1 1 4
1 1 2 2
1 1 3 3
1 2 3 4
1 4 4 4
2 2 2 3
2 2 4 4
2 3 3 3
3 3 4 4

May
1 1 1 -> 4
1 1 2 -> 2
1 1 3 -> 3
1 1 4 -> 1
1 2 2 -> 1
1 2 3 -> 4
1 2 4 -> 3
1 3 3 -> 1
1 3 4 -> 2
1 4 4 -> 4
2 2 2 -> 3
2 2 3 -> 2
2 2 4 -> 4
2 3 3 -> 3
2 3 4 -> 1
2 4 4 -> 2
3 3 3 -> 2
3 3 4 -> 4
3 4 4 -> 3
4 4 4 -> 1
*/
