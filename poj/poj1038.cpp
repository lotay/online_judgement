#include <iostream>
#include <map>

using namespace std;

map<string,int> counts;

int n,m,k;
char status[150*10];

void printBoard(){
	cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<status[j*n+i]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
}

int solve(int x,int y,int dep){
//	string sts(status);
//	if(counts[sts]>0)	return counts[sts];
	int max = 0;
	int j=y;
	for(int i=x;i<n-1;i++){
		for(;j<m-1;j++){
			if(i>=n-2&&j>=m-1)	continue;
			if(status[i*m+j]=='0'&&(status[(i+1)*m+j]=='0'&&status[i*m+j+1]=='0'&&status[(i+1)*m+j+1]=='0')){
				status[i*m+j] = status[(i+1)*m+j]=status[i*m+j+1]=status[(i+1)*m+j+1]='1';
				if(j<m-2&&(status[i*m+j+2]=='0'&&status[(i+1)*m+j+2]=='0')){
					status[i*m+j+2]=status[(i+1)*m+j+2] = '1';
					int tmp = solve(i,j+3,dep+1)+1;
					if(max<tmp) max =tmp;
					status[i*m+j+2]=status[(i+1)*m+j+2] = '0';
				}
				
				if(i<n-2&&(status[(i+2)*m+j]=='0'&&status[(i+2)*m+j+1]=='0')){
					status[(i+2)*m+j]=status[(i+2)*m+j+1] = '1';
					int tmp = solve(i,j+2,dep+1)+1;
					if(max<tmp) max =tmp;
					status[(i+2)*m+j]=status[(i+2)*m+j+1] = '0';
				}
				status[i*m+j] = status[(i+1)*m+j]=status[i*m+j+1]=status[(i+1)*m+j+1]='0';
			}
		}
		j=0;
	}
//	counts[sts] = max;
	return max;
}

int main(){
	int d,r,c;
	cin>>d;
	while(d--){
		cin>>n>>m>>k;
		for(int i=0;i<150;i++){
			for(int j=0;j<10;j++){
				status[i*10+j] = '0';
			}
		}
		for(int i=0;i<k;i++){
			cin>>r>>c;
			status[(r-1)*m+c-1] = '1';
		}
		cout<<solve(0,0,1)<<endl;
	}
}

