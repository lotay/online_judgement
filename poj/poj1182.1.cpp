#include<stdio.h>
#include<string.h>
int delta[50005],fa[50005];
int n,k;
void init(){
    for(int i=1;i<=n;i++){
        delta[i]=0;
        fa[i]=i;
    }
}
int find(int x){
     if(x==fa[x]) return x;
     int tx=find(fa[x]);
	delta[x]=(delta[x]+delta[fa[x]])%3;//�ؼ�
     return fa[x]=tx;
}
int unio(int x,int y,int type){
     if(x>n||y>n) return 1;
     if(type==1&&x==y) return 1;
     int tx=find(x);
     int ty=find(y);
     if(tx==ty){
            if((delta[y]-delta[x]+3)%3!=type)//Ҳ��������˼ά˼�������ֶ��ﶼ�ڼ������ˣ��ж�һ���Ƿ�������Ļ���һ��
//x->y=x->tx+ty->y,��Ϊtx=ty�������ڵ���ͬ������x��y�Ĺ�ϵ��ʾΪ(-delta[x]+delta[y]+3)%3,��type�Ƚϼ���
               return 1;
            else return 0;
     }
     else  {
        fa[ty]=tx;
        delta[ty]=(delta[x]-delta[y]+type+3)%3;//�ؼ�
        return 0;
     }
}
int main(){
    int type;
    int i,wrong,x,y;
    while(scanf("%d%d",&n,&k)==2){
        wrong=0;
    init();
    for(i=1;i<=k;i++){
         scanf("%d%d%d",&type,&x,&y);
         if(unio(x,y,type-1))
             wrong++;
    }
    printf("%d\n",wrong);
    }
    return 0;
}
