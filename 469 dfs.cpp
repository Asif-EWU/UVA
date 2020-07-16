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
int n, m;
char arr[102][102];
bool mark[102][102];

int dfs(int a, int b)
{
    mark[a][b]=true;
    int x=0;

    for(int i=0; i<8; i++)
    {
        int tx=a+fx[i];
        int ty=b+fy[i];

        if(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]=='W' && !mark[tx][ty])
        {
            x+=1+dfs(tx,ty);
        }
    }

    return x;
}

int main()
{
    int test, a, b;
    string s;

    scanf("%d\n\n",&test);
    for(int t=0; t<test; t++)
    {
        if(t!=0) printf("\n");
        n=0;

        while(getline(cin,s) && s!="")
        {
            if(s[0]=='L' || s[0]=='W')
            {
                for(int i=0; s[i]; i++)
                {
                    arr[n][i]=s[i];
                }
                n++;
                m=s.size();
            }

            else
            {
                memset(mark,0,sizeof(mark));
                stringstream ss(s);
                ss >> a >> b;
                printf("%d\n",dfs(a-1,b-1)+1);
            }
        }
    }

    return 0;
}
