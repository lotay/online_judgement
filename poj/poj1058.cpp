#include <stdio.h>
#define N 20

int seated[N][N];
char tables[N][5];

void setSeat(int t){
	for(int i=0;i<3;i++){
		int v1 = tables[t][i]-'A';
		for(int j=i+1;j<4;j++){
			int v2 = tables[t][j]-'A';
			seated[v2][v1] = seated[v1][v2] = 1;
		}
	}
}
int used[N];

int solve(int nn,int ii){
	nn += ii/4;
	ii %= 4;
	if(nn>=20){
		return 1;
	}
	if(nn==16&&ii==0){
		for(int i=0;i<N;i++){
			used[i] = 0;
		}
	}
	for(int j = 0;j<16;j++){
		if(used[j])	continue;
		int flag = 1;
		for(int i=0;i<ii;i++){
			if(seated[j][tables[nn][i]-'A']){
				flag = 0;
				break;
			}
		}
		if(flag){
			tables[nn][ii] = j+'A';
			for(int i=0;i<ii;i++){
				seated[j][tables[nn][i]-'A'] = seated[tables[nn][i]-'A'][j] = 1;
			}
			used[j] = 1;
			if(solve(nn,ii+1)){
				return 1;
			}
			tables[nn][ii] = 0;
			for(int i=0;i<ii;i++){
				seated[j][tables[nn][i]-'A'] = seated[tables[nn][i]-'A'][j] = 0;
			}	
			used[j] = 0;
		}
	}
	return 0;
}

int main(){
	while(scanf("%s",tables[0])!=EOF){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				seated[i][j] = 0;
			}
			seated[i][i] = 1;
			used[i] = 0;
		}
		//
		setSeat(0);
		for(int i=1;i<12;i++){
			scanf("%s",tables[i]);
			setSeat(i);
		}
		if(solve(12,0)){
			for(int i=0;i<5;i++){
				for(int j=0;j<4;j++){
					if(j)	printf(" ");
					for(int k=0;k<4;k++)	printf("%c",tables[i*4+j][k]);
				}
				printf("\n");
			}
		}else{
			printf("It is not possible to complete this schedule.\n\n");
		}
	}
	return 0;
}
