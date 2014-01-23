/*
    Date    : 23 Jan, 2014
    Problem : Light OJ 1155 Power Transmission
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#define     inf     1000006
#define     sz      210
using namespace std;
int source, sink,par[sz], c[sz][sz], N;
bool vis[sz];

int BFS()
{
    int pathcap, tot, i, cur, now;

    queue<int> q;
    pathcap = inf;
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));

    vis[source] = true;
    q.push(source);
    tot = 2*N + 2;
    while(!q.empty())
    {
        cur = q.front(); q.pop();
        if(cur== sink) break;

        for(i = 0; i <tot; i++){
            if(vis[i] || c[cur][i]<= 0) continue;
            par[i] = cur;
            vis[i] = true;
            q.push(i);
        }
    }
    int prv;

    now = sink;
    while(par[now] > -1){
        prv = par[now];
        pathcap = min(pathcap, c[prv][now]);
        now = prv;
    }

    now = sink;
    while(par[now] > -1){
        prv = par[now];
        c[prv][now] -= pathcap;
        c[now][prv] += pathcap;
        now = prv;
    }

    if(pathcap== inf) pathcap = 0;

    return pathcap;
}
int max_flow()
{
    int ans,flow;

    ans = 0;

    while(1){
        flow = BFS();
        if(flow == 0) break;
        ans+= flow;
    }

    return ans;
}

int main()
{
    int t, tc, i, a,b,cap;

    scanf("%d",&t);
    tc = 0;
    while(tc<t){
        tc++;
        memset(c, 0, sizeof(c));
        cin>>N;
        for(i = 0; i < N; i++){
            cin>>a;
            c[i][i+N] +=a;
        }

        int M,B,D;

        cin>>M;

        for(i = 0; i < M; i++){
            cin>>a>>b>>cap;
            a--; b--;
            c[a+N][b] += cap;
        }

        cin>> B>> D;
        source = 2*N;
        sink = 2*N+1;
        for(i =0; i < B; i++){
            cin>>a;
            a--;
            c[source][a] += inf;
        }

        for(i = 0; i < D; i++){
            cin>>a;
            a--;
            c[a+N][sink] += inf;
        }

      int  ans = max_flow();
        printf("Case %d: %d\n",tc,ans);

    }

    return 0;
}
