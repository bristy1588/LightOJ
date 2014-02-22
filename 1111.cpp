/*
    Day 5: Feb 22, 2014
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>
#define     pb          push_back
#define     SET(a,b)    memset(a,b, sizeof(a))
#define     Z           1003

using namespace std;
bool vis[Z];
vector<int> v[Z];
int K,pip[Z];
inline bool solve(int s){

    queue<int> q;

    SET(vis,false);
    vis[s] = true;
    q.push(s);

    int i,cur, now;

    while(!q.empty()){
        cur = q.front(); q.pop();

        for(i = 0; i < v[cur].size(); i++){
            now = v[cur][i];
            if(vis[now]==true) continue;
            vis[now] = true;
            q.push(now);
        }
    }

    bool flag;

    flag = true;
    for(i = 0; i < K; i++){
        if(vis[pip[i]]==false)
            flag = false;
    }
    return flag;
}
int main()
{
    int T,tc,i,N,M;

    cin >> T;
    tc = 0;

    while(tc<T){
        tc++;

        cin >> K >> N>> M;

        for(i = 0; i <K ; i++) cin >> pip[i];

        for(i = 0; i <= N; i++)
            v[i].clear();
        int x,y,ans;

        for(i = 0; i < M ; i++){
            cin >> x >> y;
            v[y].pb(x);
        }

        ans= 0;
        for(i = 1; i <= N; i++){
            if( solve(i)==true) ans++;
        }

        printf("Case %d: %d\n",tc,ans);

    }
    return 0;
}
