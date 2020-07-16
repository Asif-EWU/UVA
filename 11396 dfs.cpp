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
#define M               1000000000
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

vector<int>v[302];
int mark[302];
bool flag;

void dfs(int a)
{
    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i];

        if(mark[a]==mark[b]) flag=0;
        if(mark[b]==0)
        {
            if(mark[a]==1) mark[b]=2;
            if(mark[a]==2) mark[b]=1;
            dfs(b);
        }
    }
}

int main()
{
    int n, a, b;

    while(cin >> n && n)
    {
        for(int i=1; i<=n; i++) v[i].clear();
        memset(mark,0,sizeof(mark));

        while(cin >> a >> b && a+b)
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }

        mark[1]=1;
        flag=1;
        dfs(1);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
