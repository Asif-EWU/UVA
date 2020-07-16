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
    //fin; fout;

    ll t, a, b, c, d, n, m, odd, even, mx;

    fs(t);
    fl(t)
    {
        fs(m); fs(n);
        mx=n*2;

        loop(j,0,m)
        {
            odd=0, even=0;

            fs(a); fs(b); fs(c); fs(d);

            if((a+b)>mx || (c+d)>mx)
            {
                pf("no move\n");
                break;
            }

            if(a%2==0)
                even++;
            if(b%2==0)
                even++;
            if(c%2==0)
                even++;
            if(d%2==0)
                even++;

            if(a%2!=0)
                odd++;
            if(b%2!=0)
                odd++;
            if(c%2!=0)
                odd++;
            if(d%2!=0)
                odd++;

            if(a==c && b==d)
                pf("0\n");
            else if(abs(a-c)==abs(b-d))
                pf("1\n");
            else if(odd==even || odd==0 || even==0)
                pf("2\n");
            else
                pf("no move\n");
        }
    }

    return 0;
}



