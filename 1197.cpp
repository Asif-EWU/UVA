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

int parent[MX];
int rnk[MX];

void initializeSet(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        rnk[i]=0;
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

    if(px==py)
        return;
    else if(rnk[px]>rnk[py])
        parent[py]=px;
    else if(rnk[px]<rnk[py])
        parent[px]=py;
    else
    {
        parent[py]=px;
        rnk[px]++;
    }
}

int print(int n)
{
    int cnt=0;
    int p=findParent(0);

    for(int i=0; i<n; i++)
    {
        if(findParent(i)==p)
            cnt++;
    }

    return cnt;
}


int main()
{
    int n, m, a, b, x;

    while(sf("%d %d",&n,&m) && n+m)
    {
        initializeSet(n);

        for(int i=0; i<m; i++)
        {
            fs(a);
            for(int j=0; j<a; j++)
            {
                fs(b);
                if(j==0)
                    x=b;
                unionSet(x,b);
            }
        }

        pf("%d\n",print(n));
    }

    return 0;
}
