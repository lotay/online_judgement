#include <stdio.h>
#define N 302
#define M 32

int v,p;
int xs[N];
int INFINITE = 1000000000;

int s[N][N];
int dp[N][M];

int solve(){
	for(int i=1;i<=v;i++){
		s[i][i] = 0;
		for(int j = i+1;j<=v;j++){
			s[i][j] = s[i][j-1] + xs[j]-xs[(i+j)/2];
		}
	}
	
	for(int i=1;i<=v;i++){
		dp[i][i] = 0;
		dp[i][1] = s[1][i];
	}
	for(int j=2;j<=p;j++){
		for(int i=j+1;i<=v;i++){
			dp[i][j] = INFINITE;
			for(int k = i;k>=j;k--){
				if(dp[i][j]>dp[k-1][j-1]+s[k][i])	dp[i][j] = dp[k-1][j-1]+ s[k][i];
			}
		}
	}
	return dp[v][p];
}

int main(){
	scanf("%d %d",&v,&p);
	for(int i=1;i<=v;i++){
		scanf("%d",&xs[i]);
	}
	printf("%d\n",solve());

	return 0;
}

