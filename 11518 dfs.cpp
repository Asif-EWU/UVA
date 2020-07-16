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
#define MOD             100000007
#define M               1000000000000000000
#define MX              505

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

vector<int>v[10005];
bool mark[10005];

void dfs(int a)
{
    mark[a]=true;

    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i];
        if(!mark[b]) dfs(b);
    }
}

int main()
{
    int test, n, m, l, a, b, cnt;

    cin >> test;
    while(test--)
    {
        cin >> n >> m >> l;

        cnt=0;
        for(int i=1; i<=n; i++) v[i].clear();
        memset(mark,0,sizeof(mark));

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            v[a].pb(b);
        }

        for(int i=0; i<l; i++)
        {
            cin >> a;
            if(!mark[a]) dfs(a);
        }

        for(int i=1; i<=n; i++)
        {
            if(mark[i])
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
