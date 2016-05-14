#include <iostream>
#include <memory.h>
#include <cmath> 
using namespace std;

int primeTable[1001];
int primeNum;
void init(){
	memset(primeTable,0,1001);
	for(int i=2;i<1000;i++){
		if(!primeTable[i]){
			for(int j=i*2;j<1001;j+=i){
				primeTable[j] = 1;
			}
		}
	}
	
	int i=0 ,j =2;
	for(;j<1001;j++){
		if(!primeTable[j]){
			primeTable[i++] = j;
//			cout<<j<<" ";
		}
	}
	primeNum = i;
}

bool isPrime(int t){
	if(t<2)	return false;
	for(int i=0;i<primeNum&&primeTable[i]*primeTable[i]<=t;i++){
		if(t%primeTable[i]==0) return false;
	}
	return true;
}

int main(){
	init();
	int a,b,n;
	cin>>a>>b>>n;
	while(a&&b&&n){
		int t = a;
		int cnt = 0;
		while(cnt<n){
			cnt += isPrime(t);
			if(cnt==n){
				break;
			}
			t += b;
		}
		cout<<t<<endl;
		cin>>a>>b>>n;
	} 
	return 0;
} 
