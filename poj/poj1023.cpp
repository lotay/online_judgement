#include <iostream>

#define N 65

using namespace std;
bool bits[N];
bool res[N];
int k;
long long int maxVals[N];
long long int minVals[N];

long long base = 1;

long long LONGLONG_MAX = (base<<63)-1;
long long LONGLONG_MIN = (base<<63);

int main(){
	int t;
//	cout<<sizeof(long long)<<":"<<LONGLONG_MIN<<";"<<LONGLONG_MAX<<endl;
	cin>>t;
	string bitStr;
	long long int val;
	long long int v;
	while(t--){
		cin >>k>>bitStr>>val;
		maxVals[0] = minVals[0] = 0;
		v = 1;
		for(int i=k-1;i>=0;i--){
			bits[k-i] = bitStr[i]=='p';
			minVals[k-i] = minVals[k-i-1];
			maxVals[k-i] = maxVals[k-i-1];
			if(bits[k-i]){
				maxVals[k-i] += v;
			}else{
				minVals[k-i] -= v;
			}
			v = v*2;
//			cout<<k-i<<":"<<bits[k-i]<<" "<<minVals[k-i]<<" "<<maxVals[k-i]<<endl;
		}
//		cout<<val<<" "<<minVals[k]<<" "<<maxVals[k]<<","<<v<<endl;
		
		int i=k;
		if(val==0){
			while(i>0){
				cout<<0;
				i--;
			}
			cout<<endl;
			continue;
		}
//		cout<<val<<" ";
		if(i==64){
			if(bits[i]){
				if(val>maxVals[k-1]){
					res[k] = true;
					val = LONGLONG_MIN+val;
				}else{
					res[k] = false;
				}
			}else{
				if(val<minVals[k-1]){
					res[k] = true;
					val = (LONGLONG_MAX+val+1);
				}else{
					res[k] = false;
				}
			}
			i--;
			v>>=1;
//			cout<<"val"<<val<<endl;
		}
		if(val>maxVals[i]||val<minVals[i]) cout<<"Impossible"<<endl;
		else{
			while(i>0){
				v =1;
				v = v<<(i-1);
				if(!bits[i]){
					v = -v;
				}
//				cout<<i<<" "<<v<<",v:"<<val-v<<","<<minVals[i-1]<<","<<maxVals[i-1]<<endl;
				if(minVals[i-1]+v<=val&&maxVals[i-1]+v>=val){
					res[i] = true;
					val -= v;
				}else{
					res[i] = false;
				}
				i--;
			}
			for(i=k;i>0;i--){
				cout<<res[i];
			}
			cout<<endl;
		} 
	}
	return 0;
}
