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

int parent[MX];
int rnk[MX];
int arr[MX];

void initializeSet()
{
    for(int i=1; i<MX; i++)
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
    int py=findParent(y);
    int px=findParent(x);

    if(px==py)
        pf("%d\n",arr[px]);
    else if(rnk[px]<rnk[py])
    {
        parent[px]=py;
        arr[py]+=arr[px];
        pf("%d\n",arr[py]);
    }
    else if(rnk[px]>rnk[py])
    {
        parent[py]=px;
        arr[px]+=arr[py];
        pf("%d\n",arr[px]);
    }
    else
    {
        parent[py]=px;
        rnk[px]++;
        arr[px]+=arr[py];
        pf("%d\n",arr[px]);
    }
}


int main()
{
    int test, n, d, p;
    string s1, s2;

    fs(test);
    while(test--)
    {
        map<string,int>mp;
        d=1;
        initializeSet();

        fs(n);
        for(int i=0; i<n; i++)
        {
            cin >> s1 >> s2;

            if(mp[s1]==0)
            {
                arr[d]=1;
                mp[s1]=d++;
            }
            if(mp[s2]==0)
            {
                arr[d]=1;
                mp[s2]=d++;
            }

            unionSet(mp[s1],mp[s2]);
        }
    }

    return 0;
}
