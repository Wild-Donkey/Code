#include<iostream>
#include<cmath>
using namespace std;
int a,b[20],mi[20],r,mii=0;
bool flg=0;
void up(){
	int upi=0;
	while(upi<mii){
		if(b[upi]>(-r)){
		b[upi+1]+=b[upi]/(-r);
		b[upi]%=(-r);
		upi++;
	}
	}
	return;
}
int main() {
	mi[0]=1;
	cin>>a>>r;
	while((mi[mii]!=0)&&(abs(mi[mii])<=0x3ffffff)) {
		mii++;
		mi[mii]=mi[mii-1]*r;
	}
	mii--;
	for(int i=mii; i>=0; i--) {
		if(mi[i]>0) {
			if(a<0){
				continue;
			}
			b[i]=a/mi[i];
			a%=mi[i];
			cout<<b[i]<<endl;
		} else {
			if(a>0){
				continue;
			}
			b[i]=a/abs(mi[i]);
			a%=mi[i];
			if(a<0){
				a-=mi[i];
				b[i]++;
			}
			cout<<b[i]<<endl;
		}
	}
	up();
	for(int i=mii;i>=0;i--){
		if(!flg){
			if(!b[i]){
				continue;
			}
			else{
				flg=1;
			}
		}
	if(b[i]<10){
		cout<<b[i];
	}
	else{
		cout<<char(b[i]-10+'A');
	}
	}
	return 0;
}
