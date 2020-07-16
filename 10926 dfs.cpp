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

vector<int>v[102];
bool mark[102];

int dfs(int a)
{
    int x=0;
    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i];
        if(mark[b]) continue;
        mark[b]=true;
        x+=1+dfs(b);
    }
    return x;
}

int main()
{
    int n, m, a, cnt, mx, index;
    while(cin >> n && n)
    {
        for(int i=1; i<=n; i++) v[i].clear();
        cnt=mx=0;

        for(int i=0; i<n; i++)
        {
            cin >> m;
            for(int j=0; j<m; j++)
            {
                cin >> a;
                v[i+1].push_back(a);
            }
        }

        for(int i=1; i<=n; i++)
        {

            memset(mark,0,sizeof(mark));
            cnt=dfs(i);
            if(cnt>mx)
            {
                mx=cnt;
                index=i;
            }
        }
        cout << index << endl;
    }

    return 0;
}
