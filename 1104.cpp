/*
    February 18, 2014
    Day 2
          বাচ্চাদের প্রব্লেম। :D
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>
#define     inf     1000000009
#define     pb      push_back
#define     Z       100005
#define     eps     1e-9
using namespace std;
int N;



int main()
{
    int T,tc,lo,hi,i,mid;

    cin >> T;
    tc = 0;
    while(tc< T)
    {
        tc++;

        cin>> N;
        double ans = 1.0;
        for(i = 0; i < N+2; i++){
            ans =ans *(N-i)*1.0 /(N*1.0);
            if(ans <= 0.5){
                lo = i;
                break;
            }
        }

        printf("Case %d: %d\n",tc,lo);
    }
    return 0;
}
