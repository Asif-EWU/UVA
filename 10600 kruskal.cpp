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
#define MX              105

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
    int from, to, cost;
    Edge(int _from, int _to, int _cost)
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
int mark[100000];
int d, sz;

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

int kruskal_1(int n)
{
    initializeSet(n);

    int x, y, z, sum=0;
    d=0;
    sz=arr.size();

    sort(arr.begin(),arr.end());
    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            sum+=z;
            unionSet(parent[x],parent[y]);

            mark[d++]=i;
            if(d+1==n)
                break;
        }
    }

    return sum;
}

int kruskal_2(int n)
{
    int x, y, z, sum, mn=INT_MAX, cnt;

    for(int i=0; i<d; i++)
    {
        initializeSet(n);
        sum=0, cnt=0;
        for(int j=0; j<sz; j++)
        {
            if(j==mark[i])
                continue;

            x=arr[j].from;
            y=arr[j].to;
            z=arr[j].cost;

            if(findParent(x)!=findParent(y))
            {
                sum+=z;
                unionSet(parent[x],parent[y]);

                cnt++;
                if(cnt+1==n)
                    break;
            }
        }

        if(cnt+1==n)
            mn=min(mn,sum);
    }

    return mn;
}

int main()
{
    int test, n, m, a, b, c, mst1, mst2;

    fs(test);
    for(int t=0; t<test; t++)
    {
        arr.clear();
        memset(mark,0,sizeof(mark));

        fs(n);fs(m);
        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);fs(c);
            arr.pb(Edge(a,b,c));
        }

        mst1=kruskal_1(n);
        mst2=kruskal_2(n);

        pf("%d %d\n",mst1,mst2);
    }

    return 0;
}
