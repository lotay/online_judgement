		#include <stdio.h>
		
		int abs(int v){
			if(v<0)	return -v;
			return v;
		}
		
		int main(){
			int t,n,b;
			scanf("%d",&t);
			while(t--){
				scanf("%d",&n);
				int p=0,q=0;
				for(int i=0;i<n;i++){
					scanf("%d",&b);
					if(i&1){
						p += b;
					}else{
						q += b;
					}
				}
				if(n%2||abs(p-q)<2){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}
		}
