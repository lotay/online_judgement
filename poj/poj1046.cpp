#include <stdio.h>
#define N 16

int targetColors[N][3];

int nearestColor(int rgb[]){
	int t = 10000000;
	int ti = -1;
	for(int i=0;i<N;i++){
		int diff = 0;
		for(int j=0;j<3;j++){
			diff += (rgb[j]-targetColors[i][j])*(rgb[j]-targetColors[i][j]);
		}
		if(diff<t) {
			t = diff;
			ti = i;
		}
	}
	return ti;
}

int main(){
	int i=0;
	while(i<N){
		scanf("%d %d %d",&targetColors[i][0],&targetColors[i][1],&targetColors[i][2]);
		i++;
	}
	int rgb[3];
	while(1){
		scanf("%d %d %d",&rgb[0],&rgb[1],&rgb[2]);
		if(rgb[0]<0||rgb[1]<0||rgb[2]<0) break;
		int ti = nearestColor(rgb);
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",rgb[0],rgb[1],rgb[2],targetColors[ti][0],targetColors[ti][1],targetColors[ti][2]);
	}
	return 0;
}
