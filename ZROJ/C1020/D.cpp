#include <bits/stdc++.h>
unsigned m,n,Go[2000005],Hd(1000000),a[1000005];signed main(){scanf("%u%u",&n,&m);for(unsigned i(1),j(0);i<=n;++i){scanf("%u",a+i);if(a[i]){Go[Hd-1]=Go[Hd]+i-j-1,--Hd,j=i;for(unsigned k(Hd);k<Hd+m&&Go[k+1]+1<Go[k];++k)Go[k+1]=Go[k]-1;a[i]=0,a[i-Go[Hd]+Go[Hd+m]]=1;}}for(unsigned i(1);i<=n;++i)printf("%u ",a[i]);}
