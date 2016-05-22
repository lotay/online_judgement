#include <stdio.h>
#define N 1900
int dates[102][13][32];
int numOfDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int isLeapYear(int y){
	y += 1900;
	return (y%4==0&&y%100!=0)||(y%400==0);
}

int ny,nm,nd;
int nextDay(int y,int m,int d){
	if(y>101||m>12||(m!=2&&d>numOfDays[m]))	return 0;
	if(m==2&&d>numOfDays[m]+isLeapYear(y))	return 0;
	if(y==101&&m==11&&d>=4)	return 0;
	ny = y;
	nm = m;
	nd = d;
	int numOfDay = numOfDays[m];
	if(m==2){
		numOfDay += isLeapYear(y);
	}
	if(d<numOfDay){
		nd++;
	}else if(d==numOfDay){
		nm ++;
		nd = 1;
	}
	if(nm>12){
		nm = 1;
		ny ++;
	}
	return 1;
}

int nextMonth(int y,int m,int d){
	if(y>101)	return 0;
	if(y==101&&m>=11)	return 0;
	if(y==101&&m==10&&d>=4)	return 0;
	ny = y;
	nm = m;
	nd = d;
	if(m==12){
		ny++;
		nm = 1;
		return 0;
	}
	int numOfDay = numOfDays[m+1];
	if(m==1){
		numOfDay += isLeapYear(y);
	}
	if(d>numOfDay)	return 0;
	nm++;
	return 1;
}

int outOfRange(int y,int m,int d){
	return (y>101||y==101&&m>11||y==101&&m==11&&d>=4);
}

void init(){
	dates[101][11][4] = 0;
	for(int i=101;i>=0;i--){
		for(int j=12;j>0;j--){
			int k = numOfDays[j];
			if(j==2)	k += isLeapYear(i);
			for(;k>=1;k--){
				if(outOfRange(i,j,k))	continue;
				int flag = 0;
				
				if(nextDay(i,j,k)){
					flag = dates[ny][nm][nd];
				}
				if(i==101&&j==10){
//					printf("ttt:%d %d %d",ny,nm,nd);
				}
				if(flag&&nextMonth(i,j,k)){
					flag = dates[ny][nm][nd];
				}
//				if(i==101&&j==10){
//					printf("ttt:%d %d %d\n",ny,nm,nd);
//				}
				dates[i][j][k] = !flag;
//				printf("%d ",flag);
			}
		}
//		printf("\n");
	}
	
//	for(int i=0;i<=101;i++){
//		for(int j=1;j<=12;j++){
//			printf("%d,%d:\t",i,j);
//			for(int k=1;k<=31;k++){
//				printf("%d ",dates[i][j][k]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
}

int main(){
	init();
	
	int t;
	int y,m,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&y,&m,&d);
		printf("%s\n",dates[y-1900][m][d]?"YES":"NO");
	}
	return 0;
}
