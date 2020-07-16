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

char c='_', arr[32][90];
bool mark[32][90];
int n, m=85;

bool chk(int a, int b)
{
    for(int i=0; i<4; i++)
    {
        int x=a+fx[i];
        int y=b+fy[i];
        if(arr[x][y]!=' ' && arr[x][y]!='#' && arr[x][y]!='_' && arr[x][y]!='*' && x>=0 && y>=0 && x<n && y<m) return true;
    }
    return false;
}

void dfs(int a, int b)
{
    if(chk(a,b)) arr[a][b]='#';
    if(arr[a][b]=='#')
    {
        int d=b-1;
        while(d>=0)
        {
            if(arr[a][d]!='_') break;
            arr[a][d]=' ';
            d--;
        }
    }
    mark[a][b]=true;

    for(int i=0; i<4; i++)
    {
        int x=a+fx[i];
        int y=b+fy[i];

        if(x>=0 && y>=0 && x<n && y<m && !mark[x][y] && (arr[x][y]==' ' || arr[x][y]=='_'))
            dfs(x,y);
    }
}


int main()
{
    int test;
    string s;

    cin >> test;
    cin.ignore();

    while(test--)
    {
        while(getline(cin,s))
        {
            if(s[0]=='_')
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        if(arr[i][j]=='*' && !mark[i][j])
                        {
                            arr[i][j]=' ';
                            if(arr[i][j+1]=='_')
                            {
                                int w=j;
                                while(w>=0)
                                {
                                    if(arr[i][w]!=' ') break;
                                    arr[i][w]='_';
                                    w--;
                                }
                            }

                            dfs(i,j);
                        }
                    }
                }

                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        if(arr[i][j]!='_')
                        {
                            cout << arr[i][j];
                        }
                    }
                    cout << endl;
                }
                cout << s << endl;

                n=0;
                memset(mark,0,sizeof(mark));
                continue;
            }

            for(int i=s.size()-1; i>=0; i--)
            {
                if(s[i]!=' ') break;
                s[i]='_';
            }
            for(int i=s.size(); i<m; i++) s+=c;
            for(int i=0; s[i]; i++) arr[n][i]=s[i];
            n++;
        }
    }

    return 0;
}
