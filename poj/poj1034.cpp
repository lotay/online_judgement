#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 105

int m,n;
int routes[N][2];
int places[N][2];

int matches[N][N];
int links[N];
int ans[N];
int visited[N];

double distance1(int i){
	double dy = (routes[i][1]-routes[i+1][1]);
	double dx = (routes[i][0]-routes[i+1][0]);
	return sqrt((dx*dx+dy*dy));
}
double distance2(int i,int j){
	double dx1 = routes[i][0]-places[j][0];
	double dx2 = routes[i+1][0] - places[j][0];
	double dy1 = routes[i][1]-places[j][1];
	double dy2 = routes[i+1][1] - places[j][1];
	return sqrt(dx1*dx1+dy1*dy1)+sqrt(dx2*dx2+dy2*dy2);
}

int dfs(int x){
	for(int i=1;i<=m;i++){
		if(matches[x][i]&&!visited[i]){
			visited[i] = 1;
			if(!links[i]||dfs(links[i])){
				links[i] = x;
				ans[x] = i;
				return 1;
			}
		}
	}
	return 0;
}

void solve(){
	memset(matches,0,sizeof(matches));
//	printf("%d\n",sizeof(matches));
	memset(links,0,sizeof(links));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<n;i++){
		double distOfI = 2*distance1(i);
		for(int j = 1;j<=m;j++){
			if(distance2(i,j)<=distOfI){
				matches[i][j] = 1;
			}
		}
	}
	int s = n;
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		s+=dfs(i);
	}
	printf("%d\n",s);
	for(int i=1;i<n;i++){
		printf("%d %d ",routes[i][0],routes[i][1]);
		if(ans[i]){
			printf("%d %d ",places[ans[i]][0],places[ans[i]][1]);
		}
	}
	printf("%d %d",routes[n][0],routes[n][1]);
	printf("\n");
}

void init(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&routes[i][0],&routes[i][1]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&places[i][0],&places[i][1]);
	}
}

int main(){
	init();
	solve();
} 
