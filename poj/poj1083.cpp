#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class GraphNode{
	private:
		int color;
		vector<int> neighbors;
		int from,to;
	public: 
		GraphNode(){
//			this->from =fr;
//			this->to = to;
			this->color = 0;
		}
		void setColor(int color){
			this->color = color;
		}
		int getColor(){
			return this->color;
		}
		void addNeighbor(int id){
			this->neighbors.push_back(id);
		}
		const vector<int>& getNeighbors(){
			return this->neighbors;
		}
		void setFrom(int from){
			this->from = from;
		}
		int getFrom(){
			return this->from;
		}
		void setTo(int to){
			this->to = to;
		}
		int getTo(){
			return this->to;
		}
};

GraphNode *nodes = NULL;
int n;

void conflict(int i){
	for(int j=0;j<i;j++){
		if(!(nodes[i].getFrom()>nodes[j].getTo()||nodes[i].getTo()<nodes[j].getFrom())){
			nodes[i].addNeighbor(j);
			nodes[j].addNeighbor(i);
		}	
	}
}

int solve(){
	bool* visited = new bool[n]();
	vector<int> neighborNodes;
	vector<int> colors;
	int res = 0 ;
	for(int i=0;i<n;i++){
		cout<<"ii:"<<nodes[i].getNeighbors().size()<<","<<nodes[i].getTo()<<" "<<nodes[i].getFrom()<<endl;
		if(visited[i]) continue;
		neighborNodes.push_back(i);
		cout<<"iii:"<<i<<",neighborNodes:"<<neighborNodes.size()<<endl; 
		while(neighborNodes.size()>0){
			int k = neighborNodes.back();
			neighborNodes.pop_back();
			colors.clear();
			visited[k] = true;
			const vector<int> &nn = nodes[k].getNeighbors();
			for(int j=0;j<nn.size();j++){
				if(visited[nn[j]]){
					colors.push_back(nodes[nn[j]].getColor());
				}else{
					neighborNodes.push_back(nn[j]);
				}
			}
			sort(colors.begin(),colors.end());
			int tc = 0;
			for(;tc<colors.size();tc++){
				if(colors[tc]!=tc+1)break;
			}
			nodes[k].setColor(tc+1);
			cout<<"i:"<<i<<",c:"<<tc+1<<endl;
			if(tc+1>res)	res = tc+1;
		}
	}
	delete [] visited;
	return res;
}

int main(){
	int t = 0;
	int fr,to;
	cin>>t;
	while(t-->0){
		cin>>n;
		nodes = new GraphNode[n]();
		int i=0;
		while(i<n){
			cin>>fr>>to;
			fr /=2;
			to /=2;
			if(fr>to){
				int tmp = fr;
				fr = to;
				to = tmp;
			}
			nodes[i].setFrom(fr);
			nodes[i].setTo(to);//(fr,to);
			conflict(i);
			i++;
		}
		cout<<solve()*10<<endl;
		delete []nodes;
	}
	return 0;
}
