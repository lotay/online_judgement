#include <iostream>
#include <algorithm>

using namespace std;
typedef struct{
	int s;
	int e;
} Interval;

int comp(const void *a,const void *b){
	if(((Interval*)a)->s==((Interval*)b)->s) return ((Interval*)a)->e-((Interval*)b)->e;
	return ((Interval*)a)->s - ((Interval*)b)->s;
}

Interval intervals[50000];
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int main(){
	int n;
	cin>> n;
	int i=0;
	while(i<n){
		cin>>intervals[i].s>>intervals[i].e;
		i++;
	}
	
	qsort(intervals,n,sizeof(Interval),comp);
	int j = 0;
	for(i=1;i<n;i++){
		if(intervals[i].s<=intervals[j].e){
			intervals[j].e = max(intervals[j].e,intervals[i].e);
		}else{
			intervals[++j] = intervals[i];
		}
	}
	for(i=0;i<=j;i++){
		cout<<intervals[i].s<<" "<<intervals[i].e<<endl;
	}
	return 0;
}
