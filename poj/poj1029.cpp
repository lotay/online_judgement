#include <stdio.h>
#include <vector>
#include <set>

using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	bool *weights = new bool[n+1]();
	for(int i=0;i<=n;i++) weights[i] = false;
	vector<vector<int> > coins;
	int p ,v,i=0;
	char label[2];
	while(k--){
		scanf("%d",&p);
		vector<int> pans;
		pans.push_back(p);
		i=0;
		while(i++<2*p) {
			scanf("%d",&v);
			pans.push_back(v);
		}
		scanf("%s",label);
		
		if(label[0]=='='){
			for(i=1;i<pans.size();i++) {
				weights[pans[i]] = true;
			}
			continue;
		}else if(label[0]=='>'){
			/*
				swap, and make sure the [1,p] is less than [p+1,2*p]
			*/
			int j = pans.size()-1;
			for(i=1;i<j;i++,j--){
				int tmp = pans[i];
				pans[i] =pans[j];
				pans[j] = tmp;
			}
		}
		coins.push_back(pans);
	}
	
	/*
		The following is used to remove all the coins the are in both sides.
	*/
	set<int> lessCoins ;
	for(k=0;k<coins.size();k++){
		vector<int> &pans = coins[k];
		for(int j=1;j<=pans[0];j++){
			lessCoins.insert(pans[j]);
		}
	}
	
	for(k=0;k<coins.size();k++){
		vector<int> &pans = coins[k];
		for(int j=1+pans[0];j<=pans[0];j++){
			if(lessCoins.find(pans[j])!=lessCoins.end()){
				weights[pans[j]] = true;
			};
		}
	}
	
	/*
		The following is used to enumerate all candidate and check whether conflicted with the relations. 
	*/
	set<int> suspectCoins;
	for(i=1;i<=n&&suspectCoins.size()<2;i++){
		if(!weights[i]) {
			bool candidated = true;
			for(k=0;k<coins.size();k++){
				vector<int> &pans = coins[k];
				p = pans[0];
				bool legal = false;
				for(int j=1;j<=p&&!legal;j++){
//					printf("%d ",pans[j]);
					if(pans[j]==i){
						legal = true;
					}
				}
//				printf("\ni:%d,%d,%d\n",i,candidated,legal,k);
				if(!legal){
					candidated = false;
					break;
				}
			}
//			printf("cand 1:%d\n",candidated);
			if(!candidated){
				candidated = true;
				for(k=0;k<coins.size();k++){
					vector<int> &pans = coins[k];
					p = pans[0];
					bool legal = false;
					for(int j=1+p;j<=2*p&&!legal;j++){
						if(pans[j]==i){
							legal = true;
						}
					}
//					printf("i:%d,%d,%d\n",i,candidated,legal,k);
					if(!legal){
						candidated = false;
						break;
					}
				}
			}
//			printf("cand 2:%d\n",candidated);
			if(candidated) suspectCoins.insert(i);
		}
	}
	if(suspectCoins.size()==1){
		printf("%d\n",*(suspectCoins.begin())); 
	}else{
		printf("0\n");
	}
	delete []weights;
	return 0;
}
