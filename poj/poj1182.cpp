#include <stdio.h>
#define N 50005

int n;
int parents[N];
int deltas[N];
void init(){
	for(int i=1;i<=n;i++){
		parents[i] = i;
		deltas[i] = 0;
	}
}

int find(int x){
	if(x==parents[x]){
		return x;
	}
	int px = find(parents[x]);
	deltas[x] = (deltas[x]+deltas[parents[x]])%3;
	parents[x] = px;
	return px;
}

int unio(int x,int y ,int t){
	if(x>n||y>n)	return 1;
	if(x==y&&t==1)	return 1;
	int px = find(x);
	int py = find(y);
	if(px==py){
		return ((deltas[y]-deltas[x]+3)%3)!=t;
	}
	parents[py] = px;
	deltas[py] = (deltas[x]-deltas[y]+t+3)%3;
	return 0;
}

int main(){
	int k;
	scanf("%d %d",&n,&k);
	init();
	int d,x,y;
	int fates = 0;
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&d,&x,&y);
		if(unio(x,y,d-1))	fates++;
	}
	printf("%d\n",fates);
	
	return 0;
}
