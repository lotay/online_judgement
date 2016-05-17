#include <iostream>
#define N 12

using namespace std;

string tableaus[N];
int res[N*N*N][3];
int cnt = 0;

int test(int i,int j,int k){
//	cout<<tableaus[i]<<" "<<tableaus[j]<<" "<<tableaus[k]<<endl;
	for(int p=0;p<4;p++){
		if(!((tableaus[i][p]==tableaus[j][p]
			&&tableaus[i][p]==tableaus[k][p])
			||
			(tableaus[i][p]!=tableaus[j][p]
			&&tableaus[j][p]!=tableaus[k][p]
			&&tableaus[i][p]!=tableaus[k][p]))){
			return 0;
		}
	}
	return 1;
}

int solve(){
	cnt = 0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for(int k=j+1;k<N;k++){
				if(test(i,j,k)){
					res[cnt][0] = i;
					res[cnt][1] = j;
					res[cnt][2] = k;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main(){
	string line;
	while(cin>>line&&!line.empty()){
		tableaus[0] = line;
		int i=1;
		while(i<N){
			cin>>line;
			tableaus[i++] = line;
		}
		
		solve();
		cout<<"CARDS: ";
		for(i=0;i<N;i++){
			cout<<" "<<tableaus[i];
		}
		cout<<endl<<"SETS:   ";
		for(int k=0;k<cnt;k++){
			if(k){
				cout<<"        ";
			}
			cout<<k+1<<". ";
			cout<<" "<<tableaus[res[k][0]]<<" "<<tableaus[res[k][1]]<<" "<<tableaus[res[k][2]]<<endl;
		}
		if(!cnt){
			cout<<"*** None Found ***"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
