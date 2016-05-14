#include <iostream>

#define N 1000001
using namespace std;
bool isPrime[N];
void init(){
	for(int i=2;i<=N;i++){
		if(!isPrime[i]){
			for(int j=2*i;j<=N;j+=i){
				isPrime[j] = 1;
			}
		}
	}
}


int main(){
	int n;
	init();
	cin>>n;
	while(n){
		int i=2;
		if(isPrime[i]||isPrime[n-i]){
			i++;
			while(i<=n/2){
				if(isPrime[i]==0&&isPrime[n-i]==0) {
					cout<<n<<" = "<< i<<" + "<<n-i<<endl;
					break;
				}
				i+=2;
			}
		}else cout<<n<<" = "<< i<<" + "<<n-i<<endl;
		cin>>n;
	}
	return 0;
}
