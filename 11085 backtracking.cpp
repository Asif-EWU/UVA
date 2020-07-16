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
#define PS              system("pause");
#define MOD             1000000007
#define M               200005
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

int arr[10], col[10], mn;
bool row[10], dig1[20], dig2[20];

void fun(int pos)
{
    if(pos==9)
    {
        int sum=0;
        for(int i=1; i<=8; i++) if(arr[i]!=col[i]) sum++;
        mn=min(mn,sum);
        return;
    }

    for(int i=1; i<=8; i++)
    {
        if(!row[i] && !dig1[i+pos] && !dig2[8+i-pos])
        {
            col[pos]=i;
            row[i]=dig1[i+pos]=dig2[8+i-pos]=1;
            fun(pos+1);
            row[i]=dig1[i+pos]=dig2[8+i-pos]=0;
        }
    }
}


int main()
{
    int test=1;

    while(cin >> arr[1])
    {
        for(int i=2; i<=8; i++) cin >> arr[i];

        mn=INT_MAX;
        fun(1);
        printf("Case %d: %d\n",test++,mn);
    }

    return 0;
}
