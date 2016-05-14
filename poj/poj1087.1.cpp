#include <iostream>
#include <map>
#include <string.h>

#define N 1005

using namespace std;
map<string,int> indexs;
string receptacle[N];
string plugs[N];
bool reachables[N][N];
int targetIndexs[N];
int n,m,k;

int useif[N]; 
int link[N]; 

void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			reachables[i][j] = false;
		}
		reachables[i][i] = true;
	} 
}

int can(int t){
    int i; 
    for(i=1;i<=m;i++) 
    { 
        if(useif[i]==0 && reachables[t][targetIndexs[i]]) 
        {
            useif[i]=1; 
            if(link[i]==-1||can(link[i])) 
            { 
                link[i]=t; 
                return 1;
            } 
        } 
    } 
    return 0; 
} 

int MaxMatch() 
{
    int i,num; 
    num=0; 
    memset(link,0xff,sizeof(link)); 
    for(i=1;i<=n;i++) 
    { 
        memset(useif,0,sizeof(useif)); 
        if(can(i)) num++; 
    } 
    return num; 
}

int main(){
	init();
	int startIndex =1;
	cin>>n;
	int i=0;
	while(i<n){
		cin>>receptacle[i];
		if(!indexs[receptacle[i]]){
			indexs[receptacle[i]] = startIndex++;
		}
		i++;
	}
	i=0;
	cin>>m;
	string device;
	while(i<m){
		cin>>device>>plugs[i];
		if(!indexs[plugs[i]]){
			indexs[plugs[i]] = startIndex++;
		}
		targetIndexs[i] = indexs[plugs[i]];
		i++;
	}
	
	cin>>k;
	i=0;
	string inp,out;
	while(i<k){
		cin>>out>>inp;
		if(!indexs[out]){
			indexs[out] = startIndex++;
		}
		if(!indexs[inp]){
			indexs[inp] = startIndex++;
		}
		reachables[indexs[inp]][indexs[out]] = true;
		i++;
	}
	int size = indexs.size();
	for(int k=1;k<startIndex;k++){
		for(i=1;i<startIndex;i++){
			for(int j=1;j<startIndex;j++){
				reachables[i][j] = reachables[i][j]||(reachables[i][k]&&reachables[k][j]);
			}
		}
	}
	cout<<m-MaxMatch()<<endl;
	return 0;
}
