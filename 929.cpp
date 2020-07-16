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

struct Edge
{
    int a, b, cost;
    Edge(int _a, int _b, int _cost)
    {
        a=_a;
        b=_b;
        cost=_cost;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost>y.cost;
}

int arr[1005][1005];
int dist[1005][1005];

int dijkstra(int n, int m)
{
    priority_queue<Edge>pq;
    int fx[]={0,0,1,-1};
    int fy[]={1,-1,0,0};
    int tx, ty;

    dist[1][1]=arr[1][1];
    pq.push(Edge(1,1,dist[1][1]));

    while(!pq.empty())
    {
        Edge top=pq.top();
        pq.pop();

        if(top.cost!=dist[top.a][top.b])
            continue;

        for(int i=0; i<4; i++)
        {
            tx=top.a+fx[i];
            ty=top.b+fy[i];

            if(tx>0 && ty>0 && tx<=n && ty<=m)
            {
                if(dist[tx][ty]>top.cost+arr[tx][ty])
                {
                    dist[tx][ty]=top.cost+arr[tx][ty];
                    pq.push(Edge(tx,ty,dist[tx][ty]));
                }
            }
        }
    }

    return dist[n][m];
}


int main()
{
    int test, n, m, a;

    fs(test);
    for(int t=0; t<test; t++)
    {
        fs(n);fs(m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                fs(a);
                arr[i][j]=a;
                dist[i][j]=M;
            }
        }

        pf("%d\n",dijkstra(n,m));
    }

    return 0;
}
