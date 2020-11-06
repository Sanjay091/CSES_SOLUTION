#include<bits/stdc++.h>
using namespace std;
#define fori(x,y)   for(ll i=x;i<y;i++)
#define forj(x,y)   for(ll j=x;j<y;j++)
#define rfori(a,b)  for(int i=a;i>=b;i--)
#define for_it(a)   for(auto it: a)
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
// #define RD(n)       scanf("%d",&n)
// #define RD(x,y)     scanf("%d %d",&x,&y)
// #define RD(x,y,z)   scanf("%d %d %d",&x,&y,&z)
#define ll          long long int
#define llu         unsigned long long 
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vl          vector<ll> 
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
#define testcase    int t;cin>>t;for(ll test=0;test<t;test++)
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};

/*-----------------------------------------------------------------------------------------------------------------*/
char mat[10001][10001];
int vis[10001][10001];
int maxD,maxX,maxY,n,m;

bool isvalid(int x,int y)
{

    if(x>=1 && y>=1 && x<=n && y<=m && vis[x][y]==0 && mat[x][y]=='.')
        return true;
    else
        return false;
}


void dfs(int x,int y,int dis)
{
    if(dis>maxD)
    {
        maxX=x;
        maxY=y;
        maxD=dis;
    }
    vis[x][y]=1;
    dis=dis+1;
    fori(0,4)
    {
        // cout<<x<<y;
        int dx=x+xx[i];
        int dy=y+yy[i];
        if(isvalid(dx,dy))
        {

            dfs(dx,dy,dis);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("C_IN.txt","r",stdin);
    freopen("C_Out.txt","w",stdout);
    #endif
    fast;
    testcase
    {

        mem(vis,0);
        cin>>m>>n;
        int x,y;
        fori(1,n+1)
        {
            forj(1,m+1)
            {
                cin>>mat[i][j];
            }
        }
        fori(1,n+1)
        {
            bool flag=false;
            forj(1,m+1)
            {
                if(mat[i][j]=='.')
                {
                    x=i;
                    y=j;
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        // cout<<x<<y<<endl;
        maxD=0,maxX=0,maxY=0;
        dfs(x,y,0);
        mem(vis,0);
        maxD=0;
        dfs(maxX,maxY,0);
        cout<<"Maximum rope length is "<<maxD<<"."<<endl;
    }

    
    return 0;
}


