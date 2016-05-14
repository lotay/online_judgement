#include <iostream>
#include <stack>

#define N 200

using namespace std;

string backwards[N],forwards[N];
int idxb = 1,idxf = 0;

int main(){
	backwards[0] = "http://www.acm.org/";
	string command;
	while(cin>>command&&!command.compare("QUIT")==0){
		bool ignored = false;
		string url;
		if(command.compare("VISIT")==0){
			cin>> url;
			if(idxb==0) idxb = 1;
			backwards[idxb++] = url;
			idxf = 0;
		}else if(command.compare("BACK")==0){
			if(idxb>1){
				forwards[idxf++] = backwards[--idxb];
				url = backwards[idxb-1];
			}else {
				if(idxb==1) --idxb;
				ignored = true;
			}
		}else if(command.compare("FORWARD")==0){
			if(idxf>0){
				if(idxb==0) idxb = 1;
				url = forwards[--idxf];
				backwards [idxb++] = forwards[idxf];
			}else{
				ignored = true;
			}
		}
		if(ignored)	cout<<"Ignored"<<endl;
		else cout<<url<<endl;
	}
}
