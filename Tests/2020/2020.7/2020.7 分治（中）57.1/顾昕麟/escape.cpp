#include<cstdio>
#include<cmath>
#include<algorithm>
#define IAKIOI 0
using namespace std;
double dis,walk,drive,flag,ans;
int ti;
void fre()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
}
void work(double l,double r)
{
	ti++;
	if(flag==1) return;
	double mid=(l+r)/2;//ȡ���ֵ�mid
	if(ti>50) 
	{
		flag=1;
		ans=mid;
		return;
	}
	double t1=mid/drive;//��һ���˿�����midʱ�� 
	double s1=t1*walk;//�ڶ��������˶���· 
	double back=mid-s1;//����ȥ�ӵڶ����˵�·�� 
	double t2=back/(walk+drive);//���ӵ��ڶ����˵�ʱ�� 
	double s2=mid+t2*walk;//����ȥ���˵�ʱ���һ�����ߵ�·�� 
	double s3=s1+t2*walk;//�ڶ������ϳ��ĵط� 
	double t3=(dis-s3)/drive;//�ڶ����˵��յ����ʱ 
	double s4=s2+walk*t3;//�ڶ����˵��յ�ʱ����һ���˵�λ�� 
	if(s4>dis||s2>dis) work(l,mid);
	if(s4<dis) work(mid,r); 
}
int main()
{
	fre();
	scanf("%lf%lf%lf",&dis,&walk,&drive);
	if(drive<=walk)
	{
		printf("%0.2lf",dis/walk);
		return IAKIOI;
	}
	work(0,dis);
	double tt1=ans/drive;
	double ss1=tt1*walk;
	double bback=ans-ss1;
	double tt2=bback/(walk+drive);
	double ss3=ss1+tt2*walk;
	double tt3=(dis-ss3)/drive;
	printf("%0.2lf",tt1+tt2+tt3);
	return IAKIOI;
}
