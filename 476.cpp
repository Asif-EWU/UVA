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


int32_t main()
{
    double a[12], b[12], c[12], d[12];
    char ch;
    double m, n;
    int p=0, q=1, cnt=0;

    while(1)
    {
        cin >> ch;
        if(ch=='r')
        {
            cin >> a[p] >> b[p] >> c[p] >> d[p];
            p++;
        }
        else break;
    }

    while(1)
    {
        cin >> m >> n;
        if(m==9999.9 && n==9999.9) break;

        for(int i=0; i<p; i++)
        {
            if( ((m>a[i] && m<c[i]) || (m<a[i] && m>c[i]))
              &&((n>b[i] && n<d[i]) || (n<b[i] && n>d[i])))
            {
                cout << "Point " << q << " is contained in figure " << i+1 << endl;
                cnt++;
            }
        }
        if(cnt==0) cout << "Point " << q << " is not contained in any figure" << endl;
        cnt=0;
        q++;
    }

    return 0;
}
