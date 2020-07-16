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

struct st
{
    char c;
    int a;
    st(char _c, int _a)
    {
        c=_c;
        a=_a;
    }
};
bool operator<(st x, st y)
{
    if(x.a==y.a)
        return x.c<y.c;
    return x.a>y.a;
}


int n, m;
char arr[1000][1000];
bool mark[1000][1000];

void dfs(int a, int b, char c)
{
    if(a<0 || b<0 || a==n || b==m || arr[a][b]!=c || mark[a][b]) return;
    mark[a][b]=true;

    dfs(a+1,b,c);
    dfs(a-1,b,c);
    dfs(a,b+1,c);
    dfs(a,b-1,c);
}


int main()
{
    int test;
    map<char,int>mp;
    map<char,int>::iterator it;
    vector<st>v;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        memset(mark,0,sizeof(mark));
        mp.clear();
        v.clear();

        cin >> n >> m;
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
                if(!mark[i][j])
                {
                    dfs(i,j,arr[i][j]);
                    mp[arr[i][j]]++;
                }
            }
        }

        for(it=mp.begin(); it!=mp.end(); it++)
        {
            v.push_back(st(it->first,it->second));
        }
        sort(v.begin(),v.end());

        printf("World #%d\n",t);

        for(int i=0; i<v.size(); i++)
        {
            printf("%c: %d\n",v[i].c,v[i].a);
        }
    }

    return 0;
}
