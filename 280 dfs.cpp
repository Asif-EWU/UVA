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

vector<int>v[105];
bool visited[105];

void dfs(int n)
{
    for(int i=0; i<v[n].size(); i++)
    {
        int a=v[n][i];
        if(!visited[a])
        {
            visited[a]=true;
            dfs(a);
        }
    }
}

int32_t main()
{
    sync;
    int n, a, b, cnt;

    while(cin >> n && n!=0)
    {
        for(int i=1; i<=n; i++) v[i].clear();

        while(cin >> a && a!=0)
        {
            while(cin >> b && b!=0)
            {
                v[a].pb(b);
            }
        }

        cin >> a;
        for(int i=0; i<a; i++)
        {
            memset(visited,0,sizeof(visited));
            cnt=0;
            vector<int>v1;

            cin >> b;
            dfs(b);
            for(int i=1; i<=n; i++)
            {
                if(!visited[i])
                {
                    cnt++;
                    v1.pb(i);
                }
            }
            cout << cnt;
            for(int i=0; i<cnt; i++)
            {
                cout << " " << v1[i];
            }
            cout << endl;
        }
    }

    return 0;
}

