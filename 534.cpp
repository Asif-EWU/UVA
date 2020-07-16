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

double arr[205][205];
double lx[205], ly[205];

void floyd_warshall(int n)
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(arr[i][j]>max(arr[i][k],arr[k][j]))
                    arr[i][j]=max(arr[i][k],arr[k][j]);
}


int main()
{
    int n, kase=1;
    double res;

    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++)
            scanf("%lf %lf",&lx[i],&ly[i]);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    arr[i][j]=0.0;
                else
                {
                    res=(lx[i]-lx[j])*(lx[i]-lx[j])+(ly[i]-ly[j])*(ly[i]-ly[j]);
                    arr[i][j]=sqrt(res);
                }
            }
        }

        floyd_warshall(n);
        pf("Scenario #%d\nFrog Distance = %.3lf\n\n",kase++,arr[0][1]);
    }

    return 0;
}
