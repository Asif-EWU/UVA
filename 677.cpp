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

vector<int>v[12];
bool mark[12], flag;
int arr[12];
int k;

void fun(int pos, int last)
{
    if(pos==k+1)
    {
        flag=1;
        cout << "(";
        for(int i=0; i<=k; i++)
        {
            if(i!=0) cout << ",";
            cout << arr[i];
        }
        cout << ")" << endl;
        return;
    }

    for(int i=0; i<v[last].size(); i++)
    {
        int a=v[last][i];
        if(!mark[a])
        {
            arr[pos]=a;
            mark[a]=1;
            fun(pos+1,a);
            mark[a]=0;
        }
    }
}


int main()
{
    int n, a, test=1;

    while(cin >> n >> k)
    {
        if(test!=1) cout << endl;
        test++;

        for(int i=1; i<=n; i++)
        {
            v[i].clear();
            for(int j=1; j<=n; j++)
            {
                cin >> a;
                if(a==1) v[i].push_back(j);
            }
        }

        flag=0;
        arr[0]=1;
        mark[1]=1;
        fun(1,1);
        if(flag==0) cout << "no walk of length " << k << endl;

        cin >> a;
    }

    return 0;
}
