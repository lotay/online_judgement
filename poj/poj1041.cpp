#include <stdio.h>
#include <stdlib.h>
#define N 50
#define M 2000

int streets[N][M];
int opaths[N][N][M];
int s,idx=0;
int top = 0;

int res[M];
int paths[M];
int streetPaths[M];
int pathCnt[N];
int used[M];

int comp(const void *a, const void *b){
	return (*(int*)b)-(*(int*)a);
}

void dfs(int x){
	res[top++] = x;
	
	int found = 1;
	int ts = -1;
	for(int i=0;i<M;i++){
		if(streets[x][i]){
			if(streets[x][i]==s){
				ts = i;
			}else{
				int y = streets[x][i];
				streets[x][i] = streets[y][i]= 0;
				found = 0;
				dfs(y);
				break;
			}
		}
	}
	if(found&&ts>0){
		int y = streets[x][ts];
		streets[x][ts] = streets[y][ts]= 0;
		dfs(y);
	}
} 

void solve(){
	int bridge = 0;
	top = 0;
	res[top++] = s;
	idx = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(opaths[i][j][0]>0){
				qsort(&opaths[i][j][1],opaths[i][j][0],sizeof(int),comp);
			}
			
		}
	}
	while(top>0){
		bridge = 1;
		for(int i=0;i<M;i++){
			if(streets[res[top-1]][i]>0){
				bridge = 0;
				break;
			}
		}
		if(bridge){
			res[--top];
			paths[idx++] = res[top];
		}else{
			dfs(res[--top]);
		}
	}
	
	for(int i=idx-1;i>0;i--){
		int x = paths[i];
		int y = paths[i-1];
		while(used[opaths[x][y][opaths[x][y][0]]]){
			--opaths[x][y][0];
		}
		used[opaths[x][y][opaths[x][y][0]]] = 1;
		streetPaths[idx-i-1] = opaths[x][y][opaths[x][y][0]--];
	} 
	
}

void store(int x,int y,int z){
	streets[x][z] = y;
	streets[y][z] = x;
	pathCnt[x] ++;
	pathCnt[y] ++;
	opaths[x][y][++opaths[x][y][0]] = z;
	opaths[y][x][++opaths[y][x][0]] = z;
}

int main(){
	int x,y,z;
	while(1){
		for(int i=0;i<N;i++){
			pathCnt[i]=0;
			for(int j=0;j<M;j++){
				streets[i][j] = 0;
				used[j] = 0;
				if(j<N)	opaths[i][j][0] = 0;
			}
		}
		scanf("%d %d",&x,&y);
		s = x;
		if(s>y)	s = y;
		if(!x&&!y){
			break;
		}
		scanf("%d",&z);
		store(x,y,z);
		while(1){
			scanf("%d %d",&x,&y);
			if(!x&&!y){
				break;
			}
			scanf("%d",&z);
			store(x,y,z);
		}
		int solvable = 1;
		for(int i=0;i<N;i++){
			if(pathCnt[i]%2){
				solvable = 0;
				break;
			}
		}
		if(solvable){
			solve();
			for(int i=0;i<idx-1;i++){
				printf("%d ",streetPaths[i]);
			}
			printf("\n");
		}else{
			printf("Round trip does not exist.\n");
		}
	}
	return 0;
}
