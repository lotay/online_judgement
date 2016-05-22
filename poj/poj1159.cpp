#include <stdio.h>
#define N 5005
char str[N];
int res[N];

int n;

int solve(){
	for(int i=0;i<=n;i++)	res[i] = 0;
//	res[0][0] = 0;
	int max,p ;
	for(int i=1;i<=n;i++){
		p = 0;
		for(int j=1;j<=n;j++){ 
			if(str[i-1]==str[n-j]){
				max = p+1;
			}else {
				max = res[j-1];
				if(res[j]>max)	max = res[j];
			}
			p = res[j];
			res[j] = max;
		}
	}
	return n-res[n];
}

int main(){
	scanf("%d",&n);
	scanf("%s",str);
	printf("%d\n",solve());
	return 0;
}
