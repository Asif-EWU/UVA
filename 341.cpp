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

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

struct Edge
{
    int to, cost;
    Edge(int _to, int _cost)
    {
        to=_to;
        cost=_cost;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost>y.cost;
}


map<int,vector<Edge> >arr;
void dijkstra(int node, int from, int to)
{
    priority_queue<Edge>pq;
    map<int,int>dist;
    map<int,int>parent;
    vector<int>v;

    for(int i=1; i<=node; i++)
        dist[i]=M;
    dist[from]=0;
    pq.push(Edge(from,0));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(top.cost!=dist[top.to])
            continue;
        for(int i=0; i<arr[top.to].size(); i++)
        {
            Edge x=arr[top.to][i];
            if(top.cost+x.cost<dist[x.to])
            {
                dist[x.to]=top.cost+x.cost;
                parent[x.to]=top.to;
                pq.push(Edge(x.to,dist[x.to]));
            }
        }
    }

    int x=to;
    v.pb(x);
    while(x!=from)
    {
        x=parent[x];
        v.pb(x);
    }

    for(int i=v.size()-1; i>=0; i--)
        pf(" %d",v[i]);
    pf("; %d second delay\n",dist[to]);
}


int main()
{
    int n, m, to, cost, a, b, kase=1;

    while(sf("%d",&n) && n)
    {
        arr.clear();

        for(int i=1; i<=n; i++)
        {
            fs(m);
            for(int j=0; j<m; j++)
            {
                fs(to);fs(cost);
                arr[i].pb(Edge(to,cost));
            }
        }

        fs(a);fs(b);
        pf("Case %d: Path =",kase++);
        dijkstra(n,a,b);
    }

    return 0;
}
