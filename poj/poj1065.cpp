#include <iostream>
#include <vector>
#include <algorithm>

#define N 6000

using namespace std;

typedef struct Stick{
	int w;
	int l;
} Stick;


int indexs[N];
Stick sticks[N];

int comp(const void *t1, const void *t2){
	Stick &s1 = *((Stick*)t1);
	Stick &s2 = *((Stick*)t2);
	if (s1.l!=s2.l)	return s1.l-s2.l;
	return s1.w-s2.w;
}

bool lessThan(int a,int b){
	return sticks[a].l<=sticks[b].l&&sticks[a].w<=sticks[b].w; 
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>sticks[i].l>>sticks[i].w;
		}
		qsort(sticks,n,sizeof(Stick),comp);
		int t = 0;
		int i=0;
		while(i<n){
			bool found = false;
			for(int j=0;j<t;j++){
				if(lessThan(indexs[j],i)){
					found = true;
					indexs[j] = i;
					break;
				}
			}
			if(!found)	indexs[t++]=i;
			i++;
		}		
		cout<<t<<endl;	
	}
	return 0;
}
