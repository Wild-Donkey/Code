#include<iostream>
#include<cstring>
using namespace std;
int ctn=1,f[100005],a[100005],lst[100005],ans;
bool flg=1;
bool lookup(){
	for(int i=1;i<=ctn;i++){
		if(a[i]>=0){
			return 1;
		}
	}
	return 0;
}
int main(){
	memset(a,0x3f,sizeof(a));
	while(cin>>a[ctn]){
		ctn++;
	}
	f[1]=1;
	for(int i=2;i<=ctn;i++){
		for(int j=1;j<i;j++){
			if(a[i]<=a[j]){
				if(f[j]+1>f[i]){
					f[i]=f[j]+1;
					lst[i]=j;
				}
			}
		}
	}
	cout<<f[ctn]<<endl;
	int ci=ctn;
	while(1){
		a[ci]=-1;
		ci=lst[ci];
		if(lst[ci]==0){
			a[ci]=-1;
			break;
		} 
	}
	ans=1;
	while(lookup()){
		memset(f,0,sizeof(f));
		ans++;
		for(int i=2;i<=ctn;i++){
			if(a[i]<0){
				continue;
			}
			for(int j=1;j<i;j++){
				if(a[j]<0){
					continue;
				}
				if(a[i]<=a[j]){
					if(f[j]+1>f[i]){
						f[i]=f[j]+1;
						lst[i]=j;
						lst[ctn]=i;
					}
				}
			}
		}
		int fi=ctn;
		while(1){
			a[fi]=-1;
			fi=lst[fi];
			if(lst[fi]==0){
				a[fi]=-1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0; 
}
