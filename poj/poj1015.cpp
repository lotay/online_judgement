#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool dp[4000+1][21][202];
int cnts[4001][21][2];
int n,m;
typedef struct{
	int p;
	int d;
	int idx;
} Member; 
Member members[200];

int comp(const Member&m1,const Member&m2){
	if((m1.p-m1.d)!=(m2.p-m2.d))return (m1.p-m1.d)-(m2.p-m2.d);
	return (m1.p+m1.d)-(m2.p+m2.d);
}

int abs(int a,int b){
	if(a<b)	return b-a;
	return a-b;
}

void helper(int low,int above,int sum1,int sum2){
	for(int i=0;i<4000;i++)
		for(int j=0;j<21;j++){
			for(int k=0;k<202;k++) 	dp[i][j][k] = 0;
			for(int k=0;k<2;k++)	cnts[i][j][k] = 0;
		}
	dp[0][0][200] = dp[0][0][201] = 1;
	for(int i=1;i<=sum1;i++){
		for(int j=1;j<=m;j++){
			int maxK = -1;
			for(int k=0;k<low;k++){
				Member &t = members[k];
				if(i-(t.d-t.p)>=0&&dp[i-(t.d-t.p)][j-1][200]&&!dp[i-(t.d-t.p)][j-1][k]){
					if(maxK<0||cnts[i-(t.d-t.p)][j-1][0]+t.p+t.d>
						cnts[i-(members[maxK].d-members[maxK].p)][j-1][0]
						+members[maxK].p+members[maxK].d)	{
						maxK = k;
					}
				}
			}
			if(maxK>=0){
				dp[i][j][200] = 1;
				for(int k=0;k<low;k++){
					dp[i][j][k] = dp[i-members[maxK].d+members[maxK].p][j-1][k];
				}
				cnts[i][j][0] = cnts[i-members[maxK].d+members[maxK].p][j-1][0]
								+members[maxK].d+members[maxK].p;
				dp[i][j][maxK] = 1;
			}
		}
	}
	
	for(int i=1;i<=sum2;i++){
		for(int j=1;j<=m;j++){
			int maxK = -1;
			for(int k=above;k<n;k++){
				Member &t = members[k];
				if(i-(t.p-t.d)>=0&&dp[i-(t.p-t.d)][j-1][201]&&!dp[i-(t.p-t.d)][j-1][k]){
					if(maxK<0||cnts[i-(t.d-t.p)][j-1][1]+t.p+t.d>
						cnts[i-(members[maxK].d-members[maxK].p)][j-1][1]
						+members[maxK].p+members[maxK].d)	maxK = k;
				}
			}
			if(maxK>=0){
				dp[i][j][201] = 1;
				for(int k=0;k<low;k++){
					dp[i][j][k] = dp[i-members[maxK].d+members[maxK].p][j-1][k];
				}
				cnts[i][j][1] = cnts[i-members[maxK].p+members[maxK].d][j-1][1]
								+members[maxK].p+members[maxK].d;
				dp[i][j][maxK] = 1;
			}
		}
	}
	int total = 0;
	int zero = 0;
	int delta = 400000;
	int sum = 0;
	int tj = -1;
	int t1 = -1,t2 = -1;

	for(int i=0;i<=above-low;i++){
		total +=i==0?0:(members[above-i].p+members[above-i].d);
		for(int j=0;j<=m-i;j++){
			int j2 = m-j-i;
			for(int k1=0;k1<=sum1;k1++){
				for(int k2 = 0;k2<=sum2;k2++){
					if(dp[k1][j][200]&&dp[k2][j2][201]){
						if(delta>abs(k1,k2)
							||(delta==abs(k1,k2)&&sum<cnts[k1][j][0]+cnts[k2][j2][1]+total)){
							tj = j;
							zero = i;
							delta = abs(k1,k2);
							t1 = k1;
							t2 = k2;
							sum=cnts[k1][j][0]+cnts[k2][j2][1]+total; 
						}
					}
				}
			} 
		}
	}
	int totalP=0,totalD = 0;
	vector<int> indexs;
	for(int i=0;i<zero;i++){
		indexs.push_back(members[above-i-1].idx);
		totalP+= members[above-i-1].p;
		totalD+= members[above-i-1].d;
	}
	for(int i=0;i<low;i++){
		if(dp[t1][tj][i]){
			indexs.push_back(members[i].idx);
			totalP+= members[i].p;
			totalD+= members[i].d;
		}
	}
	for(int i=above;i<n;i++){
		if(dp[t2][m-zero-tj][i]){
			indexs.push_back(members[i].idx);
			totalP+= members[i].p;
			totalD+= members[i].d;

		}
	}
	cout<<"Best jury has value "<<totalP<<" for prosecution and value "
		<<totalD<<" for defence:"<<endl;
	sort(indexs.begin(),indexs.end());
	for(int i=0;i<indexs.size();i++)	cout<<" "<<indexs[i]+1 ;
	cout<<endl<<endl;
}

int main(){
	cin>>n>>m;
	int t = 1;
	while(n!=0||m!=0){
		int t1,t2;
		int i=0;
		while(i<n){
			cin>>t1>>t2;
			members[i].p = t1;
			members[i].d = t2;
			members[i].idx = i;
			i++;
		}
		
		cout<<"Jury #"<<t++<<endl; 
		
		for(int i=0;i<n-1;i++){
			int min = i;
			for(int j=i+1;j<n;j++){
				if(comp(members[i],members[j])>0){
					min = j;
				}
			}
			//swap.
			if(min!=i){
				Member t = members[min];
				members[min] = members[i];
				members[i] = t;
			}
		}
		int low = -1,above = -1;
		int sum1 = 0, sum2=0;
		for(int i=0;i<n;i++){
			if(members[i].p<members[i].d){
				sum1 += members[i].p-members[i].d;
			}else if(members[i].p>members[i].d){
				sum2 += members[i].p-members[i].d;
			}
			if(low<0&&members[i].p>=members[i].d){
				low = i;
			}
			if(above<0&&members[i].p>members[i].d){
				above = i;
			}
		}
		helper(low,above,-sum1,sum2);
		cin>>n>>m;
	}
	return 0;
}
