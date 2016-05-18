#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#define N 100000
#define M 1000
#define P 1007

using namespace std;

int counts[N];
int sumCnts[M];
char inValids[M][10];
int idx = 0;
char letter[100];
vector<int> indexs[P];

int primeNum[25] = {17, 37, 79, 163, 331, 673, 1361, 2729, 5471, 10949, 21911, 43853, 87719, 175447, 350899, 701819, 1403641, 2807303,
					5614657, 11229331, 22458671, 44917381, 89834777, 179669557, 359339171};//, 718678369, 1437356741, 2147483647 }; 

int hash(){
	int len = strlen(letter);
	int h = 1;
	for(int i=0;i<len;i++){
		h += letter[i]*primeNum[i%25];
		h %= P; 
	}
	return h;
}

void checkValid(){
	bool flag = 1;
	int h = hash();
	for(int i=0;i<indexs[h].size();i++){
		int j = indexs[h][i];
		if(strcmp(inValids[j],letter)==0){
			flag = 0;
			break;
		}
	}
	if(flag){
		strcpy(inValids[idx],letter);
		indexs[h].push_back(idx++);
	}
}

int toInt(char str[]){
	int res = 0;
	int len = strlen(str);
	if(len==5){
		for(int i=0;i<5;i++){
			char ch = str[i];
			if(ch>='0'&&ch<='9'){
				res = res * 10+ch-'0';
			}else{
				return 0;
			}
		}
	}
	return res;
}

int main(){
	memset(counts,0,N);
	memset(sumCnts,0,M);
	int k=0;
	int sum = 0,bundles = 0;
	while(scanf("%s\n",letter)!=EOF){
//		scanf("%s\n",letter);
		if(strlen(letter)==0){
			break;
		}
		int res = toInt(letter);
		if(res){
			counts[res]++;
			sumCnts[res/100]++;
			sum++;
		}else{
			checkValid();
		}
	}
	
	//
	printf("ZIP         LETTERS     BUNDLES\n\n");
	for(int i=0;i<M;i++){
		if(sumCnts[i]>=10){		
			for(int j=i*100;j<i*100+100;j++){
				if(counts[j]<10)	continue;
				if(counts[j]>=20){
					int bb = counts[j]/15+(counts[j]%15!=0);
					printf("%05d%12d%12d\n",j,counts[j],bb);
					sumCnts[j/100] -= counts[j];
					counts[j] = 0;
					bundles += bb;
				}else if(counts[j]<=15&&counts[j]>=10){
					printf("%05d%12d%12d\n",j,counts[j],1);
					sumCnts[j/100] -= counts[j];
					counts[j] = 0;
					bundles ++;
				}else if(counts[j]>15){
					printf("%05d%12d%12d\n",j,counts[j],1);
					sumCnts[j/100] -= 15;
					counts[j] -= 15;
					bundles ++;
				}
			}
		}
	}
	printf("\n");
	
	for(int i=0;i<M;i++){
		if(sumCnts[i]>=10){
			if(sumCnts[i]>=20){	
				int bb = sumCnts[i]/15+(sumCnts[i]%15!=0);
				printf("%03dxx%12d%12d\n",i,sumCnts[i],bb);
				sumCnts[i] = 0;
				bundles += bb;
			}else if(sumCnts[i]>=10&&sumCnts[i]<=15){
				printf("%03dxx%12d%12d\n",i,sumCnts[i],1);
				sumCnts[i] = 0;
				bundles ++;
			}else if(sumCnts[i]>=10){	
				printf("%03xx%12d%12d\n",letter,sumCnts[i],1);
				sumCnts[i] -= 15;
				int moved = 15;
				for(int j=i*100;j<i*100+100;j++){
					if(counts[j]){
						if(moved>counts[j]){
							moved -= counts[j];
							counts[j] = 0;
						}else{
							counts[j]-=moved;
							break;
						}	
					}
				}                         
				bundles ++;
			}			
		}
	}                            
	
	printf("\n");
	for(int i=0;i<M;i++){
		if(sumCnts[i]>0){
			for(int j=i*100;j<i*100+100;j++){
				if(counts[j]){
					printf("%05d%12d%12d\n",j,counts[j],0);
				}
			}
		}
	}
	
	printf("\nTOTALS%11d%12d\n\n",sum,bundles);
	printf("INVALID ZIP CODES\n\n");
	for(int i=0;i<idx;i++){
		printf("%s\n",inValids[i]);
	}
	
	return 0;
} 
