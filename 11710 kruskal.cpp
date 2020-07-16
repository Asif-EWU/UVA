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
#define MX              1005

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

void kruskal(int n)
{
    initializeSet(n);

    int x, y, z, sum=0, cnt=0, sz=arr.size();
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
            cnt++;
            if(cnt+1==n)
                break;
        }
    }

    if(cnt+1!=n)
        pf("Impossible\n");
    else
        pf("%d\n",sum);
}


int main()
{
    int n, m, c, d;
    string s1, s2;

    while(sf("%d %d",&n,&m) && n+m)
    {
        map<string,int>mp;
        arr.clear();
        d=1;

        for(int i=0; i<n; i++)
        {
            cin >> s1;
            if(mp[s1]==0)
                mp[s1]=d++;
        }

        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2 >> c;
            arr.pb(Edge(mp[s1],mp[s2],c));
        }

        cin >> s1;

        kruskal(d-1);
    }

    return 0;
}
