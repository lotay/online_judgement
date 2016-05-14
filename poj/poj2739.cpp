#include <iostream>
#include <string.h>

#define N 10001
using namespace std;
int primeTable[N];
int primeNum;
void init(){
	memset(primeTable,0,N);
	for(int i=2;i<N;i++){
		if(!primeTable[i]){
			for(int j=i*2;j<N;j+=i){
				primeTable[j] = 1;
			}
		}
	}
	
	int i=0 ,j =2;
	for(;j<N;j++){
		if(!primeTable[j]){
			primeTable[i++] = j;
		}
	}
	primeNum = i;
}

int solve(int n){
	int s = 0,e = 0;
	int sum = 0;
	int cnt = 0;
	while(primeTable[s]<=n&&s<primeNum&&e<=primeNum){
		if(sum<n){
			sum+=primeTable[e++];
		}else{
			sum-=primeTable[s++];
		}
		if(sum==n){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	int n;
	init();
	cin>>n;
	while(n){
		cout<<solve(n)<<endl;
		cin>>n;
	}
	return 0;
}
