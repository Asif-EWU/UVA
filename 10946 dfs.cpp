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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char arr[55][55];
bool mark[55][55];
int n, m;

bool cmp(pair<char,int>x, pair<char,int>y)
{
    if(x.second == y.second)
        return x.first < y.first;
    return x.second > y.second;
}

int dfs(int a, int b, char c)
{
    int z=0;
    mark[a][b]=true;

    for(int i=0; i<4; i++)
    {
        int x=a+fx[i];
        int y=b+fy[i];

        if(x>=0 && y>=0 && x<n && y<m && !mark[x][y] && arr[x][y]==c)
        {
            z+=1+dfs(x,y,c);
        }
    }

    return z;
}

int main()
{
    int test=1, cnt;

    while((cin >> n >> m) && n+m)
    {
        memset(mark,0,sizeof(mark));
        vector<pair<char,int> >v;

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
                if(!mark[i][j] && arr[i][j]!='.')
                {
                    cnt=1+dfs(i,j,arr[i][j]);
                    v.push_back(make_pair(arr[i][j],cnt));
                }
            }
        }
        sort(v.begin(),v.end(),cmp);

        printf("Problem %d:\n",test++);
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }

    return 0;
}
