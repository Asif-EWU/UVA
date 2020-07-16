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
#define MX              200005

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

int parent[30005];
int member[30005];

void initializeSet(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
        member[i]=1;
    }
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
    {
        parent[py]=px;
        member[px]+=member[py];
    }
}

void print(int n)
{
    int mx=0;
    for(int i=1; i<=n; i++)
        mx=max(mx,member[i]);
    pf("%d\n",mx);
}


int main()
{
    int test, n, m, a, b;

    fs(test);
    while(test--)
    {
        fs(n);fs(m);
        initializeSet(n);

        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);
            unionSet(a,b);
        }
        print(n);
    }

    return 0;
}
