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

vector<int>v;
vector<int>arr[1000005];
int indegree[1000005];
bool mark[1000005];

void dfs(int a)
{
    mark[a]=1;
    for(int i=0; i<arr[a].size(); i++)
    {
        if(!mark[arr[a][i]])
            dfs(arr[a][i]);
    }
    v.push_back(a);
}


int main()
{
    int n, m, a, b;

    while(cin >> n >> m && n+m)
    {
        v.clear();
        for(int i=1; i<=n; i++) arr[i].clear();
        memset(indegree,0,sizeof(indegree));
        memset(mark,0,sizeof(mark));

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            indegree[b]++;
            arr[a].push_back(b);
        }

        for(int i=1; i<=n; i++) if(indegree[i]==0) dfs(i);

        if(v.size()==0) cout << "IMPOSSIBLE" << endl;
        else for(int i=v.size()-1; i>=0; i--) cout << v[i] << endl;

    }

    return 0;
}
