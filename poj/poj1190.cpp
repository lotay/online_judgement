#include <iostream>
#include <cmath>

using namespace std;
int n,m;
const int MAX = 1000000000;
int s = MAX;

int sumC(int n){
	return n*(n+1)*(2*n+1)/6;
}

int sumD(int n){
	return n*(n+1)/2;
}

int square(int n){
	return n*n;
}

void solve(int r,int h,int l,int area,int v){
	area += 2*r*h;
	v += r*r*h;
	cout<<"r:"<<r<<",h:"<<h<<",l:"<<l<<",area:"<<area<<",v:"<<v<<endl;
	if(l==m){
		if(v==n){
			area+= r*r;
			if(s>area)	s = area;
		}
		return;
	}
	if(s<=area+2*(n-v)/r)return;	//2*(n-sumv)/r+sums>=best
	for(int tr = r+1,ss = square(tr+m-l-1),sr=sumD(tr+m-l-1)-sumD(tr-1);
		(h+1)*(sumC(tr+m-l-1)-sumC(tr-1))+v<=n
			&&(area+ss+2*(h+1)*sr<s);tr++){
		for(int th=h+1;tr*tr*(sumD(th+m-l-1)-sumD(th-1))+v<=n
			&&(area+ss+2*th*(sr)<s);th++){
			solve(tr,th,l+1,area,v);
		}
		ss = square(tr+m-l-1);
		sr=sumD(tr+m-l-1)-sumD(tr-1);
	}
}

int main(){
	cin>>n>>m;
	for(int r = 1;sumC(r+m-1)-sumC(r-1)<=n;r++){
		for(int h=1;2*r*r*(sumD(h+m-1)-sumD(h-1))<=n;h++){
			solve(r,h,1,0,0);
		}
	}
	if(s==MAX)	cout<<0<<endl;
	else cout<<s<<endl;
}
