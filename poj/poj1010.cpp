#include <iostream>
using namespace std;
 
int fs[10000][5][6];
int vs[10000];
int ts[10000];
int main(int argc,char **argv){
	while(cin){
		int v = 0;
		int n = 0,m = 0,max = 0;
		while(1){
			cin>>v;
			if(v==0)	break;
			vs[n++] = v;
		}
		if(n==0){
			break;
		}
		while(1){
			cin>>v;
			if(v==0)	break;
			ts[m++] = v;
			if(v>max) max = v;
		}
		for(int i=0;i<=max;i++){
			for(int j=0;j<5;j++){
				for(int k=0;k<6;k++){
					fs[i][j][k] = -1;
				}
			}
		}
		for(int i=1;i<=max;i++){
			for(int k=0;k<n;k++){
				if(vs[k]==i){
					fs[i][1][0] = k;
					fs[i][1][4] = 1;
					fs[i][1][5] = vs[k];
				}
			}
			for(int j=2;j<=4;j++){
				int typCnt = -1;
				int maxK = -1;
				int maxV = -1;
				for(int k=0;k<n;k++){
					if(i>vs[k]&&fs[i-vs[k]][j-1][4]>0){
						int cntType = fs[i-vs[k]][j-1][4];
						int val = vs[k];
						int flag = 1;
						for(int l=0;l<j-1;l++){
							if(fs[i-vs[k]][j-1][l]<0) continue;
							if(flag&&fs[i-vs[k]][j-1][l]==k)flag = 0;
							if(vs[fs[i-vs[k]][j-1][l]]>val) val = vs[fs[i-vs[k]][j-1][l]];
						}
						if(cntType>typCnt){
							typCnt = cntType+flag;
							maxK = k;
							maxV = val;
						}
					}
				}
				if(typCnt>0){
					fs[i][j][4] = typCnt;
					fs[i][j][5] = maxV;
					for(int l=0;l<j-1;l++){
						fs[i][j][l]	= fs[i-vs[maxK]][j-1][l];
					}
					fs[i][j][j-1]=maxK;
				}
			}
		}
		for(int l=0;l<m;l++){
			cout<<ts[l]<<" ";
			int tj=4;
			for(int j=3;j>=1;j--){
				if(fs[ts[l]][j][4]>=fs[ts[l]][tj][4]){
					tj = j;
				}
			}
			if(fs[ts[l]][tj][4]>0){
				cout<<"("<<fs[ts[l]][tj][4]<<"):";
				int cnt = 0;
				for(int k=0;k<tj;k++){
					if(fs[ts[l]][tj][5]==vs[fs[ts[l]][tj][k]]){
						int tmp =0;
						for(int p=0;p<tj;p++){
							tmp+=fs[ts[l]][tj][p]==fs[ts[l]][tj][k];
						}
						if(tmp>1){
							cnt = 1;
							break;
						}
					}
				}
				
				if(cnt){
					cout<<" tie";
				}else{
					for(int k=tj-1;k>=0;k--){
						cout<<" "<<vs[fs[ts[l]][tj][k]];
					}
				}
				cout<<"\n";
			}else{
				cout<<"---- none\n";
			}
		}
	}
}
