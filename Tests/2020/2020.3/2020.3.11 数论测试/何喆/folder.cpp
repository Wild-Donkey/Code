#include<iostream>
using namespace std;
typedef long long ll;
ll a,b,c;
template<typename T>
inline void read(T& x)
{
	x=0;bool flag=true;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') flag=0;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	if (!flag) x=~(x-1);
}
template<typename T>
inline void write(T x)
{
	if (x<0) {x=~(x-1);putchar('-');}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	read(a),read(b),read(c);
	ll now=a%b,p=2,cc=now;
	bool kk=false;
	do
	{
		cc+=now;
		cc%=b;
		if (cc==c) {kk=true;break;}
		++p;
	}while (now!=cc);
	if (kk) puts("YE5");
	else {puts("N0");putchar('0');return 0;}
	write(p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
