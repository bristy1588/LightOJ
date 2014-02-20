/*
	Day 4: February
	Light OJ Volume 2 Practise
	A very interesting Bellman ford Probelem
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#define		Z	1005
#define 	u	first
#define		w 	second
#define		pb	push_back
#define		mp	make_pair
#define		inf	1000000009
using namespace std;
typedef pair<int, int> pii;

vector<pii> v[Z], rev[Z];
int N, dist[Z], worm[Z];
bool vis[Z];
vector<int> source, ans;
inline void BFS(){
	ans.clear();
	queue<int>q;

	memset(vis, false, sizeof(vis));
	int i,cur,now;

	for(i = 0; i < source.size(); i++){
		now = source[i];
		q.push(now);
		vis[now] = true;
	}

	while(!q.empty()){

		cur = q.front(); q.pop();
		for(i = 0; i < v[cur].size(); i++){
			now = v[cur][i].u;
			if(vis[now] == true) continue;
			vis[now] = true;
			q.push(now);
		}
	
	}


	for(i = 0; i < N; i++){
		if(vis[i] == true) ans.pb(i);	
	}

	return;
}
inline bool Bellford()
{
	int i,j,k,now;
	bool flag = false;

	for(i = 0; i < N; i++) dist[i]  = 0;
	

	for(k  = 1; k < N ; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < v[i].size(); j++){
				now = v[i][j].u;
				dist[now] = min(dist[now], dist[i] + v[i][j].w);
			}	
		}
	}
	
	for(i = 0; i < N ; i++) worm[i] = dist[i];

	// Abar Bellford Chalailam

	for(k  = 1; k < N ; k++){
		for(i = 0; i < N; i++){
			for(j = 0; j < v[i].size(); j++){
				now = v[i][j].u;
				dist[now] = min(dist[now], dist[i] + v[i][j].w);
			}	
		}
	}

	// FInally negative cycle ase ki na sheita check kortese;
	source.clear();
	for(i = 0; i < N; i++){
		if(dist[i] < worm[i]){
			flag = true;
			source.pb(i);		
		}
	}
		
	if(flag==true) BFS();
	return flag;
}
int main()
{
	int T,tc,M, i,x,y,len;

	cin >> T;
	tc = 0;

	while(tc< T)
	{
		tc++;
					
		cin>>N>>M;
		
		for(i = 0; i < N; i++){
			v[i].clear();
			rev[i].clear();
		}
		
		for(i = 0; i < M ; i++)
		{
			cin >> x>> y>> len;
			v[y].pb(mp(x,len)); 
			
		}
		
		bool z;
		z = Bellford();
		printf("Case %d:",tc);
		if(z==false)	printf(" impossible\n");
		else{
			sort(ans.begin(), ans.end());
			for(i = 0; i < ans.size(); i++)
				printf(" %d",ans[i]);
			printf("\n");

		}	
					
					
	}
	return 0;
}
