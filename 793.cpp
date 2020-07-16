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
#define MX              1000000

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

void initilizeSet(int n)
{
    for(int i=1; i<=n; i++)
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


int main()
{
    int test, n, a, b, successful, unsuccessful;
    string s;
    char c;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        if(t!=1)
            nl;
        successful=0;
        unsuccessful=0;

        scanf("%d\n\n",&n);
        initilizeSet(n);
        while(1)
        {
            getline(cin,s);
            if(s=="")
                break;

            stringstream ss;
            ss << s;
            ss >> c >> a >> b;
            if(c=='c')
                unionSet(a,b);
            if(c=='q')
            {
                if(findParent(a)==findParent(b))
                    successful++;
                else
                    unsuccessful++;
            }
        }

        pf("%d,%d\n",successful,unsuccessful);
    }

    return 0;
}
