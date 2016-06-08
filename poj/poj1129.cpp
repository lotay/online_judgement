#include <stdio.h>
#include <string.h>
#define N 30
int boards[N][N];
int n;
int colors[N];
void reset(){
	for(int i=1;i<=n;i++){
		colors[i] = 0;
	}
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			boards[i][j] = 0;
		}
	}
}

int dfs(int nn, int color,int d){
	for(int c=1;c<=color;c++){
		int f = 1;
		colors[nn] = c;
		for(int j=1;j<=n;j++){
			if(boards[nn][j]&&colors[nn]==colors[j]){
				f = 0;
				break;
			}
		}
		if(f){
			int j=1;
			for(;j<=n;j++){
				if(!colors[j]){
					break;
				}
			}
//			cout<<d<<":"<<nn<<" "<<j<<"  "<<c<<" "<<endl;
			if(j<=n){
				if(dfs(j,color,d+1))	return 1;
			}else {
				return 1;
			}
		}
		colors[nn] = 0;
	}
	return 0;
}

int solve(){
	int c = 1;
	while(1){
		reset();
		if(dfs(1,c,1)){
			break;
		}
		c++;
//		cout<<"c:"<<c<<endl<<endl;
	}
	return c;
}

int main(){
	char line[N];
	while(scanf("%d",&n)&&n){
		init();
		for(int i=1;i<=n;i++){
			scanf("%s",line);
			for(int j=2;j<strlen(line);j++){
				boards[i][line[j]-'A'+1] = 1;
				boards[line[j]-'A'+1][i] = 1;
			}
		}
		int c = solve();
		if(c==1){
			printf("%d channel needed.\n",c);
		}else{
			printf("%d channels needed.\n",c);
		}
		
	}
	return 0;
}
