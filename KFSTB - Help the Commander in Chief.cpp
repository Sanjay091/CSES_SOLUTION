#include<bits/stdc++.h>
using namespace std;
#define fori(x,y)   for(ll i=x;i<y;i++)
#define forj(x,y)   for(ll j=x;j<y;j++)
#define rfori(a,b)   for(int i=a;i>=b;i--)
#define for_it(a)     for(auto it: a)
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(x)      x.begin(),x.end()
#define mp          make_pair
#define mod         1000000007
#define mem(a,b)    memset(a,b,sizeof(a))
#define ld          long double
#define endl        "\n"
#define ll          long long int
#define llu         unsigned long long 
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vl         vector<ll> 
#define vi          vector<int> 
#define vc          vector<char> 
#define vs          vector<string> 
#define si          set<int>
#define spii        set<pii>
#define usi         unordered_set<int>
#define uspii       unordered_set<pii>
#define mii         map<int,int>
#define umii        unordered_map<int,int>
#define pqmx        priority_queue<int>
#define pqmn        priority_queue<int,vi,greater<int>>
#define setbits(x)  __builtin_popcountll(x)
#define fast        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcase    int t;cin>>t;for(ll i=0;i<t;i++)
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};

//-----------------------------------------------------------------------------------------------------------------/
const int sz=10005;
int mat[sz][sz];
bool vis[sz];
int path[sz];
ll n,m;


int solve(int src,int e,int p)
{
	if(src==e && p!=-1)
		return 1;
	ll path1=0;
	ll path_c=0;

	for(int v=1;v<=n;v++)
	{
		if(mat[src][v]==1 && vis[v]==false)
		{
			if(path[v]==0)
			{
				vis[v]=true;
				path_c=solve(v,e,src);
				vis[v]=false;
			}
			else
			{
				path_c=path[v]%mod;
			}
			path1=((path1%mod)+(path_c%mod))%mod;
		}
	}
	path[src]=path1;
	return path1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("A_IN.txt","r",stdin);
	freopen("A_Out.txt","w",stdout);
	#endif
	fast;
	
	testcase
	{
		ll s,e;
		cin>>n>>m;
		fori(1,n+1)
		{
			forj(1,n+1)
			{
				mat[i][j]=0;
			}
			vis[i]=false;
			path[i]=0;
		}
		cin>>s>>e;
		fori(0,m)
		{
			int x,y;
			cin>>x>>y;
			mat[x][y]=1;
		}

		ll path_cnt=0;

		vis[s]=true;
		if(s!=e)
			path_cnt=solve(s,e,-1);
		else
			path_cnt=1;
		cout<<path_cnt<<endl;

	}
	return 0;
}