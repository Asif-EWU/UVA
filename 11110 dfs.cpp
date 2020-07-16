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
int arr[102][102];
bool mark[102][102];
int n;

int dfs(int a, int b, int c)
{
    mark[a][b]=true;
    int x=0;

    for(int i=0; i<4; i++)
    {
        int p=a+fx[i];
        int q=b+fy[i];

        if(p>0 && q>0 && p<=n && q<=n && !mark[p][q] && arr[p][q]==c)
        {
            x+=1+dfs(p,q,c);
        }
    }

    return x;
}


int main()
{
    int a, b, cnt;
    bool flag;
    string s;

    while(cin >> n && n)
    {
        cin.ignore();
        memset(arr,0,sizeof(arr));
        memset(mark,0,sizeof(mark));

        for(int i=1; i<n; i++)
        {
            getline(cin,s);
            stringstream ss(s);
            while(ss >> a >> b)
            {
                arr[a][b]=i;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][j]==0)
                {
                    arr[i][j]=n;
                }
            }
        }

        flag=true;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(!mark[i][j])
                {
                    cnt=1+dfs(i,j,arr[i][j]);
                    if(cnt!=n)
                    {
                        flag=false;
                        break;
                    }
                }
            }

            if(!flag) break;
        }

        if(!flag) cout << "wrong" << endl;
        else cout << "good" << endl;
    }

    return 0;
}
