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
#define M               100005
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

vector<int>v[M];
bool mark[M];
vector<pair<int,int> >vec;
int d;

void dfs(int a)
{
    mark[a]=true;

    for(int i=0; i<v[a].size(); i++)
    {
        int b=v[a][i];
        if(!mark[b]) dfs(b);
    }

    vec.push_back(make_pair(d++,a));
}

void dfs1(int a)
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
    int test, n, m, a, b, cnt;

    cin >> test;
    while(test--)
    {
        cin >> n >> m;

        for(int i=1; i<=n; i++) v[i].clear();
        memset(mark,0,sizeof(mark));
        vec.clear();
        d=cnt=0;

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
        }

        for(int i=1; i<=n; i++)
        {
            if(!mark[i])
            {
                dfs(i);
            }
        }
        sort(vec.begin(),vec.end());

        memset(mark,0,sizeof(mark));
        for(int i=n-1; i>=0; i--)
        {
            a=vec[i].second;
            if(!mark[a])
            {
                dfs1(a);
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
