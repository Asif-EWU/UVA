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
    Edge(int x, int y, double z)
    {
        from=x;
        to=y;
        cost=z;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost < y.cost;
}

vector<Edge>arr;
int parent[MX];

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

double kruskal()
{
    int x, y, sz=arr.size();
    double z, sum=0.0;

    sort(arr.begin(),arr.end());
    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            sum+=z;
            unionSet(x,y);
        }
    }

    return sum;
}


int main()
{
    int test, n, m, c, d;
    double x[MX], y[MX], res, a, b;

    while(sf("%d",&n)==1)
    {
        arr.clear();
        initializeSet(n);
        map<pair<int,int>,int>mp;

        for(int i=1; i<=n; i++)
        {
            sf("%lf %lf",&a,&b);
            x[i]=a*1.0;
            y[i]=b*1.0;
        }

        sf("%d",&m);
        for(int i=0; i<m; i++)
        {
            sf("%d %d",&c,&d);
            mp[make_pair(c,d)]=1;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                res=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                res=sqrt(res);

                if(mp[make_pair(i,j)]==1 || mp[make_pair(j,i)]==1)
                    unionSet(findParent(i),findParent(j));
                else
                    arr.pb(Edge(i,j,res));
            }
        }
        res=kruskal();
        pf("%.2lf\n",res);
    }

    return 0;
}
