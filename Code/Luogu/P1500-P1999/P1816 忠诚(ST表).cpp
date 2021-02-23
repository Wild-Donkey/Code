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
int t, m,n, a[10005], askl,askr,two[20],f[20][100005],max_two,lo[100005];
bool flg;
char ch;
string s;
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
void Two(){
	two[0]=1;
	for(register int i=1;i<=17;i++){
		two[i]=two[i-1]<<1;
		if(two[i]>m){
			max_two=i-1;
			return;
		}
	}
	return;
}
void Build(){
	for(int i=1;i<=max_two;i++){
		for(register int j=1;j<=m-two[i]+1;j++){
			f[i][j]=min(f[i-1][j],f[i-1][j+two[i-1]]);
			//printf("%d %d %d\n",j,j+two[i]-1,f[i][j]); 
		}
	}
	return;
}
int Ask(int L,int R){
	int len=R-L+1;
	if(len==two[lo[len]]){
		return f[lo[len]][L];
	}
	return min(f[lo[len]][L],f[lo[len]][R-two[lo[len]]+1]);
}
int main() {
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	m = IN(),n=IN();
	Two();
	int ti=0;
	for (register int i = 1; i <= m; i++) {
		f[0][i] = IN();
		if(i>=two[ti]){
			lo[i]=ti;
			ti++;
		}
		else{
			lo[i]=lo[i-1];
		}
		//printf("%d %d\n",i,lo[i]); 
	}
	Build();
	for (register int i = 1; i <= n; i++) {
		askl = IN();
		askr=IN();
		printf("%d ", Ask(askl,askr));
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}

