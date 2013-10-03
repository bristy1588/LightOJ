#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std ;
                                /*
                                Online Judge  : Light OJ
                                Problem Name  :
                                Problem Number:
                                Date          : June 10,2012
                                */
 
int n;
unsigned long long dp[50][1000];
int chk[50];
unsigned long long DP(int r, int k)
{
    long long ans;
    int i;
    if(k==0)
        return 1;
    if(r==n)
        return 0;
 
    if(dp[r][k]!=(-1))
        return dp[r][k];
 
    ans=0;
 
    ans+=DP(r+1,k);
 
    for(i=0;i<n;i++)
    {
        if(chk[i]!=1)
        {
            chk[i]=1;
            ans+=DP(r+1,k-1);
            chk[i]=0;
        }
    }
 
    dp[r][k]=ans;
    return dp[r][k];
}
int main()
{
    int t,tc,i,j,cl,k;
   unsigned long long ans;
    scanf("%d",&t);
    tc=0;
    while(tc<t)
    {
        tc++;
        scanf("%d %d",&n,&k);
 
        memset(dp,-1,sizeof(dp));
        memset(chk,0,sizeof(chk));
       
        ans=DP(0,k);
        printf("Case %d: ",tc);
        cout<<ans;
        printf("\n");
    }
    return 0;
}
