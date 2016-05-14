#include <iostream>
#include <fstream>

using namespace std;
int getVal(char ch){
	if(ch>='A'&&ch<='Z') return ch-'A'+1;
	return 0;
}
int main(){
	string line;
	while(getline(cin,line)){
		if(line[0]=='#'){
			break;
		}
		int cs = 0;
		for(int i=0;i<line.size();i++){
			cs+=(i+1)*getVal(line[i]);
		}
		cout<<cs<<endl;
	}
	return 0;
}
