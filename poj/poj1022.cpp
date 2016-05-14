#include <iostream>
#include <map>

using namespace std;

#define N 101
#define M 8
int neighbors[N][M];
int n;
bool visited[N];

int mXs[M];
map<int,int> indexMaps;
bool consistent = true;
int visitNum = 0;
bool dfs(int pix,int xs[]){
	int idx = indexMaps[pix];
	if(visited[idx]) return true;
	if(!consistent) return false;
	//update maxValues..
	for(int i=0;i<M/2;i++){
		if(mXs[i*2]>xs[i]){
			mXs[i*2] = xs[i];
		}
		if(mXs[i*2+1]<xs[i]){
			mXs[i*2+1] = xs[i];
		}
	}
	visited[idx] = true;
	visitNum ++;
	for(int j=0;j<M;j++){
		if(neighbors[idx][j]){
			int ni = neighbors[idx][j];
			int tj = (j/2)*2+!(j%2);
			if(neighbors[indexMaps[ni]][tj]!=pix) {
				consistent = false;
				return false;
			}
			if(!visited[indexMaps[ni]]){
				int increaseNum = (j%2==0?-1:1);
				xs[j/2] += increaseNum;
				if(!dfs(ni,xs)){
					return false;
				}
				xs[j/2] -= increaseNum;
			}
		}
	}
	return true;
}
int solve(int start){
	int xs[4] = {0,0,0,0};
	
	visitNum = 0;
	dfs(start,xs);
	if(visitNum!=n||!consistent){
		consistent = false;
		return  -1;
	}
	int res = 1;
	for(int i=0;i<M;i+=2) {
		res*=(mXs[i+1]-mXs[i]+1);
	}
	return res;
}

int main(){
	int t,id;
	cin>>t;
	while(t-->0){
		cin >>n;
		consistent = true;
		indexMaps.clear();
		int start = -1;
		for(int i=0;i<M;i++) mXs[i] = 0;
		for(int i=1;i<=n;i++){
			cin>>id;
			indexMaps[id] = i;
			if(start<0) start = id;
			visited[i] = false;
			for( int j=0;j<M;j++){
				cin>>neighbors[i][j];
			}
		}
		int res = solve(start);
		if(consistent)	cout<<res<<endl;
		else cout<<"Inconsistent"<<endl;
	}
	return 0;
}
