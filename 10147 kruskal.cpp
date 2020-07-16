#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000
#define MX              752

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
    int from, to;
    double cost;
    Edge(int _from, int _to, double _cost)
    {
        from=_from;
        to=_to;
        cost=_cost;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost < y.cost;
}

int parent[MX];
vector<Edge>arr;

void initializeSet(int n)
{
    for(int i=1; i<=n; i++)
        parent[i]=i;
}

int findParent(int x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x]=findParent(parent[x]);
}

void unionSet(int x, int y)
{
    int px=findParent(x);
    int py=findParent(y);

    if(px!=py)
        parent[py]=px;
}

void kruskal()
{
    int x, y, sz, cnt=0;
    sz=arr.size();

    sort(arr.begin(),arr.end());
    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;

        if(findParent(x)!=findParent(y))
        {
            pf("%d %d\n",x,y);
            cnt++;
            unionSet(parent[x],parent[y]);
        }
    }

    if(cnt==0)
        pf("No new highways need\n");
}


int main()
{
    int test, n, m, a, b, x[MX], y[MX];
    double res;

    fs(test);
    for(int t=0; t<test; t++)
    {
        arr.clear();
        map<pair<int,int>,int>mp;
        if(t!=0)
            pf("\n");

        fs(n);
        initializeSet(n);

        for(int i=1; i<=n; i++)
            scanf("%d %d",&x[i],&y[i]);

        fs(m);
        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);
            mp[make_pair(a,b)]=1;
            unionSet(a,b);
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(mp[make_pair(i,j)]==0 && mp[make_pair(j,i)]==0)
                {
                    a=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    res=(double)a*1.0;
                    res=sqrt(res);
                    arr.pb(Edge(i,j,res));
                }
            }
        }

        kruskal();
    }

    return 0;
}
