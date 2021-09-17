#include<iostream>
#include<algorithm>
using namespace std;
int n,SA=0;
bool Cykablyat[10005]={0},flg;
struct Game{
	int time,money;
}Gay[10005];
bool CaO(Game x,Game y){
	return x.money>y.money;
}
int main(){
	cin>>SA>>n;
	for(int i=1;i<=n;i++){
		cin>>Gay[i].time;
	}
	for(int i=1;i<=n;i++){
		cin>>Gay[i].money;
	}
	sort(Gay+1,Gay+n+1,CaO);
	for(int i=1;i<=n;i++){
		flg=0;
		for(int j=Gay[i].time;j>=1;j--){
			if(!Cykablyat[j]){
				Cykablyat[j]=1;
				flg=1;
				break;
			}
		}
		if(!flg){
			SA-=Gay[i].money;
		}
	}
	cout<<SA<<endl;
}
