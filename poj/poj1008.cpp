#include <stdio.h>
#include <string.h>

char HaabMonths[][10] = {"pop","no","zip","zotz","tzec","xul","yoxkin",
"mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char TzolkinDate[][10] = {"imix","ik","akbal","kan","chicchan","cimi",
"manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int transfer1(int d, char *m, int y){
	int mi = 0;
	for(;mi<19;mi++){
		if(strcmp(HaabMonths[mi],m)==0){
			break;
		}
	}
	return d+mi*20+y*365;
}

void transfer2(int date){
	int y = date / 260;
	int l = date % 260;
	printf("%d %s %d\n",(l%13)+1,TzolkinDate[l%20],y);
}

int main(int argv,char **argc){
	int d,y;
	char months[10];
	int t =0;
	scanf("%d",&t);
	printf("%d\n",t);
	while(t-->0){
		scanf("%d. %s %d",&d,months,&y);
		int date = transfer1(d,months,y);
		transfer2(date);
//		printf("%d %s %d\n",d,months,y);
	}
	return 0;
}
