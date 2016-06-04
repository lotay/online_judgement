#include <stdio.h>
int n,m,k;
char boards[155][15];
int pdp[60000];
int cdp[60000];
int ptris[15],ctris[15];;
int triples[11] = {1,3,9,27,81,243,729,2187,6561,19683,59049};

void to_tri(int v){
	for(int i=m-1;i>=0;i--){
		ptris[i] = v/triples[i];
		v %= triples[i];
	} 
}

int to_ten(int tris[]){
	int v = 0;
	for(int i=0;i<m;i++){
		v += tris[i]*triples[i];
	}
	return v;
}

int max(int a,int b){
	if(a>b)	return a;
	return b;
}

void dfs(int j,int k,int cnt,int s){
//	cout<<"0:"<<j<<" "<<k<<" "<<cnt<<" "<<s<<endl;
	cdp[s] = max(cdp[s],cnt);
	if(k>=m)	return ;
	if(k>=1&&!ptris[k]&&!ptris[k-1]&&!ctris[k]&&!ctris[k-1]){
		ctris[k] = ctris[k-1] = 2;
		int st = to_ten(ctris);
//		cout<<"1:"<<j<<" "<<k<<" "<<cnt+1<<" "<<st<<endl;
		dfs(j,k+2,cnt+1,st);
		ctris[k] = ctris[k-1] = 0;
	}
	if(k>=2&&ptris[k]<=1&&ptris[k-1]<=1&&ptris[k-2]<=1&&!ctris[k]&&!ctris[k-1]&&!ctris[k-2]){
		ctris[k] = ctris[k-1] = ctris[k-2] = 2;
		int st = to_ten(ctris);
//		cout<<"2:"<<j<<" "<<k<<" "<<cnt+1<<" "<<st<<endl;
		dfs(j,k+2,cnt+1,st);
		ctris[k] = ctris[k-1] = ctris[k-2] = 0;
	}
	dfs(j,k+1,cnt,s);
}

int solve(){
	int res = 0;
	for(int k = 0;k<triples[m];k++)	{
		pdp[k] = cdp[k] = -1;
	}
	for(int k = 0;k<m;k++){
		ptris[k] = 1+boards[0][k];
	}
	pdp[to_ten(ptris)] = 0;
	for(int i = 1;i<n;i++){
		for(int k = 0;k<triples[m];k++)	cdp[k] = -1;
		for(int j = 0;j<triples[m];j++){
			if(pdp[j]>=0){
				to_tri(j);
				for(int k = 0;k<m;k++){
					if(boards[i][k]){
						ctris[k] = 2;
					}else{
						ctris[k] = max(ptris[k]-1,0);
					}
				}
				dfs(j,1,pdp[j],to_ten(ctris));
			}
		}
		for(int k=0;k<triples[m];k++)	{
			pdp[k] = cdp[k];
			cdp[k] = -1;
		}
	}
	for(int k=0;k<triples[m];k++)	{
		res = max(res,pdp[k]);
	}
	return res;
} 

int main(){
	int d,r,c;
	scanf("%d",&d);
	while(d--){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<150;i++){
			for(int j=0;j<10;j++){
				boards[i][j] = 0;
			}
		}
		for(int i=0;i<k;i++){
			scanf("%d %d",&r,&c);
			boards[r-1][c-1] = 1;
		}
		printf("%d\n",solve());
	}
}

