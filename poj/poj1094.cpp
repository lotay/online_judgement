#include <iostream>
#include <queue>
#define N 27
using namespace std;
int nodes[N][N];
int parentNodes[N];
int pNodes[N];
int n,m;
int results[N];
bool exists[N][N];

int checkRelation(int edges){
	queue<int> roots;
	for(int i=0;i<n;i++) {
		pNodes[i] = parentNodes[i];
		if(!pNodes[i]){
			roots.push(i);
		} 
	}
	if(roots.size()==0){
		return -2;
	}
	int maxSize = roots.size();
	int k = 0;
	while(!roots.empty()){
		int ni = roots.front();
		roots.pop();
		results[k++] = ni;
		for(int i=1;i<=nodes[ni][0];i++){
			pNodes[nodes[ni][i]]--;
			edges--;
			if(pNodes[nodes[ni][i]]==0) roots.push(nodes[ni][i]);
		}
		if(roots.size()>maxSize) maxSize = roots.size();
	}
	if(edges>0)return -2;
	if(maxSize==1&&k==n)	return 0;
	return -1;
}


int main(){
	cin>>n>>m;
	while(n&&m){
		int i=0;
		for(;i<n;i++){
			parentNodes[i] = 0;
			for(int j=0;j<n;j++){
				nodes[i][j] = 0;
				exists[i][j] = false;
			}
		}
		string relation;
		i=0;
		bool determined = false,inconsistency = false;
		int idx = 0;
		while(i++<m){
			cin>>relation;
			int a = relation[0]-'A';
			int b = relation[2]-'A';
			if(exists[a][b]) continue;
			exists[a][b] = true;
			parentNodes[b]++;
			nodes[a][0]++;
			nodes[a][nodes[a][0]] = b;
			if(inconsistency||determined){
				continue;
			}
			int t = checkRelation(i);
			if(t==0) {
				determined = true;
				idx = i;
			}
			else if(t==-2) {
				inconsistency = true;
				idx = i;
			}
		}
		if(inconsistency){
			cout<<"Inconsistency found after "<<idx<<" relations."<<endl;
		}else if(determined){
			cout<<"Sorted sequence determined after "<<idx<<" relations: ";
			for(int j=0;j<n;j++){
				cout<<(char)(results[j]+'A');
			} 
			cout<<"."<<endl;
		}else{
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
		
		cin>>n>>m;
	}
}
