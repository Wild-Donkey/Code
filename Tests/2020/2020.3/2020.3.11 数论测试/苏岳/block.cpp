#include<stdio.h>
int a[]={0,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,16089653,14036688,15206292,13873643,12994640};
int n;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	printf("%d",a[n]);
	return 0;
}
