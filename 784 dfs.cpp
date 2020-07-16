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
char c='_';

void dfs(int a, int b)
{
    if(a<0 || a==n || b<0 || b==m) return;
    if(arr[a][b]!=' ') return;
    arr[a][b]='#';

    dfs(a+1,b);
    dfs(a-1,b);
    dfs(a,b+1);
    dfs(a,b-1);
}

int main()
{
    int test;
    string s;

    scanf("%d\n",&test);
    while(test--)
    {
        int a, b;
        n=0;

        while(getline(cin,s) && s[0]!='_')
        {
            for(int i=s.size(); i<80; i++) s+=c;
            for(int i=0; s[i]; i++)
            {
                arr[n][i]=s[i];
                if(s[i]=='*')
                {
                    a=n;
                    b=i;
                }
            }
            n++;
        }

        arr[a][b]=' ';
        dfs(a,b);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]!=c)
                    cout << arr[i][j];
            }
            cout << endl;
        }
        cout << s << endl;
    }

    return 0;
}
