#include<cstdio>
#include<cstdlib>
using namespace std;
double x,ans;
int s,vr,vc;//vrΪ�˵��ٶȣ�vcΪ�����ٶ� 
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	scanf("%d%d%d",&s,&vr,&vc);
	x=(vc+vr)*s/(vc+3*vr);
    ans=x/vc+(s-x)/vr;
    printf("%.2lf",ans);
    return 0;
}
