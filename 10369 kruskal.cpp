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
#define MX              30005

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
    Edge(int f, int t, double c)
    {
        from=f;
        to=t;
        cost=c;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost < y.cost;
}

vector<Edge>arr;
int parent[502];

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

double kruskal(int n, int m)
{
    int cnt=0, sz=arr.size();
    int x, y;
    double z;

    initializeSet(m);
    sort(arr.begin(),arr.end());
    n=m-n-1;

    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            if(cnt==n)
                return z;
            cnt++;
            unionSet(parent[x],parent[y]);
        }
    }
}


int main()
{
    int test, n, m;
    double res, ans, a, b;
    double x[502], y[502];

    fs(test);
    while(test--)
    {
        arr.clear();

        fs(n);fs(m);
        for(int i=0; i<m; i++)
        {
            sf("%lf %lf",&a,&b);
            x[i]=a*1.0;
            y[i]=b*1.0;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                res=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                res=sqrt(res*1.0);

                arr.pb(Edge(i,j,res));
            }
        }

        res=kruskal(n,m)*1.0;
        pf("%.2lf\n",res);
    }

    return 0;
}
