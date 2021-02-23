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
using namespace std;
int t, n, ans = 0;
bool flg;
char ch;
string s;
struct Big{
	int a[10005];
	int len;
	Big(int x = 0){
		memset(a, 0, sizeof(a)); 
		len = 3;
		a[1] = x % 10000;
		a[2] = (x / 10000) % 10000;
		a[3] = x / 100000000;
		if(a[3] == 0) {
			len--;
			if(a[2] == 0) {
				len--;
			}
		}
	}
};
/*struct Man{
	Big lh, rh, tied;
}M[10005];*/
Big operator * (Big x, Big y){
	Big tians = Big(0);
	tians.len = x.len + y.len;
	for(int i = 1; i <= x.len; i++) {
		for(int j = 1; j <= y.len; j++){
			tians.a[i + j - 1] += x.a[i] * y.a[j];
			/*for(int k = 1; k <= tians.len; k++){
				printf("%d %d\n", k, tians.a[k]);
			}*/
			//printf("%d %d\n", i + j - 1, tians.a[i + j - 1]);
			tians.a[i + j] += tians.a[i + j - 1] / 10000;
			/*for(int k = 1; k <= tians.len; k++){
				printf("%d %d\n", k, tians.a[k]);
			}*/
			//printf("%d %d\n", i + j, tians.a[i + j]);
			tians.a[i + j - 1] %= 10000;
			//printf("%d %d\n", i + j, tians.a[i + j]);
		}
	}
	/*tians.a[x.len + y.len + 1] += tians.a[x.len + y.len] / 10000;
	tians.a[x.len + y.len] %= 10000;*/
	while(tians.a[tians.len] == 0){
		tians.len--;
	}
	return tians;
}
Big operator / (Big x, Big y){
	int Y = 0;
	for(int i = y.len; i >= 1; i--){
		Y *= 10000;
		Y += y.a[i];
	}
	//printf("%d\n", Y);
	Big deans = Big(0);
	deans.len = x.len;
	long long now = 0;
	for(int i = x.len; i >= 1; i--){
		now *= 10000;
		now += x.a[i];
		deans.a[i] = now / Y;
		now %= Y;
		//printf("%d %d\n", i, deans.a[i]);
	}
	while (deans.a[deans.len] == 0) {
		deans.len--;
	} 
	return deans;
} 
void Print(Big x){
	/*if (x.len == 0) {
		printf("0\n");
	}*/
	printf("%d", x.a[x.len]);
	for(int i = x.len - 1; i >= 1; i--){
		printf("%04d", x.a[i]);
	}
	printf("\n");
	return;
} 
Big bIN() {
	string ich;
	Big ansin = Big(0);
	cin >> ich;
	int ini = ich.length() - 4; 
	while (ini >= 0) {
		for(int inj = 0; inj < 4; inj++) {
			ansin.a[ansin.len] *= 10;
			ansin.a[ansin.len] += ich[ini + inj] - '0';
		}
		//printf("%d %d\n", ansin.len, ansin.a[ansin.len]);
		ini -= 4;
		ansin.len++;
	}
	if (ich.length() % 4) {
		for(int inj = 0; inj < ini + 4; inj ++) {
			ansin.a[ansin.len] *= 10;
			ansin.a[ansin.len] += ich[inj] - '0';
			//printf("%d %d\n", ansin.len, ansin.a[ansin.len]);
		}
		ansin.len++;
	}
	ansin.len--;
  return ansin;
}
inline int IN() {
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
    /*n = IN();
    for (register int i = 0; i <= n; i++) {
    	M[i].lh = Big(IN());
    	M[i].rh = Big(IN());
    	M[i].tied = M[i].lh * M[i].rh;
    	Print (M[i].tied);
    }*/
    
    Big ta = bIN(), tb = Big(IN());
	//Print(ta);
	//Print(tb);
    Print(ta / tb);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
100000000
100000001
*/

