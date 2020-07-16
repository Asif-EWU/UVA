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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             100000007
#define M               1000007
#define MX              505

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

int n, m;
string s1, s2;
int dp[1002][1002];

int fun(int x, int y)
{
    if(x==m) return n-y;
    if(y==n) return m-x;
    if(dp[x][y]!=-1) return dp[x][y];

    int a, b, c;

    if(s1[x]==s2[y]) return dp[x][y]=fun(x+1,y+1);
    else
    {
        a=1+fun(x,y+1);   // insert
        b=1+fun(x+1,y);   // delete
        c=1+fun(x+1,y+1); // change

        return dp[x][y]=min(a,min(b,c));
    }
}

int32_t main()
{
    sync;
    while(cin >> m)
    {
        memset(dp,-1,sizeof(dp));
        cin >> s1;
        cin >> n >> s2;
        cout << fun(0,0) << endl;
    }

    return 0;
}
