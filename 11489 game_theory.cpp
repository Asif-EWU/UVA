/*
........................................................
........................................................
তুমি ছেলেহারা মা জাহানারা ইমামের একাক্তরের দিনগুলি
তুমি জসিম উদদীনের নকশী কাথার মাঠ, মুঠো মুঠো সোনার ধুলি
তুমি তিরিশ কিংবা তার অধিক লাখো শহীদের প্রাণ
তুমি শহীদ মিনারের প্রভাতফেরী, ভাইহারা একুশের গান
........................................................
........................................................
*/

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
#define err             cout << "OK" << endl;
#define PS              system("pause");
#define MOD             1000000007
#define M               132680
#define MX              50005

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
int sum, n;
bool mark[1005];

bool fun()
{
    if(sum<3) return 0;
    for(int i=0; s[i]; i++)
    {
        if(!mark[i])
        {
            if((sum-s[i]+'0')%3==0)
            {
                mark[i]=1;
                sum-=s[i]-'0';
                n--;
                if(fun()==0) return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int test, res;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        sum=0;
        memset(mark,0,sizeof(mark));

        cin >> s;
        n=s.size();

        for(int i=0; s[i]; i++) sum+=s[i]-'0';
        res=fun();
        if((res==1 && n!=1) || res==0 && n==1) printf("Case %d: S\n",t);
        else printf("Case %d: T\n",t);
    }

    return 0;
}
