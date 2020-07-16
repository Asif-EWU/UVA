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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             100000007
#define M               1000007
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

int arr[102][102];
int brr[102][102];
int n, x, y;

void reset()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            brr[i][j]=arr[i][j];
}

bool chk()
{
    int sum1=0, sum2=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum1+=brr[i][j];
        }
        if(sum1%2!=0) return false;
        sum1=0;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum2+=brr[j][i];
        }
        if(sum2%2!=0) return false;
        sum2=0;
    }

    return true;
}

int32_t main()
{
    sync;

    while(cin >> n && n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> arr[i][j];
            }
        }

        reset();
        if(chk())
        {
            cout << "OK" << endl;
            continue;
        }

        int flag=false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                reset();
                brr[i][j]=1-brr[i][j];
                if(chk())
                {
                    cout << "Change bit (" << i+1 << "," << j+1 << ")" << endl;
                    flag=true;
                    break;
                }
            }

            if(flag) break;
        }
        if(!flag) cout << "Corrupt" << endl;
    }

    return 0;
}
