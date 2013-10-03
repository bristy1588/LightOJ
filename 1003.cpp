#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <string.h>
#define siz 20010
using namespace std;
map<string,int> mm;
vector<int>adj[siz];
int tot,indeg[siz],ct;
char s1[20],s2[20];
string ss1,ss2;
 
void BFS()
{
    int now,nx;
    tot=0;
    queue<int>q;
    for(int i=1;i<ct;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            tot++;
        }
    }
    while(!q.empty())
    {
        now=q.front(); q.pop();
        for(int i=0;i<adj[now].size();i++)
        {
            nx=adj[now][i];
            indeg[nx]--;
            if(indeg[nx]==0)
            {
                q.push(nx);
                tot++;
            }
 
        }
    }
    return;
}
int main()
{
    int t,tc,m,a,b,i;
    scanf("%d",&t);
    tc=0;
 
    while(tc<t)
    {
        tc++;
        ct=1;
 
        memset(indeg,0,sizeof(indeg));
        mm.clear();
 
        scanf("%d",&m);
        int k;
        k= m*2+2;
 
        for(i=1;i<k;i++)
            adj[i].clear();
 
 
        for(i=0;i<m;i++)
        {
 
            scanf("%s %s",s1,s2);
          //  printf("%s %s\n",s1,s2);
 
            ss1=s1;
            ss2=s2;
 
            if(mm.find(ss1)==mm.end())
            {
              mm[ss1]=ct;
              ct++;
            }
            if(mm.find(ss2)==mm.end())
            {
                mm[ss2]=ct;
                ct++;
            }
            a=mm[ss1];
            b=mm[ss2];
            indeg[b]++;
            adj[a].push_back(b);
        }
 
 
        BFS();
 
        if(tot==(ct-1))
        {
            printf("Case %d: Yes\n",tc);
        }
        else
        {
            printf("Case %d: No\n",tc);
        }
 
    }
 
    return 0;
}
 
