#include<iostream>
#include<cstring>
using namespace std;
struct shu{
	int l,r,val;
}a[1005];
int del,n;
string s;
void in(){
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		a[i+1].val=s[i]-'0';
		a[i+1].l=i;
		a[i+1].r=i+2;
	}
	a[1].l=-1;
	a[n].r=-1;
	a[0].r=1;
	a[0].l=n;
	cin>>del;
}
int main(){
	in();
	while(del>0){
		//cout<<del<<endl;
		int j=a[0].r;
		while(a[j].r>=0){
			while((a[j].l<0)&&(a[j].val==0)){
				a[0].r=a[j].r;
				a[a[j].r].l=-1;
				j=a[j].r;
			}
			if(a[a[j].r].val<a[j].val){
				a[a[j].r].l=a[j].l;
				if(a[j].l<0){
					a[0].r=a[j].r;
				}
				else{
					a[a[j].l].r=a[j].r;
				}
				del--;
				break;
			}
			j=a[j].r;
		}
		if(a[j].r<0){
			break;
		}
	}
	/*int outj=a[0].r;
	while(a[outj].r>=0){
		cout<<a[outj].val;
		outj=a[outj].r;
	}*/
	int outi=a[0].l;
	while((a[outi].l>=0)&&(del>0)){
		//cout<<outi<<endl;
		a[a[outi].l].r=-1;
		a[0].l=a[outi].l;
		del--;
		outi=a[outi].l;
	}
	int outj=a[0].r;
	while(a[outj].r>=0){
		cout<<a[outj].val;
		outj=a[outj].r;
	}
	cout<<a[outj].val<<endl;
	return 0;
}
