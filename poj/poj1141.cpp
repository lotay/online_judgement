#include <iostream>
#define N 105
#define INF 100000000
using namespace std;

int dp[N][N];
int len;
string brackets;
int paths[N][N];
int min(int a,int b){
	if(a<b)	return a;
	return b;
}

bool match(int i,int j){
	return ((brackets[i]=='('&&brackets[j]==')')||(brackets[i]=='['&&brackets[j]==']'));
}

string restore(int i,int j){
//	cout<<"i:"<<i<<",j:"<<j<<endl;
	if(i>j)	return "";
	if(i==j){
		if(brackets[i]=='('||brackets[i]==')')	return "()";
		return "[]";
	}
	if(paths[i][j]<0){
		return brackets[i]+restore(i+1,j-1)+brackets[j];
	}
	return restore(i,paths[i][j])+restore(paths[i][j]+1,j);
}

int main(){
	cin>>brackets;
	len = brackets.size();
	for(int i=0;i<len;i++)	{
		for(int j=i+1;j<len;j++)
			dp[i][j] = INF;
		for(int j=0;j<i;j++)
			dp[i][j] = 0;
		dp[i][i] = 2;
	}
	for(int l = 1;l<len;l++){
		for(int i=0;i+l<len;i++){
			if(match(i,i+l)){
				dp[i][i+l] = 2 + dp[i+1][i+l-1];
				paths[i][i+l] = -1;
			}
			for(int k = i;k<i+l;k++){
				if(dp[i][k]+dp[k+1][i+l]<dp[i][i+l]){
					dp[i][i+l] = dp[i][k]+dp[k+1][i+l];
					paths[i][i+l] = k;
				}
			}
		} 
	}
//	for(int l = 0;l<len;l++){
//		for(int i=0;i<len;i++){
//			printf("%d ",dp[l][i]);
//		}
//		printf("\n");
//	}
//	cout<<endl;
//	for(int l = 0;l<len;l++){
//		for(int i=0;i<len;i++){
//			printf("%d ",paths[l][i]);
//		}
//		printf("\n");
//	}
//	printf("%d\n",dp[0][len-1]);
	cout<<restore(0,len-1)<<endl;
	return 0;
}
