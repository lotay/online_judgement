#include <iostream>

int digitCounts[10];
int nums[60];
int preRes[60];
using namespace std;
int main(){
	string num;
	while(cin>>num&&!num.empty()){
		for(int i=0;i<10;i++) digitCounts[i] = 0;
		int n = num.size();
		for(int i=0;i<n;i++) {
			nums[i] = num[n-1-i]-'0';
			preRes[i] = nums[i];
			digitCounts[nums[i]]++;
		}
		bool cyclic = true;
		int preVal = 0;
		for(int i=2;i<=n&&cyclic;i++){
			int counts[10];
			for(int j=0;j<10;j++)	counts[j] = 0;
			
			for(int j=0;j<n;j++){
				int val = preRes[j]+nums[j];
				if(j+1<n) preRes[j+1] += val/10;
				else if(val>=10) {
					cyclic = false;
					break;
				}
				preRes[j] = val%10;
				counts[preRes[j]]++;
			} 

			for(int j=0;j<10;j++){
				if(counts[j]!=digitCounts[j]){
					cyclic = false;
					break;
				}
			}
		}
		if(cyclic){
			cout<<num<<" is cyclic"<<endl;
		}else{
			cout<<num<<" is not cyclic"<<endl;
		}
	}
	return 0;
}
