#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

int size[100];
int data[100][100][2];
int minPrices[100][100];
int n; 
int indexs[100];

int cmp(const void *a , const void *b){
	return *(int *)a - *(int *)b; 
}
int main(){
	int t;
	cin>>t;
	cout.setf(ios::fixed);
	while(t-->0){
		cin>>n;
//		int minIndex = 0;
		int sumPrice = 0;
		for(int i=0;i<n;i++){
			cin>>size[i];
			for(int j=0;j<size[i];j++){
				cin>>data[i][j][0]>>data[i][j][1];
			}
			qsort(data[i],size[i],2*sizeof(int),cmp);
			int minPrice = data[i][size[i]-1][1];
			for(int j=size[i]-1;j>=0;j--){
				if(minPrice>data[i][j][1])	minPrice = data[i][j][1];
				minPrices[i][j] = minPrice;
//				cout<<data[i][j][0]<<" "<<data[i][j][1]<<" "<<minPrices[i][j]<<endl;
			}
//			if(data[i][0][0]<data[minIndex][0][0])	minIndex = i;
			indexs[i] = 0;
//			cout<<"data[i][0][1]:"<<data[i][0]<<endl;
			sumPrice += minPrices[i][0];
		}
		double res = 0;
		while(true){
			int minDW = data[0][indexs[0]][0];
			for(int i=0;i<n;i++){
				if(data[i][indexs[i]][0]<minDW){
					minDW = data[i][indexs[i]][0];
				}
			}
//			cout<<"min:"<<minDW<<endl;
			if(1.0*minDW/sumPrice>res){
				res = 1.0*minDW/sumPrice;
			}
			bool flag = false;
			for(int i=0;i<n;i++){
				if(data[i][indexs[i]][0]==minDW){
					sumPrice -= minPrices[i][indexs[i]];
//					cout<<"equal:"<<i<<":"<<data[i][indexs[i]][0]<<endl;
					indexs[i]++;
					if(indexs[i]>=size[i]){
						flag = true;
						break;
					}
					sumPrice += minPrices[i][indexs[i]];
				}
//				cout<<"minIndex("<<i<<"):"<<indexs[i]<<",sumPrice:"<<sumPrice<<endl;
			}
			if(flag)	break;
		}
		cout<<setprecision(3)<<res<<endl;
	}
}
