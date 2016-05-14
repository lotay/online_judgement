#include <stdio.h>

int nums[100][100];
int sums[101][100];
int main(){
	int n;
	scanf("%d",&n);
	int max = -100000000,v;
	for(int i=0;i<n;i++){
		sums[i][0] = 0;
		for(int j=0;j<n;j++){
			scanf("%d",&v);
			nums[i][j] = v;
		}
	}
	
	int ans = -100000000;
	for(int i=1;i<=n;i++){
		for( int j=0;j<n;j++){
			sums[i][j] = sums[i-1][j]+nums[i-1][j];
		}
		for(int i2=0;i2<i;i2++){
			int sum = 0;
			for(int j=0;j<n;j++){
				sum += sums[i][j]-sums[i2][j];
				if(sum>ans) ans = sum;
				if(sum<0) sum = 0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
