#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sticks(64);
vector<bool> removed(64);
void init(int n){
	for(int i=0;i<n;i++)removed[i] = false;
}

bool search(int left,int idx,int len,int n,int num){
	if(left==0){
		if(num==n) return true;
		return search(len,n-1,len,n,num);
	}
	for(int i=idx;i>=0;i--){
		if(!removed[i]&&left<sticks[i])	continue;
		removed[i] = true;
		if(search(left-sticks[i],i-1,len,n,num+1)){
			return true;
		}
		removed[i] = false;
		while(i>0&&sticks[i-1]==sticks[i]) i--; 
		if(left==len)break;
	}
	return false;
}

int solve(int baseLen,int sum,int n){
	int i=baseLen;
	vector<int> indexs;
	bool flag =false; 
	for(;i<=sum-i;i++){
		if(sum%i!=0)	continue;
		init(n);
		if(search(i,n-1,i,n,0)){
			flag =true;
			break;
		}
	}
	return flag?i:sum;
}

int main(){
	int n;
	cin>>n;
	while(n>0){
		int i = 0;
		int sum = 0, max;
		while(i<n){
			cin>>sticks[i];
			sum += sticks[i];
			if(sticks[i]>max)	max = sticks[i];
			i++;
		}
		sort(sticks.begin(),sticks.begin()+n);
		int res = solve(max,sum,n);
		cout<<res<<endl; 
		cin>>n;
	}
	return 0;
}
