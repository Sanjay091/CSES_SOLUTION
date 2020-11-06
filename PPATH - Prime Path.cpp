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
vector<int> arr[10001];
vector<int> prime;
int vis[10001];
int dis[10001];

bool isValid(int a,int b)
{
	int c=0;
	while(a>0)
	{
		if(a%10 != b%10)
			c++;
		a=a/10;
		b=b/10;
	}
	if(c==1)
		return true;
	else
		return false;
}

bool isPrime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

void buildGraph()
{
	fori(1000,10000)
	{
		if(isPrime(i))
			prime.pb(i);
	}

	fori(0,prime.size())
	{
		forj(i+1,prime.size())
		{
			int a=prime[i];
			int b=prime[j];
			if(isValid(a,b))
			{
				arr[a].pb(b);
				arr[b].pb(a);
			}
		}
	}
}

void bfs(int src)
{
	vis[src]=1;
	dis[src]=0;
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto child:arr[node])
		{
			if(vis[child]==0)
			{
				vis[child]=1;
				dis[child]=dis[node]+1;
				q.push(child);
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("A_IN.txt","r",stdin);
	freopen("A_Out.txt","w",stdout);
	#endif
	fast;
	
	buildGraph();
	testcase
	{
		ll a,b;
		cin>>a>>b;

		fori(1000,10000)
		{
			dis[i]=-1;
			vis[i]=0;
		}

		bfs(a);

		if(dis[b]==-1)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<dis[b]<<endl;

	}
	

	return 0;
}