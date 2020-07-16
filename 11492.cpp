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
    char str;
    Edge(int _to, int _cost, char _str)
    {
        to=_to;
        cost=_cost;
        str=_str;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost>y.cost;
}

map<int,vector<Edge> >arr;

int dijkstra(int from, int to, int n)
{
    priority_queue<Edge>pq;
    map<int,int>dist;

    for(int i=1; i<n; i++)
        dist[i]=M;

    dist[from]=0;
    pq.push(Edge(from,0,'#'));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(top.cost!=dist[top.to])
            continue;

        for(int i=0; i<arr[top.to].size(); i++)
        {
            Edge x=arr[top.to][i];
            if(top.cost+x.cost<dist[x.to] && top.str!=x.str)
            {
                dist[x.to]=top.cost+x.cost;
                pq.push(Edge(x.to,dist[x.to],x.str));
            }
        }
    }

    return dist[to];
}

int main()
{
    int n, d, x, y, res, a;
    string s1, s2, s3;

    while(sf("%d",&n) && n)
    {
        map<string,int>mp;
        arr.clear();
        d=1;

        cin >> s1 >> s2;
        mp[s1]=d++;
        mp[s2]=d++;

        for(int i=0; i<n; i++)
        {
            cin >> s1 >> s2 >> s3;
            if(mp[s1]==0)
                mp[s1]=d++;
            if(mp[s2]==0)
                mp[s2]=d++;

            a=s3.size();
            arr[mp[s1]].pb(Edge(mp[s2],a,s3[0]));
            arr[mp[s2]].pb(Edge(mp[s1],a,s3[0]));
        }

        res=min(dijkstra(1,2,d),dijkstra(2,1,d));

        if(res==M)
            pf("impossivel\n");
        else
            pf("%d\n",res);
    }

    return 0;
}
