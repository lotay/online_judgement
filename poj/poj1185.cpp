#include <iostream>
#include <map>
#include <vector>
#define MM 65

using namespace std;
map<int,int> indexs;
int codes[MM];
bool used[1050]; 
int cnt = 0;
int n,m;
vector<string> boards;
int dp[MM][MM],tmp[MM][MM];
int nows[MM],last[MM],lastlast[MM];
int nNum = 0; 
int bitCnt[MM]; 
void dfs(int i,int j,int s,int num){
	if(j>=m){
		bitCnt[nNum] = num;
		nows[nNum++] = s;
		return ; 
	} 
	if(boards[i][j]=='P'){
		dfs(i,j+3,s|(1<<j),num+1); 
	} 
	dfs(i,j+1,s,num); 
}



int solve(){
	int lNum = 1,llNum = 1;
	tmp[0][0] = 0; 
	last[0] = lastlast[0] = 0; 
	for(int i=0;i<n;i++){ 
		nNum = 0;
		dfs(i,0,0,0); 
		for(int j=0;j<nNum;j++){
			int num = bitCnt[j]; 
			for(int p=0;p<lNum;p++){
				dp[j][p] = num; 
				if(last[p]&nows[j])	continue; 
				for(int q=0;q<llNum;q++){
					if(nows[j]&lastlast[q])	continue;
					if(dp[j][p]<tmp[p][q]+num) 	dp[j][p] = tmp[p][q]+num; 
				}
			}
		}
		for(int p=0;p<nNum;p++)	for(int q=0;q<lNum;q++)	tmp[p][q] = dp[p][q];
		for(int j=0;j<lNum;j++)	{
			lastlast[j]  = last[j]; 
		}
		for(int j=0;j<nNum;j++)	last[j] = nows[j]; 
		llNum = lNum; 
		lNum = nNum; 
	}
	int res = 0; 
	for(int i=0;i<nNum;i++){
		for(int j=0;j<lNum;j++){
			if(dp[i][j]>res)	res = dp[i][j]; 
		} 
	} 
	return res; 
}

int main(){
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		boards.push_back(s);
	}
	cout<<solve() <<endl; 
	return 0;
}
