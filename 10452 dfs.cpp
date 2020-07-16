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

char arr[10][10];
int n, m;
map<char,int>mp;
vector<string>v;

void dfs(int x, int y)
{
    char c;

    if(x-1>=0 && x-1<n)
    {
        c=arr[x-1][y];
        if(mp[c]==1)
        {
            v.pb("forth");
            arr[x-1][y]='X';
            dfs(x-1,y);
        }
    }
    if(y+1>=0 && y+1<m)
    {
        c=arr[x][y+1];
        if(mp[c]==1)
        {
            v.pb("right");
            arr[x][y+1]='X';
            dfs(x,y+1);
        }
    }
    if(y-1>=0 && y-1<m)
    {
        c=arr[x][y-1];
        if(mp[c]==1)
        {
            v.pb("left");
            arr[x][y-1]='X';
            dfs(x,y-1);
        }
    }
}


int main()
{
    int test, x, y;
    mp['I']=1;
    mp['E']=1;
    mp['H']=1;
    mp['O']=1;
    mp['V']=1;
    mp['A']=1;
    mp['#']=1;

    cin >> test;
    while(test--)
    {
        v.clear();

        cin >> n >> m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        }

        dfs(x,y);
        for(int i=0; i<v.size(); i++)
        {
            if(i!=0) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}
