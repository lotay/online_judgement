#include <iostream>
#include <algorithm>
using namespace std;
int n;
int counts[201];
int main(){
	int t;
	cin>>t;
	int s,e;
	while(t-->0){
		cin>>n;
		for(int i=0;i<201;i++){
			counts[i] = 0;
		}
		
		for(int i=0;i<n;i++){
			cin>>s>>e;
			if(s>e){
				int tmp = s;
				s = e;
				e = tmp;
			}
			
			for(int j=(s+1)/2;j<=(e+1)/2;j++){
				counts[j]++;
			}
		}
		sort(counts,counts+201);
		cout<<counts[200]*10<<endl;
	}
}
