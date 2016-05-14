#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int typeCnt = 0;
int stampCnt = 0;
int maxVal = 0;
int maxCnt = 0;
int res[4] = {-1,-1,-1,-1};
bool tie = false;
void solve(vector<int> stamps, int sum, int curVal,int tc,int sc, int mv,int mc,int rs[],int idx){
//	cout<<"sum:"<<sum<<",curVal:"<<curVal<<",tc:"<<tc<<",sc:"<<sc<<",mv:"<<mv<<",mc:"<<mc<<endl;
	if(sc>4||curVal>sum) return;
	if(curVal==sum){
		if(tc>typeCnt||(tc==typeCnt&&sc<stampCnt)
		||(tc==typeCnt&&sc==stampCnt&&mv>maxVal)){
			typeCnt = tc;
			stampCnt = sc;
			maxVal = mv;
			maxCnt = mc;
			res[0] = rs[0];
			res[1] = rs[1];
			res[2] = rs[2];
			res[3] = rs[3];
			tie = false;
		}else if(typeCnt==tc&&sc==stampCnt&&mv==maxVal&&mc==maxCnt){
			tie = true;
		}
		return;
	}
	if(sc>=4)	return;
	for(int i=idx;i<stamps.size();i++){
		int tmpMc = mc;
		rs[sc] = i;
		solve(stamps,sum,curVal+stamps[i],tc==0?1:(tc+(i>idx)),sc+1,stamps[i],i>idx?1:mc+1,rs,i);
		mc = tmpMc;
	}
}

void print(vector<int> stamps,int req){
	cout<<req<<" ";
	if(typeCnt==0){
		cout << "---- none" <<    endl;
	}else{
		cout <<"("<<typeCnt << "):";
		int i=stampCnt-1;
		while(i>0&& stamps[res[i]]== stamps[res[i-1]]){
			if(res[i]==res[i-1]){
				tie = true;
			}
			i--;
		}
		if(tie){
			cout <<   " tie"   <<   endl;
		}else {
			for(i = 0; i < stampCnt;i++)
				if(res[i]>=0)	cout <<  " "<<   stamps[res[i]] ;
	        cout  <<  endl;
	    }
	}
}

int main(int argc,char **argv){
	vector<int> stamps; 
	vector<int> customers;
	map<int,int> counts;
	while(cin){
		int v = 0;
		stamps.clear();
		customers.clear();
		counts.clear(); 
		int n = 0,m = 0,max = 0;
		while(1){
			cin>>v;
			if(v==0)	break;
			if(counts[v]<5) {
				counts[v]++;
				stamps.push_back(v);
			}
		}
		if(stamps.size()==0){
			break;
		}
		
		sort(stamps.begin(),stamps.end());
		while(1){
			cin>>v;
			if(v==0)	break;
			//solve;
			customers.push_back(v);
		}
		for(int i=0;i<customers.size();i++){
			typeCnt = 0;
			stampCnt = 0;
			maxVal = 0;
			maxCnt = 0;
			tie = false;
//			res[0] = res[1] = res[2] =res[3] = -1;// {-1,-1,-1,-1};
			int rs[4];
			solve(stamps,customers[i],0,0,0,0,0,rs,0);
//			cout<<"typeCnt:"<<typeCnt<<",stampCnt:"<<stampCnt<<",maxVal:"<<maxVal<<",maxCnt:"<<maxCnt<<endl;
			print(stamps,customers[i]);
		}
	}
	return 0;
}
