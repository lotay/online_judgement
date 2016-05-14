#include <iostream>
#include <algorithm>
#define N 105

using namespace std;

int n,k,t;

int gangsters[N][3];
int dp[N];
int comp(const void* a,const void *b){
	return *((int*)a)-*((int* )b);
}

int abs(int a){
	if(a<0)	return -a;
	return a;
} 

int main(){
	cin>>n>>k>>t;
	gangsters[0][0]=gangsters[0][1]=gangsters[0][2] = 0;
	for(int i=1;i<=n;i++){
		cin>>gangsters[i][0];
	}
	for(int i=1;i<=n;i++){
		cin>>gangsters[i][1];
	}
	for(int i=1;i<=n;i++){
		cin>>gangsters[i][2];
	}
	
	qsort(gangsters+1,n,3*sizeof(int),comp);
	for(int i=0;i<=n;i++){
		cout<<gangsters[i][0]<<" "<<gangsters[i][1]<<" "<<gangsters[i][2]<<endl;
	}
	dp[0] = 0;
	int max = 0;
	for(int i=1;i<=n;i++){
		int tmpMax = 0;
		for(int j=i-1;j>=0;j--){
			if(gangsters[i][0]-gangsters[j][0]>=abs(gangsters[i][2]-gangsters[j][2])){
				if((j==0||dp[j]>0)&&dp[j]+gangsters[i][1]>tmpMax)	tmpMax = dp[j]+gangsters[i][1];
			}
		}
		dp[i] = tmpMax;
		if(dp[i]>max)	max = dp[i];
	}
	cout<<max<<endl;
	return 0;
} 
