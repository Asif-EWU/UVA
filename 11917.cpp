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
    sync;
    map<string,int>mp;
    string s;
    int test, n, a, b;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        mp.clear();

        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> s >> a;
            mp[s]=a;
        }
        cin >> a >> s;
        b=mp[s];

        cout << "Case " << t << ": ";
        if(b<=a && b!=0) cout << "Yesss" << endl;
        else if(b>a && b<=a+5) cout << "Late" << endl;
        else if(b==0) cout << "Do your own homework!" << endl;
        else cout << "Do your own homework!" << endl;
    }

    return 0;
}
