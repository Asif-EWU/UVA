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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             100000007
#define M               1000000000000
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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char arr[105][105];
int u, v;

void bfs1(int x, int y, int r, int c)
{
    queue<pair<int,int> >q;
    bool visited[105][105]={0};
    int level[105][105];
    int mx=1;

    visited[x][y]=true;
    level[x][y]=1;
    u=x, v=y;
    q.push(make_pair(x,y));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();

        int a=p.first;
        int b=p.second;

        for(int i=0; i<4; i++)
        {
            int tx=a+fx[i];
            int ty=b+fy[i];

            if(!visited[tx][ty] && arr[tx][ty]=='0' && tx>0 && ty>0 && tx<=r && ty<=c)
            {
                visited[tx][ty]=true;
                level[tx][ty]=level[a][b]+1;
                q.push(make_pair(tx,ty));

                if(level[tx][ty]>mx)
                {
                    mx=level[tx][ty];
                    u=tx;
                    v=ty;
                }
            }
        }
    }
}

int bfs2(int r, int c)
{
    queue<pair<int,int> >q;
    bool visited[105][105]={0};
    int level[105][105];
    int cnt=1;

    visited[u][v]=true;
    level[u][v]=1;
    q.push(make_pair(u,v));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();

        int a=p.first;
        int b=p.second;

        for(int i=0; i<4; i++)
        {
            int tx=a+fx[i];
            int ty=b+fy[i];

            if(!visited[tx][ty] && arr[tx][ty]=='0' && tx>0 && ty>0 && tx<=r && ty<=c)
            {
                visited[tx][ty]=true;
                level[tx][ty]=level[a][b]+1;
                q.push(make_pair(tx,ty));
                cnt++;
            }
        }
    }

    return cnt;
}


int main()
{
    int test, x1, y1, n, d;
    string s;

    scanf("%d\n\n",&test);
    for(int t=1; t<=test; t++)
    {
        scanf("%d %d\n",&x1,&y1);
        d=1;

        while(getline(cin,s))
        {
            if(s=="") break;
            n=s.size();
            for(int i=1; i<=n; i++) arr[d][i]=s[i-1];
            d++;
        }
        bfs1(x1,y1,d-1,n);

        if(t!=1) printf("\n");
        printf("%d\n",bfs2(d-1,n));
    }

    return 0;
}
