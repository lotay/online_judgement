#include <iostream>
#include <map>
#include <vector>

#define N 210
#define PRIME_NUM 100000007


using namespace std;
int n;

map<string,int> hashedIndexs;

int hashCode(vector<int> & indexs){
	int i = 0;
	long long hCode = 0, hashBase = 1;
	while(i<indexs.size()){
		hCode	 += i*hashBase;
		hCode	 %= PRIME_NUM;
		hashBase *= n;
		hashBase %= PRIME_NUM;
		i++;
	}
	return (int)hCode;
}

vector<int> transform(vector<int> &preIndexs,vector<int> &codes){
	vector<int> res(preIndexs.size());
	for(int i=0;i<preIndexs.size();i++){
		res[i] = preIndexs[codes[i]];
	}
	return res;
}

string transform(string &str,vector<int> &indexs){
	string res(indexs.size(),' ');
	for(int i=0;i<indexs.size();i++){
		res[indexs[i]] = str[i];
	}
	return res;
}

bool equalCheck(vector<int> &index1,vector<int> &index2){
	for(int i=0;i<index1.size();i++){
		if(index1[i]!=index2[i]) return false;
	}
	return true;
}

int repeatCheck(vector<int> & index,int hCode){
	if(hashedIndexs.find(hCode)!=hashedIndexs.end()){
		vector<int> &idxss = hashedIndexs[hCode];
		for(int i = 0;i<idxss.size();i++){
			int ii = idxss[i];
			if(equalCheck(index,codeIndexs[ii])){
				return ii;
			}
		}
		return -1;
	}else{
		return -2;
	}
}

string extendString(string & str,int n){
	string res(n,' ');
	int i=0;
	for(;i<str.length();i++){
		res[i] = str[i];
	}
	while(i<str.length()){
		res[str.length()] = ' ';
	}
	return res;
}

int main(){
	cin>>n;
	char str[256];
	while(n){
		hashedIndexs.clear();
		vector<int> codes;
		int i=0,c;
		while(i<n){
			cin>>c;
			codes.push_back(c-1);
			i++;
		}
		int k;
		int maxK = 0;
		while(k){
			cin>>k;
			if(k==0) break;
			cin.get(str,n+1,'\n');
			msg = msg.substr(1);
		
			string msg = extendString(msgs[i],n);
			int k = kVals[i];
			if(k>start){
				k = (k-start)%len+start;
			}
			vector<int> & tranIndexs = codeIndexs[k];
			//TODO: transfoer.
			cout<<transform(msg,codeIndexs[k])<<endl;
		}
	
		cout<<endl;
		cin>>n;
	}
	return 0;
} 
