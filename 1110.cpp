/*
	Day 4: February 20, 2014
	Light OJ Volume 2 Practise
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#define		Z	205
#define 	u	first
#define		w 	second
#define		pb	push_back
#define		mp	make_pair
#define		inf	1000000009
using namespace std;
char dummy[Z], s1[Z], s2[Z];
int k1,k2, dp[Z][Z], rec[Z][Z];

inline int solve(int i, int j)
{
	int w,x,y,now;

	if(i==k1 || j == k2) return 0;

	int &ret = dp[i][j];

	if(ret != -1) return ret;
	ret = 0;
	

	for(w = 0; w< 26; w++){
		for(x = i ; x < k1; x++)
			if(s1[x] == ('a' + w)) break;
		for(y = j; y < k2; y++)
			if(s2[y] == ('a' +w)) break;
		
		if( x< k1 && y< k2){
			now = solve(x+1, y+1) + 1;
			if(now > ret){
				ret = now;
				rec[i][j] = w;
			}
		}
	}

	return ret;

}
inline void PPATH(int i, int j){

	int x,y,w;
	
	if(i==k1 || j==k2) return;
	
	if(rec[i][j] == (-1)) return;
	
	w = rec[i][j];
	for(x = i ; x < k1; x++)
		if(s1[x] == ('a' + w)) break;
	for(y = j; y < k2; y++)
		if(s2[y] == ('a' +w)) break;
	
	printf("%c", 'a' +w);			
	PPATH(x+1,y+1);
	
	return;
}
int main()
{
	int tc, T, ans;

	tc = 0;
	cin >> T;
	gets(dummy);

	while(tc < T)
	{
		tc++;
		gets(dummy);
		gets(s1);
		gets(s2);

		k1  = strlen(s1);
		k2  = strlen(s2);

		memset(dp, -1, 	sizeof(dp));
		memset(rec, -1, sizeof(rec));

		ans = solve(0,0);
		printf("Case %d: ",tc);
		if(ans == 0) printf(":(");
		else PPATH(0,0);
		
		printf("\n");

			
	}

	return 0;
}













