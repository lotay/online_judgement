#include <stdio.h>

int tables[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-100000}};
int gene1[101];
int gene2[101];
int costs[101][101];

int getIndex(char ch){
	switch(ch){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	return -1;
}

int max(int a,int b,int c){
	int res = a;
	if(b>res) res = b;
	if(c>res) res = c;
	return res;
}

int main(){
	int t;
	char ch;
	scanf("%d ",&t);
	while(t--){
		int l1,l2;
		scanf("%d ",&l1);
		
		for(int i=0;i<l1;i++) {
			scanf("%c",&ch);
			gene1[i] = getIndex(ch);
		}
		scanf("%d ",&l2);
		for(int i=0;i<l2;i++){
			scanf("%c",&ch);
			gene2[i] = getIndex(ch);
		} 
		costs[0][0] = 0;
		for(int i=0;i<l1;i++){
			costs[0][i+1] = tables[4][gene1[i]] +costs[0][i];
		}
		for(int i=0;i<l2;i++){
			costs[i+1][0] = tables[4][gene2[i]] +costs[i][0];
		}
		for(int i=0;i<l2;i++){
			int c = gene2[i];
			for(int j=0;j<l1;j++){
				int r = gene1[j];
				costs[i+1][j+1] = max(costs[i][j]+tables[r][c],
										costs[i+1][j]+tables[r][4],
										costs[i][j+1]+tables[4][c]);
			}
		}
		printf("%d\n",costs[l2][l1]);
	}
	return 0;
}

