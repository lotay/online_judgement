#include <iostream>

using namespace std;
bool flag[21];
int main(){
	int t,n,l;
	cin>>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			flag[i] = false;
		}
		while(n--){
			cin>>l;
			int i=l;
			for(;i>0;i--){
				if(!flag[i]){
					flag[i] = true;
					cout<<(l-i+1)<<" ";
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
