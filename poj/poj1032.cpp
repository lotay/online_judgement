#include <stdio.h>
#include <math.h>

long long dp[1001];
int sizes[1001][1001];

int comp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n = 100;
	scanf("%d",&n);
	int k = (int)(sqrt(n*2+2.25)-0.5);
	int a = (k*k+k)/2-1;
	int p = n-a;
	if(p==0){
		for(int i=2;i<=k;i++){
			printf("%d ",i);
		}
	}
	else if(p==k){
		for(int i=3;i<=k;i++){
			printf("%d ",i);
		}
		printf("%d ",k+2);
	}else{
		for(int i=2;i<=k+1;i++){
			if(i==k+1-p) continue;
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
