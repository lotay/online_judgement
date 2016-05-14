#include <iostream>
#include <vector>

using namespace std;

vector<int> values;
void init(int k){
	values.clear();
	for(int i=1;i<=2*k;i++) values.push_back(i);
}

int solve(int k){
	int m = k+1;
	while(1){
		int s = 0;
		int i=0;
		for(;i<k;i++){
			s = (s+m-1)%(2*k-i);
			if(s<k) break;
		}
		if(i==k){
			break;
		}
		m++;
	}
	return m;
}

int main(){
	int k =0;
	cin>>k;
	for(int i=1;i<14;i++){
		cout<<solve(i)<<",";
	}
	int tables[]={2,7,5,30 ,169,441,1872,7632,1740,93313,459901,1358657,2504881};
	while(k){
		cout<<tables[k-1]<<endl;
		cin>>k;
	}
	return 0;
}
