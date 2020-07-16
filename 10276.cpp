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

vector<int>v[55];
int n, mx;
bool flag;

bool chk(int a)
{
    int b=sqrt(a);
    if(b*b==a) return true;
    else return false;
}

void fun(int pos, int x)
{
    if(flag) return;
    if(x==n+1)
    {
        mx=pos-2;
        flag=1;
        return;
    }

    for(int i=1; i<=n+1; i++)
    {
        if(v[i].size()==0)
        {
            v[i].push_back(pos);
            fun(pos+1,i);
        }
        else
        {
            int a=v[i][v[i].size()-1];
            if(chk(a+pos))
            {
                v[i].push_back(pos);
                fun(pos+1,i);
            }
        }
    }
}


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(int i=1; i<=n+1; i++) v[i].clear();

        flag=0;
        fun(1,1);
        cout << mx << endl;
    }

    return 0;
}
