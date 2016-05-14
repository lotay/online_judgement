#include <stdio.h>
#include <string.h>

char dictionary[10000][20];
int results[10000];
char word[20];
int minDist = 100000000;
int n = 0;
int m = 0;
void solve( ){
	m = 0;
	minDist = 100000000;
	int len = strlen(word);//word.length();
	for(int i=0;i<n;i++){
		char *d = dictionary[i];
		int lend = strlen(d);//d.length();
		int diff = 0;
		if(lend==len){
			for(int j=0;j<len&&diff<2;j++){
				diff += d[j]!=word[j];
			}
			if(diff==0){
				minDist = 0;
				break;
			}else if(diff==1){
				results[m++] = i;
			}
		}else if(lend==len+1){
			int j1=0,j2=0;
			for(;j1<lend&&diff<2;j1++){
				if(d[j1]==word[j2]) j2 ++;
				else{
					diff++;
				}
			}
			diff += len-j2;
			if(diff==1){
				results[m++] = i;
			}
		}else if(lend+1==len){
			int j1=0,j2=0;
			for(;j1<len&&diff<2;j1++){
				if(word[j1]==d[j2]) j2 ++;
				else{
					diff++;
				}
			}
			diff += lend-j2;
			if(diff==1){
				results[m++] = i;
			}
		}
	}
}

int main(){
	scanf("%s",word);
	while(word[0]!='#'){
		strcpy(dictionary[n++] , word);
		scanf("%s",word);
	}
	scanf("%s",word);
	while(word[0]!='#'){
		solve();
		if(minDist==0){
			printf("%s is correct\n",word);
		}else{
			printf("%s:",word);
			for(int i = 0;i<m;i++ ) printf(" %s",dictionary[results[i]]);
			printf("\n");
		}
		scanf("%s",word);
	}
	return 0;
}
