#include <iostream>

using namespace std;
const int nums[10] = {0,1,2,3,4,5,6,7,8,9};
int main(){
	int res[150];
	string str;
	cin>>str;
	for(int i=0;i<150;i++)	res[i] = 0;
	int len = 1;
	while(str.compare("0")!=0){
		int j=0;
		int t=0;
		while(str[t]=='0') t++;	// ignore preceding Zero.
		for(int i=str.size()-1;i>=t;i--,j++){
			res[j] = res[j]+nums[str[i]-'0'];
			res[j+1] = res[j+1]+res[j]/10;
			res[j] %= 10;
		}
		int flag = 0;
		while(res[j]>=10){
			res[j+1] = res[j+1]+res[j]/10;
			res[j] %=10;
			j++;
			flag = 1;
		}
		if(j+flag>len) len=j+flag;
		cin>>str;
	}
	for(int i=len-1;i>=0;i--)cout<<res[i];
	cout<<endl;
} 
