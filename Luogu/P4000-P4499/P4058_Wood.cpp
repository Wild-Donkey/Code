#include <cstdio>
#include <iostream>

using std::max;

const int N=2e5+11;

typedef unsigned long long ll;

unsigned n;
unsigned long long s, L, h[N], a[N];

inline char check(ll x) {
	ll ret(s);
	for(unsigned i(1);i<=n;i++) {
		if(L <= h[i]) {
//	    printf("%llu %llu\n", L, x);
	    if(ret <= h[i]) return 1;
      if((ret - h[i]) / a[i] < x) return 1;
  		ret -= h[i] + x * a[i];
    } else {
//	    printf("%llu %llu\n", a[i], L - h[i]);
		  if((L - h[i]) / a[i] < x) {
  	    if(ret <= h[i]) return 1;
        if((ret - h[i]) / a[i] < x) return 1;
        ret -= h[i] + x * a[i];
      }
    }
    if(!ret) return 1;
    if(ret > 0x3f3f3f3f3f3f3f3f) return 1;
	}
	return 0;
}

ll l,r,mid;

int main() {
	scanf("%u%llu%llu",&n,&s,&L);
	for(int i=1;i<=n;i++) scanf("%llu",&h[i]);
	for(int i=1;i<=n;i++) scanf("%llu",&a[i]);
	// for(int i=1;i<=n;i++) r=max(r,(L-h[i])/a[i]+1);
	r=1e18;
	while(l ^ r) {
		mid=(l + r)>>1;
		// printf("%lld %lld %lld %d\n",l,mid,r,check(mid));
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%llu\n",l);
	return 0;
}

