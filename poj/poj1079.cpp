#include <iostream>

using namespace std;

double abs(double v){
	if(v<0)	return -v;
	return v;
}

int main(){
	int a,b;
	while(cin>>a>>b){
		double val = 1.0*a/b;
		int s=(int)(val+0.5),t=1;
		double delta = s-val;
		double ratio = delta;
		cout<<s<<"/"<<t<<endl;
		while(s*b!=t*a){
			if(ratio>0){
				t++;
			}else{
				s++;
			}
			ratio = 1.0*s/t-val;
			if(abs(ratio)<abs(delta)){
				cout<<s<<"/"<<t<<endl;
				delta = ratio;
			}
			if(s*b==t*a)	break;
		}
		cout<<endl;
	}
	return 0;
}
