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

int main()
{
    ll n, a, cnt, tc=1;
    map<ll,int>mp;
    vector<ll>v;

    while(cin >> n && n)
    {
        mp.clear();
        v.clear();

        cnt=0;
        for(int i=0; i<n; i++)
        {
            cin >> a;
            mp[a]++;
            v.pb(a);
        }
        sort(v.begin(),v.end(),greater<int>());

        for(int i=0; i<n; i++)
        {
            if(i==n-1 || v[i]!=v[i+1])
            {
                cnt+=(n-i-1)*mp[v[i]];
            }
        }

        cout << "Case " << tc++ << ": " << cnt << endl;
    }

    return 0;
}
