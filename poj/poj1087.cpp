#include <iostream>
#include <map>
#include <queue>

#define N 1001
#define SOURCE 0
#define SINK 1000
#define INFINITE 1000000

using namespace std;
map<string,int> indexs;
string receptacle[N];
string plugs[N];
map<int,int> flows[N];

int path[N];

int n,m,k;
int START = 0;

int maxFlow(){
	int max = 0;
	while(true){
		bool visited[N]={false};
		visited[SOURCE] = true;
		queue<int> reachables;
		reachables.push(SOURCE);
		bool newPath = false;
		while(!reachables.empty()){
			int ff = reachables.front();
			reachables.pop();
			if(ff==SINK){
				newPath = true;
				break;
			}
			visited[ff]=true;
			map<int,int> nodes = flows[ff];
			for (map<int, int>::iterator i=nodes.begin(); i!=nodes.end(); i++)  
		    {  
		        int nn = i->first;
				int vv = i->second;
				if(!visited[nn]&&vv>0){
					reachables.push(nn);
					path[nn] = ff;
				}
		    } 
		}
		if(newPath){
			int ff = SINK;
			while(ff!=SOURCE){
				int pp = path[ff];
				flows[pp][ff]--;
				if(flows[pp][ff]<=0){
					flows[pp].erase(ff);
				}
				flows[ff][pp]+=1;
				ff = pp;
			}
			max ++;
		}else{
			break;
		}
	}
	
	return max;
}

int main(){
	int startIndex =1;
	cin>>n;
	int i=0;
	while(i<n){
		cin>>receptacle[i];
		if(!indexs[receptacle[i]]){
			indexs[receptacle[i]] = startIndex++;
		}
		flows[SOURCE][indexs[receptacle[i]]] ++;
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
		flows[indexs[plugs[i]]][SINK] += 1;
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
		flows[indexs[inp]][indexs[out]] = INFINITE;
		i++;
	}
	int size = indexs.size();
	
	cout<<m-maxFlow()<<endl;
	return 0;
}
