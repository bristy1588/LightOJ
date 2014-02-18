/*
    February 18, 2014
    Day 2
    Easy DP
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define     inf     1000000009
#define     pb      push_back
using namespace std;
int N;
int dp[320][30], rec[320][30], t[30], d[30], f[30];

int DP(int left, int at){


    if(left == 0 || at==N) return 0;
    if(left<0) return -inf;

    int &ret = dp[left][at];
    int &kip = rec[left][at];

    if(kip != -1) return ret;

    ret = max( 0,DP(left - t[at+1], at+1));
    kip = 0;
    int fish,hr,now,tot = 0;
    for(fish = f[at], hr = 1; hr <= left; fish -=d[at], hr++){
        tot = max(fish,0) + tot;
        now = DP(left - hr - t[at+1], at+1)+ tot;
        if(hr==left) now = DP(0,at+1) + tot;
        if(now >=ret){
            ret = now;
            kip = hr;
        }
    }

    return ret;
}
vector<int> v;

void PATH(int left, int at){
    if(left<=0 || at==N) return;

    v.pb(rec[left][at]);

    PATH(left - rec[left][at] -t[at+1], at+1);
    return;
}

int main()
{
    int T, tc, H,i,ans;

    cin >> T;
    tc = 0;

    while(tc<T){
        tc++;


        cin>>N>> H;
        H*=12;

        for(i = 0; i < N; i++)  cin>> f[i];
        for(i = 0; i < N; i++)  cin>> d[i];
        for(i = 1; i < N; i++)  cin>> t[i];

        memset(dp,-1, sizeof(dp));
        memset(rec, -1, sizeof(rec));
        v.clear();

        ans = DP(H,0);
        PATH(H,0);

        printf("Case %d:\n",tc);

        // Path Printing
        for(i = v.size(); i < N; i++)
            v.pb(0);

        for(i  = 0; i < v.size(); i++){
            v[i] = v[i]*5;
            if(i!=0) printf(", ");
            printf("%d",v[i]);
        }
        printf("\n");

        printf("Number of fish expected: %d\n",ans);

    }

    return 0;
}
