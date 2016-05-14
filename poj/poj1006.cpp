#include <stdio.h>

int test(int date,int p,int e){
	return ((date-p)%23==0)&&((date-e)%28==0);
}

int main(int argv,char **argc){
	int p,e,i,d;
	int idx = 1;
	while(scanf("%d %d %d %d",&p,&e,&i,&d)){
		if(p<0&&e<0&&i<0&&d<0){
			break;
		}
		p %=23;
		e %= 28;
		i %= 33;
		int ans = i;
		while(!test(ans,p,e)){
			ans += 33;
		}
		ans = (ans-d+21252)%21252;
		if(ans==0) ans = 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",idx,ans); 
		idx++;
	}
}
