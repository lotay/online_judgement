#include <iostream>
#include <vector>

int maxDiff()

int main(){
	int w;
	cin>>w;
	while(w>0){
		int pix,len;
		vector<int> values;
		vector<int> tmpLens;
		int preDiffLen = 0, preDiffVal = -1;
		int preIndex = 0,curIndex = 0;
		while(cin>>pix>>len){
			if(pix==0&&len==0){
				break;
			}
			while(len>0&&values.size()<=w){
				values[preIndex++] = pix;
				tmpLens.push_back(0);
				len--;
			}
			if(len<2*w){
				
			}
		}
		
		cin>>w;
	}
	return 0;
} 
