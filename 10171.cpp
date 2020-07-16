#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             9223372036854775807
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

int arr1[100][100];
int arr2[100][100];

void floyd_warshall_1()
{
    for(int k=65; k<=90; k++)
    {
        for(int i=65; i<=90; i++)
        {
            for(int j=65; j<=90; j++)
            {
                if(arr1[i][j]>arr1[i][k]+arr1[k][j])
                {
                    arr1[i][j]=arr1[i][k]+arr1[k][j];
                }
            }
        }
    }
}

void floyd_warshall_2()
{
    for(int k=65; k<=90; k++)
    {
        for(int i=65; i<=90; i++)
        {
            for(int j=65; j<=90; j++)
            {
                if(arr2[i][j]>arr2[i][k]+arr2[k][j])
                {
                    arr2[i][j]=arr2[i][k]+arr2[k][j];
                }
            }
        }
    }
}

int main()
{
    int n, mn, x;
    char a, b, c, d;
    bool chk;

    while(scanf("%d",&n)&&n)
    {
        for(int i=65; i<=90; i++)
        {
            for(int j=65; j<=90; j++)
            {
                if(i==j)
                    arr1[i][j]=arr2[i][j]=arr1[j][i]=arr2[j][i]=0;
                else
                    arr1[i][j]=arr2[i][j]=arr1[j][i]=arr2[j][i]=M;
            }
        }

        for(int t=0; t<n; t++)
        {
            scanf(" %c %c %c %c %d",&a,&b,&c,&d,&x);

            if(a=='Y')
            {
                if(b=='B')
                    arr1[c][d]=arr1[d][c]=x;
                else
                    arr1[c][d]=x;
            }

            else
            {
                if(b=='B')
                    arr2[c][d]=arr2[d][c]=x;
                else
                    arr2[c][d]=x;
            }
        }

        floyd_warshall_1();
        floyd_warshall_2();

        scanf(" %c %c",&a,&b);

        chk=false;
        mn=M;

        for(int i=65; i<=90; i++)
        {
            if(arr1[a][i]!=M && arr2[b][i]!=M)
            {
                chk=true;
                mn=min(mn,arr1[a][i]+arr2[b][i]);
            }
        }

        if(!chk)
            pf("You will never meet.\n");
        else
        {
            if(a==b)
            {
                pf("0 %c",a);
            }
            else
                pf("%d",mn);

            for(int i=65; i<=90; i++)
            {
                if(a==b && i==a)
                    continue;

                if(arr1[a][i]+arr2[b][i]==mn)
                {
                    c=i;
                    pf(" %c",c);
                }
            }
            pf("\n");
        }
    }

    return 0;
}
