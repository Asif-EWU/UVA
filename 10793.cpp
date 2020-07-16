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
                if(arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
            }
        }
    }
}


int main()
{
    int test, n, m, a, b, c, mn, mx;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        vector<int>v;

        fs(n);
        fs(m);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=M;
            }
        }

        for(int i=0; i<m; i++)
        {
            fs(a);
            fs(b);
            fs(c);
            arr[a][b]=arr[b][a]=min(arr[a][b],c);
        }

        floyd_warshall(n);

        for(int i=6; i<=n; i++)
        {
            if(arr[i][1]==arr[i][2] && arr[i][2]==arr[i][3] && arr[i][3]==arr[i][4] && arr[i][4]==arr[i][5] && arr[i][1]!=M)
                v.pb(i);
        }

        if(v.size()==0)
            pf("Map %d: -1\n",t);
        else
        {
            mn=M;
            for(int i=0; i<v.size(); i++)
            {
                a=v[i];
                mx=0;
                for(int i=1; i<=n; i++)
                    mx=max(mx,arr[a][i]);

                mn=min(mn,mx);
            }

            if(mn==M)
                pf("Map %d: -1\n",t);
            else
                pf("Map %d: %d\n",t,mn);
        }
    }

    return 0;
}
