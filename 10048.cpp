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

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

int arr[105][105];

void floyd_warshall(int n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][j]>arr[i][k] && arr[i][j]>arr[k][j])
                {
                    arr[i][j]=max(arr[i][k],arr[k][j]);
                }
            }
        }
    }
}

int main()
{
    int a, b, c, x, y, z, t=1;

    while(sf("%d %d %d",&a,&b,&c) && a+b+c)
    {
        for(int i=1; i<=a; i++)
        {
            for(int j=1; j<=a; j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=M;
            }
        }

        for(int i=0; i<b; i++)
        {
            fs(x);
            fs(y);
            fs(z);
            arr[x][y]=arr[y][x]=z;
        }

        floyd_warshall(a);


        if(t!=1)
            nl;
        pf("Case #%d\n",t++);
        for(int i=0; i<c; i++)
        {
            fs(a);
            fs(b);
            x=arr[a][b];
            if(x==M)
                pf("no path\n");
            else
                pf("%d\n",x);
        }
    }

    return 0;
}
