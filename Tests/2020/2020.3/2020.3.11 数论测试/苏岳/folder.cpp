#include<stdio.h>
long long abss(long long aa){return aa>=0?aa:-aa;}
long long exgcd(long long a,long long b,long long* x,long long* y){
if(b==0){
    *x=1;
    *y=0;
    return a;
}
  long long r=exgcd(b,a%b,x,y);
  long long temp=*x;       
  *x=*y;
  *y=temp-(a/b)*(*y);
  return r;
}
int main(){
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	long long a,b,c,gcd,t,*x,*y;
	scanf("%lld%lld%lld",&a,&b,&c);
	x=new (long long);y=new (long long);
	gcd=exgcd(a,-b,x,y);
	if(c%gcd!=0){printf("N0\nO\n");return 0;}
	t=c/gcd;
	long long x1=*x*t,y1=*y*t,a1=abss(b/gcd),a2=abss(a/gcd);
	if(x1<0||y1<0){
		long long s1=abss(x1/a1),s2=abss(y1/a2);
		if(s1<s2)s1=s2;
		x1+=(s1+1)*a1;y1+=(s1+1)*a2; 
	}else{
		long long s1=abss(x1/a1),s2=abss(y1/a2);
		if(s1>s2)s1=s2;
		x1-=s1*a1;y1-=s1*a2;
	}
//	printf("%lld %lld\n",x1,y1);
	printf("YE5\n%lld\n",x1);
	fclose(stdin);fclose(stdout);
	return 0;
}
