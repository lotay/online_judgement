#include <stdio.h>
int main(){
	int t;
	int y,m,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&y,&m,&d);
		printf("%s\n",((m%2==d%2)||((m==9||m==11)&&d==30))?"YES":"NO");
	}
	return 0;
}
