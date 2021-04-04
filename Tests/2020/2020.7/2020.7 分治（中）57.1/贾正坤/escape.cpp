#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 525525
#include <vector>
using namespace std;

int dis,vp,vc;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	
	cin >> dis >> vp >> vc;
	if(vp>vc)	swap(vp,vc);
	double fenmu=1.0*vc/vp*dis-dis, fenzi=1.0*vc*vc/vp+(1.0*vc*(1.0*vc-vp))/(vc+vp)+(vc-vp)*1.0/(vc+vp)*vc-vc;
	double time=fenmu/fenzi;
//	cout<<time;
	double ans=time+(dis-time*vc)*1.0/vp;
	printf("%.2lf\n",ans);
	return 0;
}

