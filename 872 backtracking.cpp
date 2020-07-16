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
#define M               1000000000
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

int sz;
string s;
bool mark[30][30], used[30];
vector<string>v;

void fun(int pos, string str)
{
    if(pos==sz)
    {
        v.push_back(str);
        return;
    }

    for(int i=0; i<sz; i++)
    {
        if(!used[i])
        {
            bool flag=1;
            int a=s[i]-'A';
            for(int j=0; j<str.size(); j++)
            {
                int b=str[j]-'A';
                if(mark[a][b])
                {
                    flag=0;
                    break;
                }
            }

            if(flag)
            {
                used[i]=1;
                fun(pos+1,str+s[i]);
                used[i]=0;
            }
        }
    }
}

int main()
{
    int test;
    string s1;

    cin >> test;
    cin.ignore();

    for(int t=0; t<test; t++)
    {
        cin.ignore();
        memset(mark,0,sizeof(mark));
        v.clear();
        s.clear();

        getline(cin,s1);
        for(int i=0; i<s1.size(); i+=2) s.push_back(s1[i]);
        sort(s.begin(),s.end());
        sz=s.size();

        getline(cin,s1);
        for(int i=0; i<s1.size(); i+=4) mark[s1[i]-'A'][s1[i+2]-'A']=1;

        fun(0,"");

        if(t) cout << endl;
        if(v.size()==0) cout << "NO" << endl;
        else
        {
            for(int i=0; i<v.size(); i++)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    if(j) cout << " ";
                    cout << v[i][j];
                }
                cout << endl;
            }
        }
    }

    return 0;
}
