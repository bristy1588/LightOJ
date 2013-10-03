//June 09,2012
#include <iostream>
#include <math.h>
#include <stdio.h>
#define md 10000007
#define sz 10010
using namespace std;
double R,r,pi;
int n,t,tc;
int fn[sz];
int ABS(int a)
{
    if(a<0)
        return -a;
    return a;
 
}
int main()
{
    int n,i,l,ans;
    scanf("%d",&t);
    tc=0;
    while(tc<t)
    {
       tc++;
      for(i=0;i<6;i++)
      {
        scanf("%d",&fn[i]);
        fn[i]=fn[i]%md;
      }
 
    scanf("%d",&n);
 
    for(i=6;i<=n;i++)
    {
        fn[i]=(fn[i-1] + fn[i-2] + fn[i-3] + fn[i-4] + fn[i-5] + fn[i-6])%md;
    }
    printf("Case %d: %d\n",tc,fn[n]);
 
    }
    return 0;
}
