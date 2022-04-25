#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,m,ans=0,a[200005],A=0,B=0,tmp=0;
bool le=1;
int main(){
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n;
		ans=0;
		A=0;
		B=0;
		tmp=0;
		le=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l=1,r=n;
		while(l<=r){
			int sum=0;
			ans++; 
			if(le){//�����ѡ 
				while(sum<=tmp){
					if(l==r){
						sum+=a[l];
						A+=a[l];
						l++;
						break;
					}
					sum+=a[l];
					A+=a[l];
					l++;
				}
			}
			else{//���ұ�ѡ 
				while(sum<=tmp){
					if(l==r){
						sum+=a[r];
						B+=a[r];
						r--;
						break;
					}
					sum+=a[r];
					B+=a[r];
					r--;
				}
			}
			tmp=sum;
			le=!le;
		}
		cout<<ans<<" "<<A<<" "<<B<<endl;
	}
	return 0;
}
