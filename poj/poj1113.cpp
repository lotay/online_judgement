#include <stdio.h>
#include <math.h>
#define M 1005
#define PI 3.1415926

int xs[M];
int ys[M];
int n,l;


int product(int i,int j, int k){
	int dx1 = xs[j] - xs[i];
	int dy1 = ys[j] - ys[i];
	int dx2 = xs[k] - xs[i];
	int dy2 = ys[k] - ys[i];
	return dx1*dy2-dx2*dy1;
}

double distance(int i,int j){
	int dx = xs[i]-xs[j];
	int dy = ys[i]-ys[j];
	return sqrt(dx*dx+dy*dy);
}

void swap(int s,int e){
	for(int i=s,j=e;i<j;i++,j--){
		int t = xs[i];
		xs[i] = xs[j];
		xs[j] = t;
		t = ys[i];
		ys[i] = ys[j];
		ys[j] = t;
	}
}

int main(){
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++){
		scanf("%d %d",&xs[i],&ys[i]);
	}
	int ti = 0;
	
	for(int i=1;i<n;i++){
		if(xs[i]<xs[ti]||(xs[i]==xs[ti]&&ys[i]>ys[ti]))	ti = i;
	}
	swap(0,ti-1);
	swap(ti,n-1);
	swap(0,n-1);
	xs[n] = xs[0];
	ys[n] = ys[0];

	double s = 0;
	int points = 0;
	int f = 0;
	for(int i=0;i<n;){
		int j = i+1;
		for(int k = j+1;k<n+f;k++){
			int p = product(i,j,k);
//			printf("p:%d %d %d %d\n",i,j,k,p);
			if(p>=0){
				j = k;
			}
		}
		s += distance(i,j);
//		printf("%d %d %f\n",i,j,s);
		points++;
		i = j;
		f = 1;
	}
	s += 2*PI*l;
	printf("%d\n",(int)(s+0.5));
	return 0;
}

