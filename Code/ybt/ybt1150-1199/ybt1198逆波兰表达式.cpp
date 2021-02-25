#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
double ans;
string ch;
int at=0;
double Rd(string x) {
	int tmp=0,i=0;
	double a=0.00;
	while(x[i]>='0'&&x[i]<='9') {
		a*=10.00;
		a+=x[i]-'0';
		i++;
	}
	i++;//因为有小数点，所以跳出了 
	while(x[i]>='0'&&x[i]<='9') {
		tmp++;
		a*=10.00;
		a+=x[i]-'0';
		i++;
	} 
	for(int j=1;j<=tmp;j++) {
		a/=10.00;
	}
	return a;
} 
double f(char x){
	//cout<<x<<endl;
	double a,b;
	string c;
	cin>>c;
	if(c[0]>='0'&&c[0]<='9') {
		a=Rd(c);
	}
	else {
		a=f(c[0]);
	//	cout<<"a "<<a<<endl;
	}
	cin>>c;
	//cout<<Rd(c);
	if(c[0]>='0'&&c[0]<='9') {
		b=Rd(c);
	}
	else {
		b=f(c[0]);
	//	cout<<"b "<<b<<endl;
	}
	if(x=='+'){
	//	cout<<x<<endl;
		return a+b;
	}
	if(x=='-')
		return a-b;
	if(x=='*')
		return a*b;
	if(x=='/')
		return a/b; 
}
int main() {
	cin>>ch;
	if(ch[0]<'0'||ch[0]>'9')
		ans=f(ch[0]);
	else {
		ans=Rd(ch);
	}
	printf("%f\n",ans);
	return 0;
}
