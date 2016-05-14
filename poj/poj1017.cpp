#include <iostream>
using namespace std;
long long n1,n2,n3,n4,n5,n6;

long long solve(){
	long long cnt = n6;
	cnt += n5;
	int t1 = 11*n5;
	int t2 = n4*5;
	cnt += n4;
	cnt += n3/4;
	n3 %=4;
	if(n3>0){
		cnt ++;	
		if(n3==1){
			t2 +=5;
			t1 += 7;
		}else if(n3==2){
			t2 += 3;
			t1 += 6;
		}else if(n3==3){
			t2 +=1;
			t1 += 5;
		}
	}
	if(n2>=t2){
		n2 -= t2;
		cnt += n2/9;
		if(n2%9){
			cnt++;
			t1 += 36- 4*(n2%9);
		}
	}else{
		t1 += (t2-n2)* 4;
	}
	n1 -= t1;
	if(n1>0){
		cnt += n1/36;
		if(n1%36) cnt++;
	}
	return cnt;
}

int main(){
	cin>>n1>>n2>>n3>>n4>>n5>>n6;
	while(n1!=0||n2!=0||n3!=0||n4!=0||n5!=0||n6!=0){
		cout<<solve()<<endl;
		cin>>n1>>n2>>n3>>n4>>n5>>n6;
	}
	return 0;
}
