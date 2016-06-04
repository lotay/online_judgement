#include <stdio.h>
#include <queue>
#define N 105
#define M 1005
#define INF 1000000000
using namespace std;

int graphs[N][N];
int m,n;
int preCustomers[M];
int pigs[M];
int preNodes[N];
bool visited[N];
int flows[N];

void init(){
	for(int i=0;i<M;i++){
		preCustomers[i] = 0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graphs[i][j] = 0;
		}
	}
}

int min(int a,int b){
	if(a<b)	return a;
	return b;
}

bool findPath(){
	for(int i=0;i<=n;i++)	visited[i] = false;
	queue<int> q;
	q.push(0);
	flows[0] = INF;
	bool flag = false;
	while(!q.empty()&&!flag){
		int node = q.front();
		q.pop();
		visited[node] = true;
		for(int j=1;j<=n+1;j++){
			if(!visited[j]&&graphs[node][j]>0){
				preNodes[j] = node;
				flows[j] = min(flows[node],graphs[node][j]);
				if(j==n+1){
					flag = true;
					break;
				}
				q.push(j);
			}
		}
	}
	return flag;
}

int solve(){
	int res = 0 ;
	while(findPath()){
		//update
		res += flows[n+1];
//		cout<<flows[n+1]<<endl;
		int node = n+1;
		while(node>0){
			int p = preNodes[node];
			graphs[p][node]-=flows[n+1];
			graphs[node][p]+=flows[n+1];
			node = p;
		}
	}
	return res;
}

int main(){
	int k,t;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)	scanf("%d",&pigs[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&t);
			if(preCustomers[t]){
				graphs[preCustomers[t]][i] = INF;
			}else{
				graphs[preCustomers[t]][i] += pigs[t];
			}
			preCustomers[t] = i;
		}
		scanf("%d",&graphs[i][n+1]);
	}
//	for(int i=0;i<=n+1;i++){
//		for(int j=0;j<=n+1;j++){
//			cout<<graphs[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	printf("%d\n",solve());
	return 0;
}
