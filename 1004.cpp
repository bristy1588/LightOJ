#include <iostream>
#include <stdio.h>
#include <string.h>
#define siz 210
using namespace std;
int ar[siz][siz],dp[siz][siz];
int DP(int r,int c)
{
    if(dp[r][c]!=(-1))
        return dp[r][c];
    int a,b;
 
    a=DP(r+1,c);
    b=DP(r+1,c+1);
    dp[r][c]=max(a,b)+ar[r][c];
 
    return dp[r][c];
 
}
int main()
{
    int t,tc,n,i,j,cl,R,ans;
    scanf("%d",&t);
    tc=0;
    while(tc<t)
    {
        tc++;
        scanf("%d",&n);
        memset(ar,0,sizeof(ar));
 
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
                scanf("%d",&ar[i][j]);
        }
        R=2*n-1;
        cl=0;
        for(i=n;i<R;i++)
        {
            cl++;
            for(j=0;j<n;j++)
            {
                if((j+cl)==n)
                    break;
                scanf("%d",&ar[i][j+cl]);
            }
        }
 
        memset(dp,-1,sizeof(dp));
        for(i=0;i<=R;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(ar[i][j]==0)
                    dp[i][j]=0;
            }
        }
        dp[R-1][n-1]=ar[R-1][n-1];
 
        ans=DP(0,0);
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
