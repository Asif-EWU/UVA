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

int n, ch, d;
bool mark[30][30];
bool used[30];
bool flag;
string s;
vector<int>v[30];

void dfs(int a, int b)
{
    if(a!=b) mark[a][b]=1;
    for(int i=0; i<v[b].size(); i++) dfs(a,v[b][i]);
}

void fun(int pos, string str)
{
    if(pos==n)
    {
        cout << str << endl;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(used[i]) continue;

        flag=true;
        ch=s[i]-'a';

        for(int j=0; j<pos; j++)
        {
            d=str[j]-'a';
            if(mark[ch][d])
            {
                flag=false;
                break;
            }
        }
        if(!flag) return;

        used[i]=1;
        fun(pos+1,str+s[i]);
        used[i]=0;
    }
}


int main()
{
    int test=1;
    string s1;
    while(getline(cin,s1))
    {
        if(test!=1) cout << endl;
        test++;

        for(int i=0; i<26; i++) v[i].clear();
        s.clear();
        memset(mark,0,sizeof(mark));

        for(int i=0; i<s1.size(); i+=2) s.push_back(s1[i]);
        sort(s.begin(),s.end());
        n=s.size();

        getline(cin,s1);
        for(int i=0; i<s1.size(); i+=4) v[s1[i]-'a'].push_back(s1[i+2]-'a');

        for(int i=0; i<26; i++) dfs(i,i);
        fun(0,"");
    }

    return 0;
}
