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

vector<int>vec[202];
bool mark[202];

int bfs(int a)
{
    bool x=0, y=0;
    int u=0, v=0;
    queue<int>q;
    int level[202]={0};

    level[a]=1;
    u++;
    q.push(a);

    while(!q.empty())
    {
        int b=q.front();
        q.pop();
        mark[b]=1;

        for(int i=0; i<vec[b].size(); i++)
        {
            int c=vec[b][i];

            if(b==c)
            {
                if(level[b]==1) x=1;
                if(level[b]==2) y=1;
            }
            if(level[b]==level[c]) x=y=1;
            if(level[c]!=0) continue;

            if(level[b]==1) v++, level[c]=2;
            if(level[b]==2) u++, level[c]=1;
            q.push(c);
        }
    }

    if(x && y) return -1;
    if(x) return v;
    if(y || v==0) return u;
    return min(u,v);
}

int main()
{
    int test, n, m, a, b, cnt, res;

    cin >> test;
    while(test--)
    {
        cin >> n >> m;

        for(int i=0; i<n; i++) vec[i].clear();
        memset(mark,0,sizeof(mark));
        cnt=0;

        for(int i=0; i<m; i++)
        {
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        for(int i=0; i<n; i++) if(!mark[i])
        {
            res=bfs(i);
            if(res==-1) break;
            cnt+=res;
        }

        if(res==-1) cout << -1 << endl;
        else cout << cnt << endl;
    }

    return 0;
}
