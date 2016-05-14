#include <stdio.h> 
#include <string.h>

#define N 200

int len = 0; 
int val;
void multi(int num[],int val){
	int i=0;
	for(;i<len;i++){
		num[i]= num[i]*val;
	}
	i=0;
	int pending = 0;
	for(;i<len;i++){
		int tmp = (num[i]+pending)/10;
		num[i] = (num[i]+pending)%10;
		pending = tmp;
	}
	while(pending){
		num[i++] = pending%10;
		pending/=10;
	}
	len = i;
}

void printResult(int *nums,int poi){
	int i = len-1;
	if(len<poi){
		printf(".");
		int j=0;
		for(j=0;j<poi-len;j++){
			printf("0");
		}
		while(i>=0){
			printf("%d",nums[i--]);
		}
	}else{
	int flag1 = 1, flag2= 0;
	int zeroCnt = 0;
	while(i>=0){
		if(i>poi-1){
			if(nums[i]!=0){
				flag2 = 1;
			}
			if(flag2){
				printf("%d",nums[i]);
			}
		}
		else {
		 	if(flag1){
				printf(".");
				flag1 = 0;
			}
			if(nums[i]==0){
				zeroCnt ++;
			}else{
				while(zeroCnt){
					printf("0");
					zeroCnt--;
				}
				printf("%d",nums[i]);
			}
		}
		i--;
	}
}
	printf("\n");
}

int main(int argc,char**argv){
	char s[100];
	int n;
	while(scanf("%s%d",s,&n)!=EOF){
		int l = strlen(s);
		int i=0,j=0;
		int poi = 0;
		int sum =0;
		for(;j<l;j++){
			if(s[j]=='.'){
				poi = j;
			}else{
				sum = sum*10+s[j]-'0';
				i++;
			}
		}
		poi = i-poi;
		int k = 0;
		int nums[N];
		nums[0] = 1;
		len = 1;
		for(;k<n;k++){
			multi(nums,sum);
		}
		poi *=n;
		printResult(nums,poi);
	}
}
