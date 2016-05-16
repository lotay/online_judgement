#include <stdio.h>
#define N 25

int years[N][3];
int n;

int test(int y){
	int flag = 1;
	for(int i=1;i<n;i++){
		if(y<years[i][0]||years[i][1]+(y-years[i][1])%(years[i][2]-years[i][1])!=years[i][0]){
			flag = 0;
			break;
		}
	}
	return flag;
}

int solve(){
	int y = years[0][0];
	while(y<10000){
		if(test(y)){
			break;
		}
		y += years[0][2]-years[0][1];
	}
	return y;
} 

int main(){
	int t = 0;
	while(scanf("%d",&n)&&n){
		int maxI=0;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&years[i][0],&years[i][1],&years[i][2]);
			if(years[i][2]-years[i][1]>years[maxI][2]-years[maxI][1]){
				maxI = i;
			}
		}
		if(maxI!=0){
			int y1 = years[maxI][0],y2 = years[maxI][1],y3 = years[maxI][2];
			years[maxI][0] = years[0][0];
			years[maxI][1] = years[0][1];
			years[maxI][2] = years[0][2];
			years[0][0] = y1;
			years[0][1] = y2;
			years[0][2] = y3;
		}
		int y = solve();
		printf("Case #%d:\n",++t);
		if(y>=10000){
			printf("Unknown bugs detected.\n\n");
		}else{
			printf("The actual year is %d.\n\n",y);
		}
	}
	return 0;
}
