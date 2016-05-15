#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct{
	int s,e;
	int size;
	int earning;
	int maxEarning;
} Order;

Order orders[30];

int n,b,k;
int selects[10];

int comp(const void *a,const void *b){
	Order *o1 = (Order *)a;
	Order *o2 = (Order *)b;
	return o1->earning-o2->earning;
}

int res = 0;

void update(int s,int e, int ss){
	for(int j=s;j<e;j++){
		selects[j]+=ss;
	}
}

void solve(int i,int earning){
	for(int p=i;p<k;p++){
		if((earning+orders[p].maxEarning)<=res){
			break;
		}
		int ss = orders[p].size;
		bool flag = true;
		for(int j=orders[p].s;j<orders[p].e;j++){
			if(selects[j]+ss>n){
				flag = false;
				break;
			}
		}
		if(flag){
			int newEarning = earning+orders[p].earning;
			update(orders[p].s,orders[p].e,ss);
			if(newEarning>res)	
				res = newEarning;
			solve(p+1,newEarning);
			update(orders[p].s,orders[p].e,-ss);
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&b,&k);
	while(n||b||k){
		int i=0;
		for(;i<k;i++){
			scanf("%d %d %d",&orders[i].s,&orders[i].e,&orders[i].size);
			orders[i].earning = orders[i].size*(orders[i].e-orders[i].s);
		}
		
		qsort(orders,k,sizeof(Order),comp);
		
		for(i=0;i<b;i++){
			selects[i] = 0;
		}
		
		int sum = 0;
		for(i=k-1;i>=0;i--){
			sum += orders[i].earning;
			orders[i].maxEarning = sum;
		}
		res = 0;
		solve(0,0);
		
		printf("%d\n",res);
		
		scanf("%d %d %d",&n,&b,&k);
	}
}
