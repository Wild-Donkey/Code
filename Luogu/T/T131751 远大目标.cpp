#include<iostream>
#include<cstring>
using namespace std;
string a;
bool flg;
int A[10100];
void Read() {
	cin>>a;
	A[0]=a.size();
	for(int i=0; i<A[0]; i++) {
		if(a[i]=='-'){
			flg=1;
			return;
		}
		A[A[0]-i]=a[i]-48;
	}
	A[0]=A[0]+1;
	return;
}
void Plus(int x[]) {
	int faq[10005];
	for(int i=0;i<=x[0];i++){
		faq[i]=x[i];
	}
	for(int i=1; i<=x[0]; i++) { //枚举每一位
		x[i]+=faq[i];
		//cout<<x[i]<<endl;
		while(x[i]>=10) {
			//cout<<"faq"<<endl;
			x[i+1]++;
			x[i]-=10;
		}
	}
	while(x[x[0]]==0&&x[0]>1)
		x[0]--;
	return;
}
int main(){
	Read();
	if(flg){
		cout<<0<<endl;
		return 0;
	}
	if(A[0]==2){
		if(A[1]==0){
			cout<<0<<endl;
			return 0;
		}
	}
	Plus(A);
	A[1]--;
	int i=1;
	while((A[i]<0)&&(i<=A[0])){
		A[i]+=10;
		A[++i]--;
	}
	while(A[A[0]]==0&&A[0]>1){
		A[0]--;
	}
	for(int i=A[0];i>=1;i--){
		cout<<A[i];
	}
	cout<<endl;
	return 0;
}
