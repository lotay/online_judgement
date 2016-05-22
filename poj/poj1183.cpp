#include <stdio.h>
//#include <math.h>
int main(){
	long long a;
	scanf("%lld",&a);
	long long aa = a*a+1;
	long long m = a;
	while(m>0){
		if(aa%m==0){
			break;
		}
		m--;
	}
	printf("%lld\n",a+a+m+aa/m);
	return 0;
}
