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

int fx[]={1,1,1,0,-1,-1,-1,0};
int fy[]={1,0,-1,-1,-1,0,1,1};
char arr[104][104];
int mark[104][104];
int n, m;

void dfs(int a, int b)
{
    mark[a][b]=1;

    for(int i=0; i<8; i++)
    {
        int x=a+fx[i];
        int y=b+fy[i];

        if(x>=0 && x<m && y>=0 && y<n && mark[x][y]==0 && arr[x][y]=='@')
        {
            dfs(x,y);
        }
    }
}


int main()
{
    int cnt;

    while(cin >> m && m!=0)
    {
        cin >> n;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> arr[i][j];
                mark[i][j]=0;
            }
        }

        cnt=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]=='@' && mark[i][j]==0)
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
