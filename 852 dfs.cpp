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

char arr[12][12];
bool mark[12][12];
int x, y, z;

void dfs(int a, int b)
{
    if(arr[a][b]=='X') x++;
    if(arr[a][b]=='O') y++;
    if(a<0 || b<0 || a==9 || b==9 || arr[a][b]!='.' || mark[a][b]) return;

    mark[a][b]=true;
    z++;

    dfs(a+1,b);
    dfs(a-1,b);
    dfs(a,b+1);
    dfs(a,b-1);
}


int main()
{
    int board, n=0, black=0, white=0;
    string s;

    cin >> board;
    while(board--)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]=='X') black++;
                if(arr[i][j]=='O') white++;
            }
        }

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(arr[i][j]=='.' && !mark[i][j])
                {
                    x=y=z=0;
                    dfs(i,j);
                    if(x==0 && y!=0) white+=z;
                    if(y==0 && x!=0) black+=z;
                }
            }
        }

        printf("Black %d White %d\n",black,white);

        n=black=white=0;
        memset(mark,0,sizeof(mark));
    }

    return 0;
}
