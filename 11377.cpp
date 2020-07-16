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
bool city[2005];

int dijkstra(int node, int from, int to)
{
    priority_queue<Edge>pq;
    int dist[2005];

    for(int i=1; i<=node; i++)
        dist[i]=M;

    if(city[from])
        dist[from]=0;
    else
        dist[from]=1;

    pq.push(Edge(from,dist[from]));

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
                pq.push(Edge(x.to,dist[x.to]));
            }
        }
    }

    return dist[to];
}


int main()
{
    int test, n, m, k, a, b, res;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        pf("Case %d:\n",t);

        memset(city,0,sizeof(city));
        arr.clear();

        fs(n);fs(m);fs(k);
        for(int i=1; i<=k; i++)
        {
            fs(a);
            city[a]=true;
        }

        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);
            if(!city[b])
                arr[a].pb(Edge(b,1));
            if(!city[a])
                arr[b].pb(Edge(a,1));
            if(city[b])
                arr[a].pb(Edge(b,0));
            if(city[a])
                arr[b].pb(Edge(a,0));
        }

        fs(m);
        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);
            res=dijkstra(n,a,b);

            if(a==b)
                pf("0\n");
            else if(res==M)
                pf("-1\n");
            else
                pf("%d\n",res);
        }
        nl;
    }

    return 0;
}
