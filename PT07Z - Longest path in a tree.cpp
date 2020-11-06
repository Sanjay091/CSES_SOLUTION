#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int vis[10001];
int maxD,maxNode;
void dfs(int n,int dis)
{
	vis[n]=1;
	if(dis>maxD)
	{
		maxD=dis;
		maxNode=n;
	}
	for(int i=0;i<v[n].size();i++)
	{
		int x=v[n][i];
		if(vis[x]==0)
		{
			dfs(x,1+dis);
		}
	}
}
 
int main()
{
 
		memset(vis,0,sizeof(vis));
		int n,A,B;
		cin>>n;
		for(int i=1;i<=n-1;i++)
		{
			cin>>A>>B;
			v[A].push_back(B);
			v[B].push_back(A);
		}
		maxD=-1;
		dfs(1,0);
		memset(vis,0,sizeof(vis));
		maxD=-1;
		dfs(maxNode,0);
		cout<<maxD<<endl;
	
} 