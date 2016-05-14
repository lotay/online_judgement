#include <iostream>
#include <map>
#define N 105

using namespace std;

typedef struct{
	int price;
	int l;
	int cnt;
	int replaceId[N];
	int prices[N];
} Tribe;

Tribe tribes[N];
int n,m;
map<int,int> prices[N];
bool visited[N];

int MAX_INT = 1000000000;

int abs(int v){
	if(v<0)	return -v;
	return v;
}

int max(int a,int b){
	if(a>b)	return a;
	return b;
}

int min(int a,int b){
	if(a<b)	return a;
	return b;
}

int solve(int i,int minI,int maxI){
//	cout<<"T:"<<i<<" "<<tribes[i].l<<" "<<minI<<" "<<maxI<<endl;
//	if(prices[i][maxI*1000+maxI-minI]>0)	return prices[i][maxI*1000+maxI-minI];
	if(visited[i])	return tribes[i].price;
	visited[i] = true;
	int minPrice = tribes[i].price;
	for(int j=0;j<tribes[i].cnt;j++){
		int ni = tribes[i].replaceId[j];
		int minL = min(minI,tribes[ni].l);
		int maxL = max(maxI,tribes[ni].l);
		if(maxL-minL<=m){	
			int v = solve(ni,minL,maxL);
			if(tribes[i].prices[j]+v<minPrice)minPrice = tribes[i].prices[j]+v;
		}
	}
	visited[i] = false;
	prices[i][maxI*1000+maxI-minI] = minPrice;
	return minPrice;
}

int main(){
	cin>>m>>n;
	int i=0;
	while(i++<n){
		cin>>tribes[i].price>>tribes[i].l>>tribes[i].cnt;
		int j=0;
		while(j<tribes[i].cnt){
			cin>>tribes[i].replaceId[j]>>tribes[i].prices[j];
			j++;
		}
		visited[i] = false;
	}
	cout<<solve(1,tribes[1].l,tribes[1].l)<<endl;
	return 0;
}
