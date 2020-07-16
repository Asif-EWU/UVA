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
#define MX              10005

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
int cost[MX];

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

void print(int n)
{
    map<int,vector<int> >arr;
    map<int,vector<int> >::iterator it;
    int sum, p, x;

    for(int i=0; i<n; i++)
    {
        p=findParent(i);
        arr[p].pb(i);
    }

    for(it=arr.begin(); it!=arr.end(); it++)
    {
        sum=0;
        x=it->first;
        for(int i=0; i<arr[x].size(); i++)
            sum+=cost[arr[x][i]];
        if(sum!=0)
        {
            pf("IMPOSSIBLE\n");
            return;
        }
    }

    pf("POSSIBLE\n");
    return;
}


int main()
{
    int test, n, m, a, b;

    fs(test);
    while(test--)
    {
        fs(n);fs(m);
        initializeSet(n);

        for(int i=0; i<n; i++)
        {
            fs(a);
            cost[i]=a;
        }

        for(int i=0; i<m; i++)
        {
            fs(a);fs(b);
            unionSet(a,b);
        }

        print(n);
    }

    return 0;
}
