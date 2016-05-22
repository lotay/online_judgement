#include <stdio.h>
#define N 105

int values[N];
int max(int a,int b){
	if(a>b)	return a;
	return b;
}
int main(){
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<N;i++)	values[i] = 0;
	for(int i=1;i<=n;i++){
		int nv = 0;
		for(int j=1;j<=i;j++){
			scanf("%d",&v);
			int t = max(nv,values[j])+v;
			nv = values[j];
			values[j] = t;
		}
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		if(values[i]>res){
			res = values[i];
		}
	}
	printf("%d\n",res);
}

