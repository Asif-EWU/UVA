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

vector<int>v[202];
bool mark[202];

int bfs(int a)
{
    queue<int>q;
    int level[202]={0};
    int one=0, two=0;
    bool flag=0;

    level[a]=1;
    one++;
    q.push(a);

    while(!q.empty())
    {
        int b=q.front();
        mark[b]=1;
        q.pop();

        for(int i=0; i<v[b].size(); i++)
        {
            int c=v[b][i];
            if(level[b]==level[c] || b==c) flag=1;
            if(level[c]!=0) continue;

            if(level[b]==1)
            {
                two++;
                level[c]=2;
            }
            else
            {
                one++;
                level[c]=1;
            }

            q.push(c);
        }
    }

    if(flag) return 0;
    return max(one,two);
}

int main()
{
    int test, n, m, a;

    cin >> test;
    while(test--)
    {
        int cnt=0;
        memset(mark,0,sizeof(mark));

        cin >> n;
        for(int i=1; i<=n; i++) v[i].clear();

        for(int i=1; i<=n; i++)
        {
            cin >> m;
            for(int j=0; j<m; j++)
            {
                cin >> a;
                if(a<=n)
                {
                    v[i].push_back(a);
                    v[a].push_back(i);
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(!mark[i])
                cnt+=bfs(i);
        }
        cout << cnt << endl;
    }

    return 0;
}
