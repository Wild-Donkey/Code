#include <cstdio>
#include <cmath>
#define IAKIOI 0
using namespace std;
double a,b;
void fre()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
}
int main()
{
	fre();
	scanf("%lf%lf",&a,&b);
	printf("%0.0lf",pow(a,b));
	return IAKIOI;
}
