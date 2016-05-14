#include <stdio.h>
#include <string.h>
int abs(int v){
	if(v<0)	return -v;
	return v;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int flag[12];
		for(int i=0;i<12;i++) flag[i] = 0;
		char l[12],r[12],s[12];
		int k=0;
		while(k++<3){
		scanf("%s %s %s",l,r,s);
		if(strcmp(s,"even")==0){
			char *t = l;
			while(*t!='\0'){
				flag[*t-'A'] = 100;
				t++;
			}
			t = r;
			while(*t!='\0'){
				flag[*t-'A'] = 100;
				t++;
			}
		}else if(strcmp(s,"up")==0){
			char *t = l;
			while(*t!='\0'){
				if(flag[*t-'A']!=100) flag[*t-'A']++;
				t++;
			}
			t = r;
			while(*t!='\0'){
				if(flag[*t-'A']!=100) flag[*t-'A']--;
				t++;
			}
		}else if(strcmp(s,"down")==0){
			char *t = l;
			while(*t!='\0'){
				if(flag[*t-'A']!=100) flag[*t-'A']--;
				t++;
			}
			t = r;
			while(*t!='\0'){
				if(flag[*t-'A']!=100) flag[*t-'A']++;
				t++;
			}
		}}
		int res = 0;
		int i=0;
		while(flag[i]==100)	i++;
		res = i;
		for(;i<12;i++){
			if(flag[i]!=100&&abs(flag[res])<abs(flag[i]))	res = i;
		}
		if(flag[res]>0){
			printf("%c is the counterfeit coin and it is heavy.\n",'A'+res);
		}else{
			printf("%c is the counterfeit coin and it is light.\n",'A'+res);
		}
	}
	return 0;
}
