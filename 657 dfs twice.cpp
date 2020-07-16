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

int n, m, x;
char arr[55][55];
bool mark[55][55];

void dfs2(int a, int b)
{
    if(a<0 || b<0 || a==n || b==m || mark[a][b] || arr[a][b]!='X') return;
    arr[a][b]='*';

    dfs2(a+1,b);
    dfs2(a-1,b);
    dfs2(a,b+1);
    dfs2(a,b-1);
}

void dfs1(int a, int b)
{
    if(a<0 || b<0 || a==n || b==m || mark[a][b] || arr[a][b]=='.') return;
    if(arr[a][b]=='X')
    {
        dfs2(a,b);
        x++;
    }
    mark[a][b]=true;

    dfs1(a+1,b);
    dfs1(a-1,b);
    dfs1(a,b+1);
    dfs1(a,b-1);
}

int main()
{
    int test=1;
    vector<int>v;

    while((cin >> m >> n) && m+n)
    {
        memset(mark,0,sizeof(mark));
        v.clear();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]!='.' && !mark[i][j])
                {
                    x=0;
                    dfs1(i,j);
                    v.push_back(x);
                }
            }
        }

        sort(v.begin(),v.end());

        cout << "Throw " << test++ << endl;
        for(int i=0; i<v.size(); i++)
        {
            if(i!=0) cout << " ";
            cout << v[i];
        }
        cout << endl << endl;
    }

    return 0;
}
