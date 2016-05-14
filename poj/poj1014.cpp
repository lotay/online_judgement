#include <iostream>

using namespace std;
int dp[181][7];
int main(){
	int n1,n2,n3,n4,n5,n6;
	cin>>n1>>n2>>n3>>n4>>n5>>n6;
	int t = 1;
	while(n1||n2||n3||n4||n5||n6){
		if(n1>60)	n1 = n1%60;
		if(n2>30)	n2 = n2%30;
		if(n3>20)	n3 = n3%20;
		if(n4>15)	n4 = n4%16;
		if(n5>12)	n5 = n5%12;
		if(n6>10)	n6 = n6%10; 
		
		int sum = n1+2*n2+3*n3+4*n4+5*n5+6*n6;
		cout<<"Collection #"<<t++<<":"<<endl;
		if(sum%2==1){
			cout<<"Can't be divided.\n"<<endl;
		}else{
			dp[0][0] = n1;
			dp[0][1] = n2;
			dp[0][2] = n3;
			dp[0][3] = n4;
			dp[0][4] = n5;
			dp[0][5] = n6;
			dp[0][6] = 1;
			for(int i=1;i<=sum/2;i++){
				dp[i][6] = 0;
				for(int j=1;j<=6;j++){
					if(i-j>=0&&dp[i-j][6]&&dp[i-j][j-1]){
						dp[i][6] = 1;
						for(int k=0;k<6;k++){
							dp[i][k] = dp[i-j][k];
						}
						dp[i][j-1]--;
						break;
					}
				}
			}
			if(dp[sum/2][6]){
				cout<<"Can be divided.\n"<<endl;
			}else{
				cout<<"Can't be divided.\n"<<endl;
			}
		}
		cin>>n1>>n2>>n3>>n4>>n5>>n6;
	}
	return 0;
}
