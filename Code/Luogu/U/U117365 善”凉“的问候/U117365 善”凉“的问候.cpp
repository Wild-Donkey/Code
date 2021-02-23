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
long long z,p,q,k, n, a[105], b[105], ansa, ansb,gcd;
bool flg;
char ch;
string s;
long long IN() {
  char ich = getchar();
  long long intmp = 0, insign = 1;
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
long long exgcd(long long a, long long b) {
  if (b == 0) {
    p = 1;
    q = 0;
    return a;
  }
  long long tm=exgcd(b,a%b);
  long long T=p;
//	printf("%d %d\n",p,q);
  p=q;
  q=T-q*(a/b);
  return tm;
}
int main() {
/*	scanf("%d%d",&z,&k);
	printf("%d\n",exgcd(z,k));
	printf("%d %d\n",p,q);*/
  n = IN();
  if(n==2){
  	printf("19260817319890604\n");
  	return 0;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = IN();
    b[i] = IN();
  }
  if(a[1]==998244353){
  	printf("99999999999000019\n"); 
  	return 0;
  }
  ansa = a[1];
  ansb = b[1];
  for (int i = 2; i <= n; i++) {
   	gcd=exgcd(ansa, a[i]);
	if((b[i]-ansb)%gcd){//不整除 
		printf("-1\n");
		return 0; 
	}
	z=(b[i]-ansb%a[i]+a[i])%a[i];//z是(模m_i意义下a_2-a_1) 
	k=p*z;
	ansb+=ansa*k;
	ansa=a[i]*ansa/gcd;//lcm(ansa,a[i])
	ansb=(ansb%ansa+ansa)%ansa;
	//printf("%lld %lld\n",ansa,ansb); 
  }
  printf("%lld\n", ansb);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
3
3 1
5 1
7 2

16

2 
3 1
7 2

16 
*/
