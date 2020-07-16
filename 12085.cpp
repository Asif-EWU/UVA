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

void print(ll x, ll y)
{
    ll a;
    string s1, s2;

    stringstream ss1;
    ss1 << x;
    ss1 >> s1;
    stringstream ss2;
    ss2 << y;
    ss2 >> s2;

    cout << s1 << "-";
    for(int i=0; s1[i]; i++)
    {
        if(s1[i]!=s2[i])
        {
            a=i;
            break;
        }
    }
    for(int i=a; s2[i]; i++) cout << s2[i];
    cout << endl;
}

ll n, a, kase=1, temp;
vector<ll>v;

int32_t main()
{
    sync;

    while(cin >> n && n)
    {
        v.clear();

        for(int i=0; i<n; i++)
        {
            cin >> a;
            v.pb(a);
        }

        cout << "Case " << kase++ << ":" << endl;

        temp=0;
        for(int i=1; i<n; i++)
        {
            if(v[i]-v[i-1]==1)
            {
                if(i==n-1)
                {
                    cout << 0;
                    print(v[temp],v[i]);
                    break;
                }
            }
            else
            {
                if(i-1==temp)
                    cout << 0 << v[temp] << endl;
                else
                {
                    cout << 0;
                    print(v[temp],v[i-1]);
                }

                temp=i;
                if(i==n-1)
                {
                    cout << 0 << v[i] << endl;
                }
            }
        }

        if(n==1) cout << 0 << v[0] << endl;

        cout << endl;
    }

    return 0;
}
