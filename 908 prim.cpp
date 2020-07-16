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
#define MX              1000000

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
    return a.cost>b.cost;
}

vector<Edge>arr[MX+2];
int cost[MX+2];
bool taken[MX+2];

int prim(int from, int n)
{
    priority_queue<Edge>pq;
    int x, y, sum=0;

    for(int i=1; i<=n; i++)
    {
        cost[i]=INT_MAX;
        taken[i]=false;
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
            if(cost[x]>y)
            {
                cost[x]=y;
                pq.push(Edge(x,cost[x]));
            }
        }
    }

    return sum;
}

int main()
{
    int n, k, m, a, b, c, sum, d=1;

    while(sf("%d",&n)==1)
    {
        sum=0;
        for(int i=1; i<=n; i++)
            arr[i].clear();

        for(int i=1; i<n; i++)
        {
            fs(a);fs(b);fs(c);
            arr[a].pb(Edge(b,c));
            arr[b].pb(Edge(a,c));
            sum+=c;
        }

        fs(k);
        for(int i=0; i<k; i++)
        {
            fs(a);fs(b);fs(c);
            arr[a].pb(Edge(b,c));
            arr[b].pb(Edge(a,c));
        }

        fs(m);
        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);fs(c);
        }

        if(d!=1)
            nl;
        d++;
        pf("%d\n",sum);
        pf("%d\n",prim(1, n));
    }

    return 0;
}
