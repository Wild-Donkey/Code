#include<iostream>
using namespace std;
int n,a,tmp,k,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>k;
		tmp=k/(a-1);//�Թ������� 
		ans=k-tmp*(a-1);//��Щ��֮��ĵ�ans����
		if(ans==0){
			cout<<tmp*a-1<<endl;
			continue;
		} 
		tmp*=a;
		ans+=tmp;
		cout<<ans<<endl;
	}
	return 0;
}
