#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
double tim;
int t;
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    system("Rand.exe >t2_10.in");
    tim = clock();
    system("T2std.exe <t2_10.in >t2_10.out");
    tim = clock() - tim;
    printf("Time: %lfms\n", tim);
    tim = clock();
    system("xds.exe <t2_10.in >xds.out");
    tim = clock() - tim;
    printf("Time: %lfms\n", tim);
    if(system("fc t2_10.out xds.out")){
    	break;
	}
	else{
		printf("Test %d Accepted!\n\n", i);
	}
  }
  system("pause");
  return 0;
}
