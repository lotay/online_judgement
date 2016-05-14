#include <iostream>
#include <cmath>
using namespace std;
long long bases[5] = {0,45,9045,1395495,189414495};
long long starts[5] = {0,9,189,2889,38889};
long long indexs[5] = {0,9,99,999,9999};
long long lens[6] = {1,2,3,4,5,6};


long long bases2[6] = {0,9,189,2889,38889,488889};
long long starts2[6] = {0,9,99,999,9999,99999};

long long fix(long long  idx,long long n){
	while(true){
		int i=-1;
		int tmp = idx;
		while(tmp>0){
			i++;
			tmp /=10;
		}
		long long l = lens[i];
		long long s = starts[i];
		long long b = bases[i];
		long long ii = indexs[i];
		
		long long val = b+(idx-ii)*s+l*(idx-ii+1)*(idx-ii)/2;
		if(val>=n){
			break;
		}
		idx++;
	}
	return idx-1;
}

long long countVal(long long idx){
	int i=-1;
	int tmp = idx;
	while(tmp>0){
		i++;
		tmp /=10;
	}
	long long l = lens[i];
	long long s = starts[i];
	long long b = bases[i];
	long long ii = indexs[i];
		
	return b+(idx-ii)*s+l*(idx-ii+1)*(idx-ii)/2;
}

int main(){
	long long t,n;
	
	cin>>t;
	while(t-->0){
		cin>>n;
		int i=0;
		while(i<5&&n>bases[i]){
			i++;
		}
		i--;
		long long l = lens[i];
		long long s = starts[i];
		long long b = bases[i];
		long long base = (long long )(0.5*(-s*2-l+sqrt((long double)(s*2+l)*(s*2+l)-4*l*(2*b-2*n)))/l)+indexs[i];
		base = fix(base,n);
		long long val = countVal(base);
		long long left = n- val;
		
		i=0;
		while(i<6&&left>bases2[i]){
			i++;
		}
		int vv = starts2[i-1]+(left-bases2[i-1]-1)/lens[i-1]+1;
		int ii = lens[i-1]-(left-bases2[i-1]-1)%lens[i-1]-1;
		int j =0;
		while(j<ii){
			j++;
			vv /=10;
		}
		cout<<vv%10<<endl;
	}
	return 0;
}

