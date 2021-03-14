#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,t=0,sum=0;
char x,y;
struct stu
{
	string name;
	int qm,py,lw,mny;
	bool gb,xb;
};
stu a[105];
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i].name>>a[i].qm>>a[i].py>>x>>y>>a[i].lw;
		if(x=='Y')
			a[i].gb=1;
		if(y=='Y')
			a[i].xb=1;
		if(a[i].qm>80)
			if(a[i].lw)
				a[i].mny+=8000;
		if(a[i].qm>85)
			if(a[i].py>80)
				a[i].mny+=4000;
		if(a[i].qm>90)
			a[i].mny+=2000;
		if(a[i].qm>85)
			if(a[i].xb) 
				a[i].mny+=1000;
		if(a[i].py>80)
			if(a[i].gb)
				a[i].mny+=850;
		sum+=a[i].mny;
		if(a[i].mny>a[t].mny)
			t=i;
	}
	cout<<a[t].name<<endl<<a[t].mny<<endl<<sum<<endl;
	return 0;
}
