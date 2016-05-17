#include <stdio.h>
#include <stdlib.h>
#define N 5005

using namespace std;

bool plants[N][N];
typedef struct{
	int x,y;
}Point;

int comp(const void *a, const void *b){
	Point *a1 = ((Point*)a);
	Point *b1 = ((Point*)b);
	if(a1->x!=b1->x)	return a1->x-b1->x;
	return a1->y-b1->y;
}

int main(){
	Point points[N];
	int n;
	int r,c;
	scanf("%d %d",&r,&c);
	scanf("%d",&n);
	for(int i=1;i<=c;i++){
		for(int j=1;j<=r;j++){
			plants[i][j] = false;
		}
	}
	int x,y;
	for(int i=0;i<n;i++){
		scanf("%d %d",&y,&x);
		points[i].y = y;
		points[i].x = x;
		plants[y][x] = true;
	}
	qsort(points,n,sizeof(Point),comp);
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x1 = points[i].x;
			int y1 = points[i].y;
			int x2 = points[j].x;
			int y2 = points[j].y;
			
			int dx = x2-x1;
			int dy = y2-y1;
			if(x1-dx>0&&y1-dy>0&&y1-dy<=r) 	continue;
			if(dx&&(x1+dx*res>c||x1+dx*res<1))	continue;
			if(dy&&(y1+dy*res>r||y1+dy*res<1))	continue;
			int cnt = 2;
			x = x2+dx,y=y2+dy;
			int flag = 1;
			while(x>0&&x<=c&&y>0&&y<=r){
				cnt++;
				if(!plants[y][x]){
					flag = 0;
					break;
				}
				x += dx;
				y += dy;
			}
//			printf("%d %d:%d %d=%d\n",x1,y1,x2,y2,cnt);
			if(flag&&cnt>2&&cnt>res){
				res = cnt;
			}
		}
	}
	printf("%d\n",res>2?res:0);//<<res<<endl;
}
