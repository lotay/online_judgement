#include <iostream>
#include <algorithm>
using namespace std;
#define N 100
int lengths[N][N];
int heights[N][N];
int r,c;

int max(int a, int b){
	if(a>b)	return a;
	return b;
}

int dfs(int i,int j){
	if(lengths[i][j])	return lengths[i][j];
	int h = heights[i][j];
	int mh = 1;
	if(i>0&&heights[i-1][j]<h){
		mh = max(mh,dfs(i-1,j)+1);
	}
	if(i<r-1&&heights[i+1][j]<h){
		mh = max(mh,dfs(i+1,j)+1);
	}
	if(j>0&&heights[i][j-1]<h){
		mh = max(mh,dfs(i,j-1)+1);
	}
	if(j<c-1&&heights[i][j+1]<h){
		mh = max(mh,dfs(i,j+1)+1);
	}
	lengths[i][j] = mh;
	return mh;
}

int main(){
	cin>>r>>c;
	int i=0,res =0;
	while(i<r){
		int j=0;
		while(j<c){
			cin>>heights[i][j];
			lengths[i][j] = 0;
			j++;
		}
		i++;
	}
	for(i=0;i<r;i++)
		for(int j=0;j<c;j++)
			res = max(res,dfs(i,j));
	cout<<res<<endl;
	return 0;
}
