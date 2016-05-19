#include <stdio.h>
#define N 19

int counts[N];
int sum[N];
void init(){
	counts[0] = 1 ;
	sum[0] = 0;
	for(int i=1;i<N;i++){
		counts[i] = 0;
		for(int j=0;j<=i-1;j++){
			counts[i] += counts[j]*counts[i-1-j];
		}
		sum[i] = sum[i-1]+counts[i];
//		cout<<i<<":"<<counts[i]<<": "<<sum[i]<<endl;
	}
}

void solve(int n){
	if(n==0)	return ;
	if(n==1){
		printf("X");
		return;
	}
	for(int k=N-1;k>=0;k--){
		if(n>sum[k]){
			n -= sum[k];
			int cnt =0;
			int flag = 0;
//			if(n>counts[k]/2){
//				n = counts[k]-n;
//				flag =1;
//			}
			int i=0;
			int ii = 0;
			int j=0;
			while(cnt+counts[k-i]<n){
				cnt += counts[k-i];
				ii++;
				j++;
				if(j>=counts[i]){
					j=0;
					i++;
				}
			}
			if(ii){
				printf("(");
				solve(ii);	
				printf(")");		
			}
			printf("X");
			int kk = k-i;
			if(kk){
				int rr = sum[kk-1]+n-cnt;
				printf("(");
				solve(rr);
				printf(")");
			}
//			printf("X:%d,%d,%d,%d,%d\n",i,ii,cnt,k,n-cnt);
			break;
		}
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)&&n){
		solve(n);
		printf("\n");
	}
	return 0;
}
