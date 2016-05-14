#include <iostream>

using namespace std;

int main(){
	double k,h;
	int n;
	cin>>k>>h>>n;
	double x[110],y[110];
	for(int i=0;i<n;i++){
		cin>>>x[i]>>y[i];
	}
	x[n] = x[0];
	y[n] = y[0];
	
	
	return 0;
	
}
