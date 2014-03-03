/*
    Week 18, Day 2: March 2, 2014
    Light OJ Practise
*/
#include <iostream>
#include <string.h>
#include <map>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define     x           first
#define     y           second
#define     SET(a,b)    memset(a, b, sizeof(a))
#define     mp          make_pair
using namespace std;
char s[55][55];
int N,M;
typedef pair<int, int> pii;
int ar[]={-1,0,1,0};
int ac[]={0,1,0,-1};
int rigon[55][55], cmp;
vector <int> v;

void BFS(int si, int sj)
{
    int i,rw,cl;
    pii cur;

    queue <pii > q;
    q.push(mp(si,sj));
    rigon[si][sj] = cmp;

    while(!q.empty()){
        cur = q.front(); q.pop();

        for(i = 0; i < 4; i++){
            rw = ar[i] + cur.x;
            cl = ac[i] + cur.y;

            if(rw<0 || rw>= M+2 || cl<0 || cl >=N+2) continue;
            if(rigon[rw][cl] != -1 || s[rw][cl] != s[si][sj]) continue;
            rigon[rw][cl]  = cmp;
            q.push(mp(rw,cl));

        }

    }

    return;
}
bool vis[55][55];
int mark[55*55];
int block;
int par[55*55];
char rec[55*55];
int parent(int a){

    if(par[a] == a) return a;

    par[a] = parent(par[a]);
    return par[a];

}
void FLOOD()
{
    int i,rw,cl; pii cur;

    queue<pii > q;
    q.push(mp(0,0));
    memset(vis,false, sizeof(vis));
    memset(mark, false, sizeof(mark));
    vis[0][0] = true;

    while(!q.empty()){
        cur = q.front(); q.pop();

        for(i = 0; i < 4; i++){
            rw = ar[i] + cur.x;
            cl = ac[i] + cur.y;

            if(rw<0 || rw>= M+2 || cl<0 || cl >=N+2) continue;
            if(vis[rw][cl] == true || rigon[rw][cl] == block) continue;
            vis[rw][cl] = true;
            mark[rigon[rw][cl]] = true;
            q.push(mp(rw,cl));
        }
    }
    int py,px;
    py = parent(block);

    for(i = 0; i < cmp; i++){
        if(mark[i] == true) continue;
        px = parent(i);
        if(px == py) continue;
        par[px] = py;
    }

    return;
}

char str[55];

int main(){

    int T,tc,i,j;


    cin >> T;
    tc = 0;
    while(tc< T){
        tc++;
        cin >> M >> N;

        for(i = 0; i < M +2 ; i++)
            for(j = 0 ; j < N+ 2; j++)
                s[i][j] = '.';

        for(i = 0; i < M ; i++){
            scanf("%s",str);
            for(j = 0; j < N ; j++){
                s[i+1][j+1] = str[j];
            }
        }

        SET(rigon, -1);
        cmp = 0;
        for(i = 0; i < M+2; i++){
            for(j = 0; j < N+2; j++){
                if(rigon[i][j] != -1 ) continue;
                rec[cmp] = s[i][j];
                BFS(i,j);
                cmp++;
            }
        }


        for(i = 0; i < cmp; i++)
            par[i] = i;

        for(i = 0; i < cmp; i++){
            if(rec[i] == '.') continue;
            block = i;
            FLOOD();
        }

        int id;
        printf("Case %d:\n",tc);

        for(i = 1; i < M+1; i++){
            for(j = 1; j < N+1; j++){
                id =parent(rigon[i][j]);
                s[i][j] = rec[id];
                printf("%c",s[i][j]);
            }
            printf("\n");
        }



    }

    return 0;
}

