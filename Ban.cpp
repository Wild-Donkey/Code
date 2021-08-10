#include <bits/stdc++.h>
using namespace std;
unsigned INF;
void Jinzhi (unsigned x) {
  if(x == INF) {printf("orz\n"); return;}
  printf((x & 1) ? "½ûÖ¹Äã" : "½ûÖ¹ÎÒ");
  return Jinzhi(x + 1);
}
int main(){
    scanf("%u", &INF);
    Jinzhi(0);
    system("pause");
    return 0;
}

