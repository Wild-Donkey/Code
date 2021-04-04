#include<cstdio>
#include<cmath>
double s,s1,s2,vr,vc,t1,t2,p;
double a,b;
int main()
{
	freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
	scanf("%lf%lf%lf",&s,&vr,&vc);
	s1=0;s2=s;
	do
	{
		p=(s1+s2)/2.0;
		a=p/vc;
		b=(p-a*vr)/(vr+vc);
		t1=a+(s-p)/vr;
		t2=a+b+(s-(a+b)*vr)/vc;
		if(t1<t2)
		  s2=p;
		else
		  s1=p;
	}
	while(fabs(t1-t2)>1e-8);
	printf("%.2lf",t1);
	return 0;
}
