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
#define MX              30005

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

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------


int main()
{
    int test, p, t, a, b, ok, cnt;
    string s;

    scanf("%d",&test);
    for(int t1=1; t1<=test; t1++)
    {
        if(t1!=1)
            nl;

        bool arr[103][103]={0};
        scanf("%d %d\n",&p, &t);

        while(1)
        {
            getline(cin,s);
            if(s=="")
                break;
            stringstream ss;
            ss << s;
            ss >> a >> b;
            arr[a][b]=true;
        }

        cnt=0;
        for(int i=1; i<=p; i++)
        {
            ok=0;
            for(int j=i+1; j<=p; j++)
            {
                for(int k=1; k<=t; k++)
                {
                    if(arr[i][k]!=arr[j][k])
                    {
                        ok++;
                        break;
                    }
                }
            }

            if(ok==p-i)
                cnt++;
        }

        pf("%d\n",cnt);
    }

    return 0;
}
