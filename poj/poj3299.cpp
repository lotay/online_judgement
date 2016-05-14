#include <iostream> 
#include <iomanip> 
#include <cmath>
using namespace std;

double humidex(double t,double d){
	return t+0.5555*(6.11 *exp(5417.7530 * ((1/273.16) - (1/(d+273.16))))-10.0);
}
double temperature(double h,double d){
	return h-0.5555*(6.11 *exp(5417.7530 * ((1/273.16) - (1/(d+273.16))))-10.0);
}
double dew(double h,double t){
	return 1/(1/273.16-(log(((h-t)/0.5555+10.0)/6.11))/5417.753)-273.16;
}
int main(){
	string s1,s2;
	double v1,v2;
	cin>> s1;
	cout<<setiosflags(ios::fixed)<<setprecision(1);
	double t,d,h ;
	while(s1[0]=='H'||s1[0]=='T'||s1[0]=='D'){
		cin>> v1>>s2>>v2;
		if(s1[0]=='T'&&s2[0]=='D'){
			t = v1;
			d = v2;
			h = humidex(t,d);
		}else if(s1[0]=='D'&&s2[0]=='T'){
			t = v2;
			d = v1;
			h = humidex(t,d);
		}else if(s1[0]=='H'&&s2[0]=='D'){
			h = v1;
			d = v2;
			t = temperature(h,d);
		}else if(s1[0]=='D'&&s2[0]=='H'){
			h = v2;
			d = v1;
			t = temperature(h,d);
		}else if(s1[0]=='T'&&s2[0]=='H'){
			t = v1;
			h = v2;
			d = dew(h,t);
		}else if(s1[0]=='H'&&s2[0]=='T'){
			h = v1;
			t = v2;
			d = dew(h,t);
		}
		cout<<"T "<<t<<" D "<<d<<" H "<<h<<" "<<endl; 
		s1 = "";
		cin>> s1;
	}
}
