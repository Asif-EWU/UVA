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

int n;
char arr[30][30];
bool visited[30][30];

void dfs(int a, int b)
{
    if(a<0 || b<0 || a==n || b==n || arr[a][b]=='0' || visited[a][b]) return;
    visited[a][b]=true;

    dfs(a+1,b+1);
    dfs(a+1,b+0);
    dfs(a+1,b-1);
    dfs(a+0,b-1);
    dfs(a-1,b-1);
    dfs(a-1,b+0);
    dfs(a-1,b+1);
    dfs(a+0,b+1);
}

int main()
{
    int test=1, cnt;

    while(cin >> n)
    {
        memset(visited,0,sizeof(visited));
        cnt=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && arr[i][j]=='1')
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",test++,cnt);
    }

    return 0;
}
