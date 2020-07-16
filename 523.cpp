#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

int arr[205][205];
int nxt[205][205];
int cost[205];

void floyd_warshall(int n)
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j]+cost[k])
                {
                    arr[i][j]=arr[i][k]+arr[k][j]+cost[k];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }
}

void print_path(int a, int b)
{
    pf("%d",a);
    while(a!=b)
    {
        a=nxt[a][b];
        pf("-->%d",a);
    }
}


int main()
{
    int test, a, b, cnt, x, y;
    string str;

    scanf("%d",&test);
    getline(cin,str);

    cin.ignore();
    for(int t=1; t<=test; t++)
    {
        if(t!=1)
            pf("\n");

        getline(cin,str);
        stringstream ss1;
        ss1 << str;

        cnt=0;
        while(ss1 >> a)
            cnt++;

        stringstream ss;
        ss << str;
        x=1, y=1;
        while(ss >> a)
        {
            if(a==-1)
                arr[x][y]=M;
            else
                arr[x][y]=a;

            nxt[x][y]=y;
            y++;
        }

        for(int i=2; i<=cnt; i++)
        {
            for(int j=1; j<=cnt; j++)
            {
                scanf("%d",&a);
                if(a==-1)
                    arr[i][j]=M;
                else
                    arr[i][j]=a;

                nxt[i][j]=j;
            }
        }

        for(int i=1; i<=cnt; i++)
        {
            scanf("%d",&a);
            cost[i]=a;
        }

        floyd_warshall(cnt);

        cin.ignore();
        for(int i=0; ; i++)
        {
            getline(cin,str);
            if(str=="")
                break;
            else if(i!=0)
                pf("\n");

            stringstream ss2;
            ss2 << str;
            ss2 >> a >> b;

            pf("From %d to %d :\n",a,b);
            pf("Path: ");
            print_path(a,b);
            pf("\nTotal cost : %d\n",arr[a][b]);
        }
    }

    return 0;
}
