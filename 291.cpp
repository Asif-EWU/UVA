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

int mark[12], arr[12];
int chk[10][10];
vector<int>v[12];

void fun(int pos, int last)
{
    if(pos==9 && arr[8]!=4 && arr[8]!=2 && arr[7]!=2)
    {
        for(int i=1; i<=9; i++) cout << arr[i];
        cout << endl;
        return;
    }

    for(int i=0; i<v[last].size(); i++)
    {
        int a=v[last][i];
        if(mark[a] && arr[pos-2]!=a && !chk[last][a])
        {
            arr[pos]=a;
            chk[last][a]=chk[a][last]=1;
            mark[a]--;
            fun(pos+1,a);
            mark[a]++;
            chk[last][a]=chk[a][last]=0;
        }
    }
}


int main()
{
    v[1].pb(2);
    v[1].pb(3);
    v[1].pb(5);

    v[2].pb(1);
    v[2].pb(3);
    v[2].pb(5);

    v[3].pb(1);
    v[3].pb(2);
    v[3].pb(4);
    v[3].pb(5);

    v[4].pb(3);
    v[4].pb(5);

    v[5].pb(1);
    v[5].pb(2);
    v[5].pb(3);
    v[5].pb(4);

    arr[1]=1;
    arr[9]=2;

    mark[1]=mark[2]=mark[4]=1;
    mark[3]=mark[5]=2;

    fun(2,1);

    return 0;
}
