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
    system("Rand.exe >t3_40.in");
    tim = clock();
    system("T3std.exe <t3_40.in >t3_40.out");
    tim = clock() - tim;
    printf("Time: %lfms\n", tim);
    tim = clock();
    system("lsq.exe <t3_40.in >lsq.out");
    tim = clock() - tim;
    printf("Time: %lfms\n", tim);
    if(system("fc t3_40.out lsq.out")){
    	break;
	}
	else{
		printf("Test %d Accepted!\n", i);
	}
  }
  system("pause");
  return 0;
}
