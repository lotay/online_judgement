#include <iostream>
using namespace std;
long long gcd(long a,long b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
void exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return; 
	}
	exgcd(b,a%b,x,y);
	long long tx = x;
	x = y;
	y = tx-a/b*y;
}
int main(){
	long long s1,s2,v1,v2,m;
	cin>>s1>>s2>>v1>>v2>>m;
	long long a = v1 - v2;
	long long b = m;
	long long c = s2 - s1;
	if(a<0) a+=m;
	long long d = gcd(a,b);
	if(c%d)	{
		cout<<"Impossible\n";return 0;
	}
	a/=d;
	b/=d;
	c/=d;
	long long x,y;
	exgcd(a,b,x,y);
	x = x*c%b;
	while(x<0)	x+=b;
	cout<<x<<endl;
	return 0;
}
