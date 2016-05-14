#include <iostream>
#include <algorithm>
using namespace std;
#define N 105
int lengths[N][N];
int oHeights[N][N];

typedef struct{
	int v;
	int x;
	int y;
} MM; 

MM heights[N*N];
int comp(const void *a,const void *b){
	return ((MM*)a)->v - ((MM*)b)->v;
}

int max(int a, int b){
	if(a>b)	return a;
	return b;
}

int main(){
	int r,c;
	cin>>r>>c;
	int i=0,res =0;
	int t = 0;
	while(i<r){
		int j=0;
		while(j<c){
			cin>>t;
			heights[i*r+j].v = t;
			heights[i*r+j].x = i;
			heights[i*r+j].y = j;
			lengths[i][j] = 0;
			oHeights[i][j] = t;
			j++;
		}
		i++;
	}
	qsort(heights,r*c,sizeof(MM),comp);
	for(int k=0;k<r*c;k++){
		int m = heights[k].x;
		int n = heights[k].y;
		int v = oHeights[m][n];
		int maxLen = 1;
		if(m>0&&oHeights[m-1][n]<v&&maxLen<lengths[m-1][n]+1){
			maxLen=lengths[m-1][n]+1;
		}
		if(n>0&&oHeights[m][n-1]<v&&maxLen<lengths[m][n-1]+1){
			maxLen=lengths[m][n-1]+1;
		}
		if(m<r-1&&oHeights[m+1][n]<v&&maxLen<lengths[m+1][n]+1){
			maxLen=lengths[m+1][n]+1;
		}
		if(n<c-1&&oHeights[m][n+1]<v&&maxLen<lengths[m][n+1]+1){
			maxLen=lengths[m][n+1]+1;
		}
		lengths[m][n] = maxLen;
	}
	for(i=0;i<r;i++)
		for(int j=0;j<c;j++)
			res = max(res,lengths[i][j]);
	cout<<res<<endl;
	return 0;
}
