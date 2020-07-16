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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               100000000
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

int32_t main()
{
    sync;
    ll test, n, sum;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        cin >> n;
        cout << "Case #" << t << ": " << n << " is ";

        map<ll,int>mp;
        while(1)
        {
            mp[n]=1;
            sum=0;
            while(n)
            {
                sum+=(n%10)*(n%10);
                n/=10;
            }
            n=sum;
            if(n==1)
            {
                cout << "a Happy number." << endl;
                break;
            }
            if(mp[n]==1)
            {
                cout << "an Unhappy number." << endl;
                break;
            }
        }
    }

    return 0;
}
