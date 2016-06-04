#include <stdio.h>
#define N 302
#define M 32

int dp[N][N][M];
int s1[N][N];

int v,p;
int xs[N];
int INFINITE = 1000000000;

int abs(int a){
	if(a<0)	return -a;
	return a;
}

void solve(){
	for(int i=1;i<=v;i++){
		s1[i][i] = 0;
		for(int j=i-1;j>=1;j--){
			s1[i][j] = s1[i][j+1]+xs[i]-xs[j];
//			printf("%d\t",s1[i][j]); 
		}
//		printf("%d\t",0);
		for(int j=i+1;j<=v;j++){
			s1[i][j] = s1[i][j-1]+xs[j]-xs[i]; 
//			printf("%d\t",s1[i][j]);
		}
//		printf("\n");
	}
//	printf("\n");
	int i1 = 1;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=i;j++){
			dp[i][j][1] = s1[j][1]+s1[j][i];
//			printf("%d ",dp[i][j][1]);
		}
//		printf("\n");
	}
//	printf("%d\n\n",dp[2][2][1]);
	for(int i=2;i<=v;i++){
		for(int j=2;j<=i;j++){
			for(int k=2;k<=j&&k<=p;k++){
				int min = INFINITE;
				if(i>j)	min = dp[i-1][j][k] + xs[i]-xs[j];
				int j2 = j;
//				printf("bbbbbb.i:%d,j:%d,k:%d min:%d\n",i,j,k,min);
				for(int j1 = j-1;j1>=k-1&&j1>0;j1--){
					while(j2>j1&&s1[j1][j2-1]+s1[j][j2]>s1[j1][j2-2]+s1[j2-1][j])	j2--;
					if(min>dp[i][j1][k-1]+s1[j1][j2-1]+s1[j][j2]-s1[j1][i]+s1[j][i])
						min = dp[i][j1][k-1]+s1[j1][j2-1]+s1[j][j2]-s1[j1][i]+s1[j][i];
				}
				
				dp[i][j][k] = min;
//				printf("aaaaaa.i:%d,j:%d,k:%d min:%d  %d\n",i,j,k,min,j2);
			}
		}
	}
	int min = dp[v][p][p];
	for(int j = p;j<=v;j++){
		if(min>dp[v][j][p])	min = dp[v][j][p];
	}
	return min;
}

int main(){
	scanf("%d %d",&v,&p);
	for(int i=1;i<=v;i++){
		scanf("%d",&xs[i]);
	}
	printf("%d\n",solve());

	return 0;
}

