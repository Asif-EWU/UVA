#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000
#define MX              200005

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

struct Edge
{
    int to, cost;
    Edge(int _to, int _cost)
    {
        to=_to;
        cost=_cost;
    }
};
bool operator<(Edge a, Edge b)
{
    return a.cost<b.cost;
}

vector<Edge>arr[202];

int prim(int from, int to, int n)
{
    priority_queue<Edge>pq;
    int cost[202];
    int parent[202];
    bool taken[202];
    int x, y, mn=INT_MAX, sum=0;

    for(int i=1; i<=n; i++)
    {
        taken[i]=false;
        cost[i]=-1;
        parent[i]=-1;
    }

    cost[from]=0;
    pq.push(Edge(from,cost[from]));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(taken[top.to])
            continue;

        taken[top.to]=true;
        sum+=top.cost;

        for(int i=0; i<arr[top.to].size(); i++)
        {
            x=arr[top.to][i].to;
            y=arr[top.to][i].cost;

            if(taken[x])
                continue;
            if(cost[x]<y)
            {
                cost[x]=y;
                parent[x]=top.to;
                pq.push(Edge(x,cost[x]));
            }
        }
    }

    while(to!=from)
    {
        mn=min(mn,cost[to]);
        to=parent[to];
    }

    return mn;
}


int main()
{
    int n, m, a, d, kase=1, res;
    string s1, s2;

    while(sf("%d %d",&n,&m) && n+m)
    {
        map<string,int>mp;
        d=1;

        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2 >> a;
            if(mp[s1]==0)
                mp[s1]=d++;
            if(mp[s2]==0)
                mp[s2]=d++;
            arr[mp[s1]].pb(Edge(mp[s2],a));
            arr[mp[s2]].pb(Edge(mp[s1],a));
        }

        cin >> s1 >> s2;
        res=prim(mp[s1],mp[s2],n);

        pf("Scenario #%d\n",kase++);
        pf("%d tons\n\n",res);
    }

    return 0;
}
