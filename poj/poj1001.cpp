#include<stdio.h>
#include<string.h>
#include<math.h>
int m,n;
int a[300],b[300];
void sou()
{
    int i,j,r[50000];
    int max,leap;
    memset(r,0,sizeof(r));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            r[i+j]=r[i+j]+a[i]*b[j];
        }
    }
    max=n+m-1;
    leap=0;
    for(i=0;i<max;i++)
    {
        r[i]=r[i]+leap;
        leap=r[i]/10;
        r[i]=r[i]%10;
    }
    if(leap!=0)
    r[i]=leap,max++;
    for(i=max-1;i>=0;i--)
    {
        a[i]=r[i];
    }
    n=max;
}
int main()
{
    int t,i,leap,j,leapp,cas;
    char str[1000];
    while(scanf("%s%d%*c",str,&t)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        n=strlen(str);
        j=0;
        cas=0;
        leapp=0;
        leap=0;
        for(i=n-1;i>=0;i--)
        {
            if(str[i]=='.')
            {
                leap=i;cas++;
                continue;
            }
            cas+=str[i]-'0';
            if(cas==0)leapp++;
            a[j]=str[i]-'0';
            b[j]=str[i]-'0';
            j++;
        }
        if(leap!=0)
        {
            for(i=0;i<j-leapp;i++)
            {
                a[i]=a[i+leapp];
                b[i]=b[i+leapp];
            }
            j=j-leapp;
        }

        m=n=j;
        if(leap!=0)
            leap=n-leap;
        leap=leap*t;
        for(i=1;i<t;i++)
        {
            sou();
        }
        cas=0;leapp=0;
        for(i=0;i<n;i++)
        {
            cas+=a[n-i-1];
            if(leap!=0&&n-i==leap)
            {
                printf(".");
                leapp=1;
            }
            if(cas!=0||leapp!=0)
                printf("%d",a[n-i-1]);
        }
        if(cas==0)
        printf("0");
        printf("\n");
    }
    return 0;
}
