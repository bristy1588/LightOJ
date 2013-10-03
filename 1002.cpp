#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#define sz 502
#define inf 1000000000
using namespace std;
int cst[sz][sz];
int cost[sz],vis[sz],n;
void DIJKSTRA(int s)
{
    int i,nxt;
 
    for(i=0;i<n;i++)
    {
        vis[i]=0;
        cost[i]=-1;
    }
    cost[s]=0;
 
    priority_queue<pair<int,int> >pq;
    pair<int,int> cur;
        pq.push(make_pair(-0,s));
    while(!pq.empty())
    {
        cur=pq.top(); pq.pop();
        if(vis[cur.second]==1)
            continue;
        vis[cur.second]=1;
        for(i=0;i<n;i++)
        {
            if(cst[cur.second][i]>20000)
                continue;
            nxt=max(cst[cur.second][i],cost[cur.second]);
            if(nxt<cost[i] || cost[i]==(-1))
            {
                cost[i]=nxt;
                pq.push(make_pair(-cost[i],i));
            }
        }
    }
    return;
}
int main()
{
    int t,tc,m,u,v,w,i,s;
    scanf("%d",&t);
    tc=0;
    while(tc<t)
    {
        tc++;
 
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cst[i][j]=inf;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            cst[u][v]=min(cst[u][v],w);
            cst[v][u]=cst[u][v];
        }
        scanf("%d",&s);
 
        DIJKSTRA(s);
        printf("Case %d:\n",tc);
        for(i=0;i<n;i++)
        {
            if(cost[i]==(-1))
                printf("Impossible\n");
            else
                printf("%d\n",cost[i]);
        }
 
    }
 
    return 0;
}
