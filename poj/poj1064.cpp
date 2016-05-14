#include <stdio.h>
#define N 10005
typedef long long Long;

Long lengths[N];
Long totalLength = 0;

int main(){
	int n,k;
	float v;
	scanf("%d %d",&n,&k);
	Long maxLen = 0,minLen = 20000000000L;
	for(int i=0;i<n;i++){
		scanf("%f",&v);
		lengths[i] = (Long)(v*100);
		totalLength += lengths[i];
		if(lengths[i]>maxLen)	maxLen = lengths[i];
		if(lengths[i]<minLen)	minLen = lengths[i];
	}
	if(maxLen>totalLength/k)	maxLen = totalLength/k;
	Long low = minLen/(k/n+1),high = maxLen;
	Long preValid = 0;
	if(low<=0)	low = 1;
	int found = 0;
	while(low<=high){
		Long mid = low+(high-low)/2;
		Long cnt = 0;
		for(int i=0;i<n;i++){
			cnt+=lengths[i]/mid;
			if(cnt>=k)	break;
		}
		if(cnt>=k){
			low = mid+1;
			preValid = mid;
			found = 1;
		}else{
			high = mid-1;
		}
	}
	if(found)	printf("%.2f\n",preValid*1.0/100);
	else printf("0.00\n");
	return 0;
}
