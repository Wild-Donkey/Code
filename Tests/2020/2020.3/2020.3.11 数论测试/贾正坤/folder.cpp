#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, g; 
int x2, y2;
int gcd(int a,int b){
	return b==0? a: gcd(b,a%b);
}
void exgcd(int aa,int bb,int &xx,int &yy){//exgcd±ê×¼²Ù×÷ 
	if(bb==0){
		xx=1;
		yy=0;
		return;
	}
	int x1,y1;
	exgcd(bb,aa%bb,x1,y1);
	xx=y1;
	yy=x1-(aa/bb)*y1;
}
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	cin>>a>>b>>c;
	g=gcd(a,-b);
	b=-b;
	if(c%g){
		cout << "N0" << endl << 0 << endl;
		return 0;
	}
	cout << "YE5" << endl;
//	cout << a << " " << b << " " << g << " " << c << endl;
	exgcd(a,b,x2,y2);
//	cout << x2 << " " << y2 << endl;
	x2=x2*(c/g);
	if(b>0){
		while(x2<0)	x2+=b;
	}
	if(b<0){
		while(x2<0)	x2-=b;
	}
	cout << x2 << endl;
	return 0;
}

