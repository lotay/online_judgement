#include  <stdio.h>
#define N 705
int n;
int points[N][2];

int cross_product(int i,int j,int k){
	return (points[j][0]-points[i][0])*(points[k][1]-points[i][1])-(points[j][1]-points[i][1])*(points[k][0]-points[i][0]);
}

int calculate(){
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cnt = 2;
			for(int k=j+1;k<n;k++){
				if(cross_product(i,j,k)==0){
					cnt++;
				}
			}
			if(max<cnt)	max = cnt;
		}
	}
	return max;
}

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%d %d",&points[i][0],&points[i][1]);
		}
		printf("%d\n",calculate());
	}
	return 0;
}
