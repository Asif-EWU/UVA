#include<bits/stdc++.h>
#define fl(n) for(int i=0; i<n; i++)
#define loop(i, a, n) for(int i=a; i<n; i++)
#define pb push_back
#define pp pop_back
#define ll long long int
#define ld long double
#define inf 5e18
#define sf scanf
#define Sf(a) scanf("%lf",&a)
#define pf printf
#define Pfc(a) printf("Case %d: ",a)
#define Pfl(a) printf("%lld",a)
#define Pfi(a) printf("%d",a)
#define nl printf("\n")
#define Vl vector<ll>
#define Vi vector<int>
#define fin freopen("input.txt", "r", stdin)
#define fout freopen("outut.txt", "w", stdout)
#define PI 2*acos(0.0)
#define F first
#define S second
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define PS system("pause")
#define BM bool mark[M+10]
#define MOD 1000000007
#define M 200009

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


int main()
{
    ll n, m, a;

    while(1)
    {
        set<ll> arr;

        fs(n); fs(m);

        if(n==0 && m==0)
            break;

        fl(n)
        {
            fs(a);
            arr.insert(a);
        }
        fl(m)
        {
            fs(a);
            arr.insert(a);
        }

        Pfl(m+n-arr.size());
        nl;
    }

    return 0;
}



