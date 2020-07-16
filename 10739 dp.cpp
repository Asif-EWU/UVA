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

string s;
int dp[1005][1005];

int fun(int l, int r)
{
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    int a, b, c, d;
    a=b=c=d=INT_MAX;

    if(s[l]==s[r]) a=fun(l+1,r-1);
    else
    {
        b=1+fun(l+1,r);
        c=1+fun(l,r-1);
        d=1+fun(l+1,r-1);
    }

    return dp[l][r]=min(a,min(b,min(c,d)));
}

int32_t main()
{
    sync;
    int test;

    cin >> test;
    cin.ignore();
    for(int t=1; t<=test; t++)
    {
        mem(dp,-1);
        getline(cin,s);
        cout << "Case " << t << ": ";
        if(s=="") cout << 0 << endl;
        else cout << fun(0,s.size()-1) << endl;
    }

    return 0;
}
