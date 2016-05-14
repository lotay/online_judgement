#include <iostream>
using namespace std;
string pre,ind;
void helper(int s1,int e1,int s2, int e2){
	if(s1<e1) {
		char root = pre[s1];
		int i = s2;
		for(;i<e2;i++) if(ind[i]==root) break;
		helper(s1+1,s1+i-s2+1,s2,i);
		helper(s1+i-s2+1,e1,i+1,e2);
		cout<<root;
	}
}

int main(){
	while(cin>>pre>>ind){
		helper(0,ind.size(),0,ind.size());
		cout<<endl;
	}
	return 0;
}
