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
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000
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

int n, arr[20];
bool mark[20], prime[20];

void fun(int pos)
{
    if(pos==n)
    {
        if(prime[arr[n-1]+1])
        {
            for(int i=0; i<n; i++)
            {
                if(i!=0) cout << " ";
                cout << arr[i];
            }
            cout << endl;
        }
        return;
    }

    for(int i=2; i<=n; i++)
    {
        if(!mark[i] && prime[arr[pos-1]+i])
        {
            mark[i]=1;
            arr[pos]=i;
            fun(pos+1);
            mark[i]=0;
        }
    }
}


int main()
{
    arr[0]=1;
    prime[2]=1;
    prime[3]=1;
    prime[5]=1;
    prime[7]=1;
    prime[11]=1;
    prime[13]=1;
    prime[17]=1;
    prime[19]=1;
    prime[23]=1;
    prime[29]=1;
    prime[31]=1;

    int test=1;

    while(cin >> n)
    {
        if(test!=1) cout << endl;
        cout << "Case " << test++ << ":" << endl;
        fun(1);
    }

    return 0;
}
