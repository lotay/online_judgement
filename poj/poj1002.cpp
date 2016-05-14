#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

string numbers[] = {"2","2","2","3","3","3","4","4","4","5","5","5","6","6","6","7","0","7","7","8","8","8","9","9","9"};
string nums[] = {"0","1","2","3","4","5","6","7","8","9"};

string helper(string str){
	string tel= "";
	
	for(int i=0,j=0;i<str.length();i++){
		char ch = str[i];
		if(ch>='0'&&ch<='9'){
			tel = tel +nums[ch-'0'];
			j++;
		}
		if(ch>='A'&&ch<='Z'&&ch!='Q'&&ch!='Z'){
			tel=  tel +numbers[ch-'A'];
			j++;
		}
		if(j==3) {
			tel+="-";
			j++;
		}
	}
	return tel;
}

void show(string tels[],int t){
	int i=0;
	bool flag = false;
	while(i<t){
		string tel = tels[i++];
		int cnt = 1;
		while(i<t&&tels[i++]==tel){
			cnt++;
		}
		if(cnt>1){
			flag = true;
			cout<<tel<<" "<<cnt<<endl;
		}
	}
	
	if(!flag)	cout<<"No duplicates."<<endl;
}

int main(int argc,char**argv){
	int t;
	cin>>t; 
	string tels[100005];
	int i=0;
	while(i<t){
		string str;
		cin>>str;
		tels[i++] = helper(str);
	}
	
	sort(tels,tels+t);
	
	show(tels,t);
	return 0;
}
