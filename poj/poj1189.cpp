#include <stdio.h>
#define N 55

typedef long long Long;
char boards[N][N];
int n,m;
Long dists[N][N];

void solve(){
	Long b = 1l;
	dists[0][1] =(b<<n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(boards[i][j]=='*'){
				dists[i][j] += dists[i-1][j]/2;
				dists[i][j+1] += dists[i-1][j]/2;
			}
		}
		if(i>1){
			for(int j=2;j<=i;j++){
				if(boards[i-1][j-1]=='.'){
					dists[i][j] += dists[i-2][j-1];
				}
			}
		}
//		for(int j=1;j<=i+1;j++){
//			printf("%d\t",dists[i][j]);
//		}
//		printf("\n");
	}
}

Long gcd(Long a,Long b){
	if(b==0)	return a;
	return gcd(b,a%b);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dists[i][j] = 0;
			boards[i][j] = ' ';		
		}
	}
	char ch;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			while(scanf("%c",&ch)&&(ch!='.'&&ch!='*'));
			boards[i][j] = ch;
		}
//		printf("\n");
	}
	solve();
	if(dists[n][m+1]){	
		Long g = gcd(dists[0][1],dists[n][m+1]);
//		printf("g:%d\n",g);
		printf("%lld/%lld\n",dists[n][m+1]/g,dists[0][1]/g);
	}else{
		printf("0/%lld\n",dists[0][1]);
	}
	return 0;
}
