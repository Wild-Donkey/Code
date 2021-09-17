#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int num_card=4,max_health=4;
int n,m;
struct player{
	bool alive,brother;
	int kind,card[10005],card_next_l[10005],card_next_r[10005],health;
	int card_l,card_r;
	int next_l,next_r;
}players[15];
int Card(char x){
	if(x=='P'){//peach:1
		return 1; 
	}
	if(x=='K'){//kill:2
		return 2;
	}
	if(x=='D'){//flash:3
		return 3;
	}
	if(x=='F'){//fight:4 
		return 4
	}
	if(x=='N'){//south:5
		return 5;
	} 
	if(x=='W'){//ten_thousand:6
		return 6;
	}
	if(x=='J'){//protect:7
		return 7;
	}
	if(x=='Z'){//brother:8
		return 8;
	}
	return 0;
}
int Kind(char x){
	if(x=='M'){//main:1
		return 1;
	}
	if(x=='Z'){//faithful:2 
		return 2;
	}
	if(x=='F'){//enemy:3 
		return 3;
	}
	return 0;
}
void In(){
	char Tin;
	scanf("%d%d",n,m);
	for(int i=1;i<=n;i++){
		cin>>Tin;
		players[i].kind=Kind(Tin);
		cin>>Tin;
		for(int j=1;j<=num_card;j++){
			cin>>Tin;
			players[i].card[j]=Card(Tin);
		}
		players[i].card_l=1;
		players[i].card_r=num_card;
		players[i].health=max_health;
		players[i].next_l=(i+m-2)%m+1;
		players[i].next_r=(i+1)%m;
		players[i].alive=1;
	}
	for(int i=1;i<=m;i++){
		cin>>Tin;
		players[0].card[i]=Card(Tin);
	}
	players[0].card_l=1;
	players[0].card_r=m;
	return;
}
void Getcard(int x){
	players[0]
}
void Use(int x,int y){
	return;
}
void Die(int x){
	players[x].alive=0;
	players[players[x].next_l].next_r=players[x].next_r;
	players[players[x].next_r].next_l=players[x].next_l;
	return;
}
void Print(bool x){
	if(x){
		printf("MP\n"); 
	}
	else{
		printf("FP\n"); 
	}
	for(int i=1;i<=n;i++){
		if(players[i].alive){
			for(int j=players[i].card_l;j<=players[i].card_r;j++){
				printf("%c ",Print_card(players[i].card[j]));
			}
		}
	}
	return;
}
bool Play(){
	int player_now=1;
	while(1){
		Get_card(player_now);
		player_now=players[player_now].next_r;
	}
	return 1;
}
int main(){
	In();
	Print(Play());
	return 0;
}
