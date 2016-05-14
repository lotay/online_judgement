#include <stdio.h>
#define N 30 

int fs[N];
int ds[N];
int ts[N];
int spendTimes[N];
int fishes[N];
int times[N];

int maxFishes = 0;

void solve(int n,int h){
	maxFishes = -1;
	for(int t = 1;t<=n;t++){
		int leftTime = h;
		for(int j = 0;j<t;j++){
			fishes[j] = fs[j];
			leftTime -= ts[j];
			times[j] = 0;
		}
		int maxFs = 0;
		while(leftTime>0){
			int idx = 0;
			for(int i=1;i<t;i++){
				if(fishes[i]>fishes[idx]){
					idx = i;
				}
			}
			if(fishes[idx]<=0){
				times[idx] += leftTime;
				break;
			}
			maxFs += fishes[idx];
			fishes[idx] -= ds[idx];
			if(fishes[idx]<0) fishes[idx] = 0;
			times[idx]++;
			leftTime--;
		}
		if(maxFs>maxFishes){
			maxFishes = maxFs;
			for(int i=0;i<n;i++){
				spendTimes[i] = times[i];
			}
		}
	}
}

int main(){
	int i,h,n;
	scanf("%d",&n);
	while(n){
		scanf("%d",&h);
		h *=12;
		i=0;
		while(i<n){
			scanf("%d",fs+i);
			times[i] = 0;
			i++;
		}
		i=0;
		while(i<n){
			scanf("%d",ds+i);
			spendTimes[i] = 0;
			i++;
		}
		i=1;
		ts[0] = 0;
		while(i<n){
			scanf("%d",ts+i);
			i++;
		}
		
		solve(n,h);
		for(int i=0;i<n;i++) {
			printf("%d",spendTimes[i]*5);
			if(i<n-1) printf(", ");
		}
		printf("\nNumber of fish expected: %d\n\n",maxFishes);
		
		scanf("%d",&n);
	}
	return 0;
}
