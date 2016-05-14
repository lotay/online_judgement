#include <iostream>
#include <string>
using namespace std;
string strs[16];
string str;
string tmp;
const string END_STR = "-1";
int cnts[10];
string base[10] ={"0","1","2","3","4","5","6","7","8","9"};
string int2Str(int val){
	string res = "";
	while(val){
		res = base[val%10]+res;
		val /=10;
	}
	return res;
}

int solve(int &status){
	status = -1;
	int i=0;
	for(i=0;i<10;i++)	cnts[i]=0;
	for(i=0;i<15;i++){	
		strs[i] = str;
		for(int j=0;j<str.size();j++)
			cnts[str[j]-'0']++;
		tmp = "";
		for(int j=0;j<10;j++){
			if(cnts[j]>0){
				tmp += int2Str(cnts[j]);
				tmp += base[j];
				cnts[j] = 0;
			}
		}
//		cout<<i<<" "<<str<<" "<<tmp<<endl;
		if(str.compare(tmp)==0){
			status = 1;
			return i;
		}
		for(int j=0;j<=i;j++){
			if(strs[j].compare(tmp)==0){
				status = 2;
				return i-j+1;
			}
		}
		str =tmp;
	}
	return i;
}

int main(){
	cin>>str;
	while(END_STR.compare(str)!=0){
		int status ;
		cout<<str;
		int res = solve(status);
		if(res==0){
			cout<<" is self-inventorying"<<endl;
		}else if(status==1){
			cout<<" is self-inventorying after "<<res<<" steps"<<endl;
		}else if(status==2){
			cout<<" enters an inventory loop of length "<<res<<endl;
		}else if(status==-1){
			cout<<" can not be classified after 15 iterations"<<endl;
		}
		cin>>str;
	}
	return 0;
}
