#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{
    int t,tc,a,b;
 
    scanf("%d",&t);
    tc=0;
    while(tc<t)
    {
      scanf("%d %d",&a,&b);
      printf("Case %d: %d\n",tc+1,a+b);
      tc++;
    }
    return 0;
}
