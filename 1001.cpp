#include<stdio.h>
int tc,t,n,k;
int main()
{
    scanf("%d",&t);
    tc=0;
    while(tc<t)
    {
        tc++;
        scanf("%d",&n);
        k=0;
        if(n>10)
        {
            k=n-10;
            n=10;
        }
        printf("%d %d\n",k,n);
    }
    return 0;
}
 
