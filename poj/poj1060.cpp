#include <iostream>

using namespace std;
int tmp[1005];
int as[2005];
int bs[1005];
int cs[1005];

int subtract(int as[],int n,int bs[],int m,int bias){
	while(n>=bias&&as[n]==bs[n-bias]) {
		as[n] = 0;
		n--;
	}
	for(int i=n;i>=bias;i--){
		as[i] = as[i]!=bs[i-bias];
	}
	return n;
}

int multi(int as[],int n,int bs[],int m){
	int mm = m+n;
	for(int i=0;i<=n;i++) tmp[i] = as[i];
	for(int i=mm;i>=0;i--){
		int cnt = 0;
		for(int j=n;j>=0;j--){
			if(i-j<=m&&i-j>=0) cnt += tmp[j]*bs[i-j];
		}
		as[i] = cnt%2;
	}
	return mm;
}

int module(int as[],int n,int bs[],int m){
	if(n<m)	return n;
	while(n>=m){
		n = subtract(as,n,bs,m,n-m);
	}
	return n;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,p;
		cin>>n;
		n--;
		for(int i=0;i<=n;i++){
			cin>>as[n-i];
		}
		
		cin>>m;
		m--;
		for(int i=0;i<=m;i++){
			cin>>bs[m-i];
		}
		
		cin>>p;
		p--;
		for(int i=0;i<=p;i++){
			cin>>cs[p-i];
		}
		
		n =multi(as,n,bs,m);
		n = module(as,n,cs,p);
		cout<<n+1;
		for(int i=n;i>=0;i--)	cout<<" "<<as[i];
		cout<<endl;	
	}
	return 0;
}
