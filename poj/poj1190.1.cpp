#include <iostream>
#include <cmath>
using namespace std;
const int INTMAX = 1000000000; 
int n,m,res=INTMAX;

int minV[21];
int minA[21];

void DFS( int lv,int r,int h,int s ,int dp ){
    int mr,mh,i,j;
    if( minV[dp]>lv )
        return;
    if( minA[dp]+s>res )
        return;
    if( dp==0 ){
        if( lv==0 )
            res=s;
        return;
    }
    if( res<s+2*lv/( r-1 ) )
        return;
    mr=sqrt( ( lv-minV[dp-1] )/dp );
    mr=mr>=r?r-1:mr;
    for( i=mr;i>=dp;i-- ){
        mh=( lv-minV[dp-1])/i/i;
        mh=mh>=h?h-1:mh;
        for( j=dp;j<=mh;j++ )
            DFS( lv-i*i*j,i,j,s+2*i*j,dp-1 );
    }
}
void init(){
	minA[0] = 0;
	minV[0] = 0;
	for(int i=1;i<21;i++){
		minA[i] = minA[i-1]+i*i*2;
		minV[i] = minV[i-1]+i*i*i;
	}
}

int main( void ){
    int mr,mh,i,j;
    cin>>n>>m;
    init();
    mr=sqrt( (n-minV[m-1])/m );
    for( i=mr;i>=m;i-- ){
        mh=(n-minV[m-1])/i/i;
        for( j=m;j<=mh;j++ )
            DFS( n-i*i*j,i,j,i*i+2*i*j,m-1 );
    }
    if( res==INTMAX )
        cout<<0<<endl;//( "0\n" );
    else
        cout<<res<<endl;;
}
