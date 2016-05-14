#include <iostream>
#include <string.h>

#define N 210

using namespace std;
int n;
int transition[N][N];
int encodings[N];

string extendString(string & str,int n){
	string res(n,' ');
	int i=0;
	for(;i<str.length()-1;i++){
		res[i] = str[i+1];
	}
	return res;
}

void calcTransition(){
	for(int i=0;i<n;i++){
		int idx = i,b = i;
		int cnt = 0;
		do{
			transition[i][cnt+1] = idx;
			idx = encodings[idx];
			cnt++;
		}while(idx!=b);
		transition[i][0] = cnt;
	}
}

string transform(int k,string &str){
	string res(n,' ');
	for(int i=0;i<str.length();i++){
		int pos = k%transition[i][0];
		res[transition[i][pos+1]] = str[i];
	}
	return res;
}

int main(){
	char str[256];
	while(cin>>n&&n){
		int i=0,c;
		while(i<n){
			cin>>encodings[i];
			encodings[i]--;
			i++;
		}
		calcTransition();
		int k;
		while(cin>>k&&k){
			string msg;
			getline(cin,msg);
			msg = extendString(msg,n);
			cout<<transform(k,msg)<<endl;
		}
		cout<<endl;
	}
	return 0;
} 
