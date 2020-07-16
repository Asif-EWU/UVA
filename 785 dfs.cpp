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

int n, m=80;
char arr[35][85];
bool mark[35][85];
char c='_', d;

void dfs(int a, int b, char ch)
{
    if(a<0 || b<0 || a==n || b==m || mark[a][b] || arr[a][b]==d || arr[a][b]=='_') return;
    mark[a][b]=true;
    arr[a][b]=ch;

    dfs(a+1,b,ch);
    dfs(a-1,b,ch);
    dfs(a,b+1,ch);
    dfs(a,b-1,ch);
}


int main()
{
    string s;
    n=0;

    while(getline(cin,s))
    {
        if(s[0]=='_')
        {
            for(int i=0; i<80; i++)
            {
                if(arr[0][i]!='_' && arr[0][i]!=' ')
                {
                    d=arr[0][i];
                    break;
                }
            }

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<80; j++)
                {
                    if(!mark[i][j] && arr[i][j]!=d && arr[i][j]!=' ' && arr[i][j]!='_')
                    {
                        dfs(i,j,arr[i][j]);
                    }
                }
            }

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<80; j++)
                {
                    if(arr[i][j]!='_') cout << arr[i][j];
                }
                cout << endl;
            }
            cout << s << endl;

            n=0;
            memset(mark,0,sizeof(mark));
            continue;
        }

        for(int i=s.size(); i<80; i++) s+=c;
        for(int i=0; s[i]; i++) arr[n][i]=s[i];
        n++;
    }

    return 0;
}
