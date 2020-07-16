/*
........................................................
........................................................
তুমি ছেলেহারা মা জাহানারা ইমামের একাক্তরের দিনগুলি
তুমি জসিম উদদীনের নকশী কাথার মাঠ, মুঠো মুঠো সোনার ধুলি
তুমি তিরিশ কিংবা তার অধিক লাখো শহীদের প্রাণ
তুমি শহীদ মিনারের প্রভাতফেরী, ভাইহারা একুশের গান
........................................................
........................................................
*/

#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define sync            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(a,b)        memset(a,b,sizeof(a))
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause");
#define MOD             1000000007
#define M               200005
#define MX              50005

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
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

vector<int>v[30];
bool mark[30][30];

int fun(int a)
{
    int x=0;
    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i];
        if(!mark[a][b] && !mark[b][a])
        {
            mark[a][b]=mark[b][a]=1;
            x=max(x,1+fun(b));
            mark[a][b]=mark[b][a]=0;
        }
    }
    return x;
}


int main()
{
    sync;
    int a, b, n, m, mx;

    while(cin >> n >> m && n+m)
    {
        memset(mark,0,sizeof(mark));
        for(int i=0; i<n; i++) v[i].clear();

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        mx=0;
        for(int i=0; i<n; i++) mx=max(mx,fun(i));
        cout << mx << endl;
    }

    return 0;
}
