#include <iostream>
using namespace std;
int dp[21][801][201];
int ps[200],ds[200],vs[200],ss[200];
int n,m;
int base = 400;
void init(){
	for(int i=0;i<=m;i++){
		for(int j=0;j<801;j++){
			dp[i][j][200] = -1;
			for(int k=0;k<200;k++)dp[i][j][k] = 0;
		}
	}
}

void solve(){
	init();
//	base = 20*m;
	dp[0][base][200] = 0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=2*base;j++){
			int maxK = -1;
			for(int k=0;k<n;k++){
				if(j-vs[k]>=0&&dp[i-1][j-vs[k]][200]>=0&&!dp[i-1][j-vs[k]][k]){
					if(maxK<0||dp[i-1][j-vs[k]][200]+ss[k]>dp[i-1][j-vs[maxK]][200]+ss[maxK]){
						maxK = k;
					}
				}
			}
			if(maxK>=0){
				dp[i][j][200] = dp[i-1][j-vs[maxK]][200]+ss[maxK];
				for(int k=0;k<n;k++){
					dp[i][j][k] = dp[i-1][j-vs[maxK]][k];
				}
				dp[i][j][maxK] = 1;
			}
		}
	}

	int tj = -1;
	for(int j=0;j<=n*20;j++){
		if(dp[m][base+j][200]>=0||dp[m][base-j][200]>=0){
			if(dp[m][base+j][200]>dp[m][base-j][200]){
				tj = base+j;
			}else{
				tj = base-j;
			}
			break;
		}
	}
	cout<<"Best jury has value "<<(tj+dp[m][tj][200]-base)/2
	<<" for prosecution and value "<<(dp[m][tj][200]-tj+base)/2<<" for defence: "<<endl;
	for(int k=0;k<n;k++){
		if(dp[m][tj][k])	cout<<" "<<(k+1);
	}
	cout<<endl<<endl;
}

int main(){
	cin>>n>>m;
	int t = 1;
	while(n!=0||m!=0){
		int t1,t2;
		int i=0;
		while(i<n){
			cin>>ps[i]>>ds[i];
			vs[i] = ps[i]-ds[i];
			ss[i] = ps[i]+ds[i];
			i++;
		}
		
		cout<<"Jury #"<<t++<<endl; 
		solve();
		cin>>n>>m;
	}
	return 0;
}
