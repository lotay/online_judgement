#include <stdio.h>
#define N 1030

int table[N][N];
int n;
int lowbit(int x){
	return x&(-x);
}

void init(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			table[i][j] = 0;
		}
	}
}

void update(int x,int y,int a){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			table[i][j] += a;
		}
	}
}

int sum(int x,int y){
	int s = 0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			s += table[i][j];
		}
	}
	return s;
}
int main(){
	int ins;
	while(scanf("%d",&ins)&&ins<3){
		if(ins==0){
			scanf("%d",&n);
			init();
		}else if(ins==1){
			int x,y,a;
			scanf("%d %d %d",&x,&y,&a);
			x++;
			y++;
			update(x,y,a);
		}else{
			int x,y,l,r;
			scanf("%d %d %d %d",&x,&y,&l,&r);
			x++;
			y++;
			l++;
			r++;
			printf("%d\n",sum(l,r)-sum(l,y-1)-sum(x-1,r)+sum(x-1,y-1));
		}
	}
	return 0;
}
