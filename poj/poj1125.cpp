#include <stdio.h>
#include <string.h>
#define N 105

int dist[N][N];
int n;
int MAX = 100000000;

void solve(){	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j])	dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int p = 0;
	int time = MAX;
	for(int i=1;i<=n;i++){
		int t = 0;
		for(int j=1;j<=n;j++){
//			printf("%d ",dist[i][j]);
			if(dist[i][j]>t)	t = dist[i][j];
		}
//		printf("\n");
		if(time>t){
			time = t;
			p = i;
		}
	}
//	printf("\n"); 
	if(p){
		printf("%d %d\n",p,time);
	}else{
		printf("disjoint\n");
	}
}

int main(){
	while(scanf("%d",&n)&&n){
//		memset(dist,MAX,sizeof(dist));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j] = MAX;
			}
		}
		for(int i=1;i<=n;i++){
			int m,k,d;
			scanf("%d",&m);
			dist[i][i] = 0;
			for(int j=1;j<=m;j++){
				scanf("%d %d",&k,&d);
				dist[i][k] = d;
			}
		}
		solve();
	}
	return 0;
}
