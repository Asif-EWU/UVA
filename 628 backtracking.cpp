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

vector<string>v;
string str;
int n, sz;

void fun(int pos, string s)
{
    if(pos==sz)
    {
        cout << s << endl;
        return;
    }

    if(str[pos]=='#')
    {
        for(int i=0; i<v.size(); i++)
            fun(pos+1,s+v[i]);
    }
    if(str[pos]=='0')
    {
        for(int i='0'; i<='9'; i++)
        {
            char c=i;
            fun(pos+1,s+c);
        }
    }
}


int main()
{
    int m;
    string s;

    while(cin >> n)
    {
        v.clear();
        cout << "--\n";

        for(int i=0; i<n; i++)
        {
            cin >> s;
            v.push_back(s);
        }

        cin >> m;
        for(int i=0; i<m; i++)
        {
            cin >> str;
            sz=str.size();
            fun(0,"");
        }
    }

    return 0;
}
