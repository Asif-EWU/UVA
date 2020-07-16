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

int arr[205][205];

void floyd_warshall(int n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][j]<min(arr[i][k],arr[k][j]))
                    arr[i][j]=min(arr[i][k],arr[k][j]);
            }
        }
    }
}

int main()
{
    int n, m, d, a, b, kase=1;
    string s1, s2;

    while(sf("%d %d",&n,&m) && n+m)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                arr[i][j]=0;
            }
        }

        map<string,int>mp;
        d=1;

        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2 >> a;

            if(mp[s1]==0)
                mp[s1]=d++;
            if(mp[s2]==0)
                mp[s2]=d++;

            arr[mp[s1]][mp[s2]]=arr[mp[s2]][mp[s1]]=a;
        }

        cin >> s1 >> s2;
        a=mp[s1], b=mp[s2];

        floyd_warshall(n);

        pf("Scenario #%d\n",kase++);
        pf("%d tons\n\n",arr[a][b]);
    }

    return 0;
}
