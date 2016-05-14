#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(){
	double vs,r,c,q;
	int n;
	cin>>vs>>r>>c>>n;
	double cr = c*r;
	double cr2 = cr*cr;
	
	while(n--){
		cin>>q;
		cout<<fixed << setprecision(3)<<(cr*q*vs)*(sqrt(1/(1+cr*cr*q*q)))<<endl;
	} 
	return 0;
}
