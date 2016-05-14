#include <iostream>
#include <string.h>
#include <algorithm>
#define N 26
using namespace std;

int cnt1[N];
int cnt2[N];
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		memset(cnt1,0,N);
		memset(cnt2,0,N);
		if(s1.size()!=s2.size()){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<s1.size();i++){
			cnt1[s1[i]-'A']++;
		}
		
		for(int i=0;i<s2.size();i++){
			cnt2[s2[i]-'A']++;
		}
		
		sort(cnt1,cnt1+N);
		sort(cnt2,cnt2+N);
		bool flag = true;
		for(int i=0;i<N&&flag;i++){
//			cout<<s1<<" "<<cnt1[i]<<" "<<s2<<" "<<cnt2[i]<<endl;
			if(cnt1[i]!=cnt2[i]){
				flag = false;
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
} 
