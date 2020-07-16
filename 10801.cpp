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

int dijkstra(int n)
{
    priority_queue<Edge>pq;
    map<int,int>dist;

    for(int i=0; i<=100; i++)
        dist[i]=M;

    dist[0]=0;
    pq.push(Edge(0,0));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(top.cost!=dist[top.to])
            continue;

        for(int i=0; i<arr[top.to].size(); i++)
        {
            Edge x=arr[top.to][i];
            if(dist[x.to]>top.cost+x.cost+60)
            {
                dist[x.to]=top.cost+x.cost+60;
                pq.push(Edge(x.to,dist[x.to]));
            }
        }
    }

    return dist[n];
}


int main()
{
    int n, k, m, p, a, res;
    int cost[8];
    string s;

    while(sf("%d %d",&n,&k)==2)
    {
        arr.clear();

        for(int i=1; i<=n; i++)
            sf("%d",&cost[i]);
        cin.ignore();

        for(int i=1; i<=n; i++)
        {
            getline(cin,s);
            vector<int>v;
            stringstream ss;
            ss << s;
            while(ss >> a)
                v.pb(a);

            for(int j1=0; j1<v.size(); j1++)
            {
                for(int j2=j1+1; j2<v.size(); j2++)
                {
                    arr[v[j1]].pb(Edge(v[j2],abs(v[j2]-v[j1])*cost[i]));
                    arr[v[j2]].pb(Edge(v[j1],abs(v[j2]-v[j1])*cost[i]));
                }
            }
        }

        res=dijkstra(k);

        if(k==0)
            pf("%d\n",0);
        else if(res==M)
            pf("IMPOSSIBLE\n");
        else
            pf("%d\n",res-60);
    }

    return 0;
}
