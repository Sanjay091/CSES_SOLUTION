#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int vis[10001];
 
void dfs(int n)
{
	vis[n]=1;
	for(int i=0;i<v[n].size();i++)
	{
		int x=v[n][i];
		if(vis[x]==0)
		dfs(x);
	}
}
 
int main()
{
	memset(vis,0,sizeof(vis));
	int n,m,A,B;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i);
			c++;
		}
	}
	if(c==1 && m==(n-1))
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
} 