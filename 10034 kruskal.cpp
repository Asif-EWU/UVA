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
#define MX              10003

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
int parent[102];

void initializeSet(int n)
{
    for(int i=0; i<n; i++)
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

double kruskal(int n)
{
    int x, y, sz=arr.size();
    double z, sum=0.0;

    initializeSet(n);
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
    int test, n;
    double x[102], y[102], res;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        arr.clear();
        if(t!=1)
            nl;

        fs(n);
        for(int i=0; i<n; i++)
            sf("%lf %lf",&x[i],&y[i]);

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                res=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                res=sqrt(res);
                arr.pb(Edge(i,j,res));
            }
        }

        res=kruskal(n);
        pf("%.2lf\n",res);
    }

    return 0;
}
