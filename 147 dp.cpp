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

int arr[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[13][30007];

ll fun(int pos, int n)
{
    if(pos==11) return 0;
    if(n==0) return 1;
    if(dp[pos][n]!=-1) return dp[pos][n];

    ll a=0, b;
    if(arr[pos]<=n) a=fun(pos,n-arr[pos]);
    b=fun(pos+1,n);

    return dp[pos][n]=a+b;
}

int32_t main()
{
    sync;
    double a, b;
    int n;

    mem(dp,-1);
    while(cin >> a && a!=0.0)
    {
        stringstream ss;
        b=a*100.0;
        ss << b;
        ss >> n;
        cout << setfill(' ') << setw(6) << setprecision(2) << fixed << a << setfill(' ') << setw(17) << fun(0,n) << endl;
    }

    return 0;
}
