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

int n, a, mx;
int arr[500];
int num[500];
vector<int>v;

void fun(int pos, int sum, int last)
{
    if(pos==a+1 || sum>n) return;
    if(sum>mx)
    {
        v.clear();
        for(int i=0; i<pos; i++) v.push_back(arr[i]);
        mx=sum;
    }

    for(int i=last; i<a; i++)
    {
        arr[pos]=num[i];
        fun(pos+1,sum+num[i],i+1);
    }
}


int main()
{
    int sum;

    while(cin >> n)
    {
        cin >> a;
        for(int i=0; i<a; i++) cin >> num[i];

        mx=0;
        fun(0,0,0);

        sum=0;
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i] << " ";
            sum+=v[i];
        }
        cout << "sum:" << sum << endl;
    }

    return 0;
}
