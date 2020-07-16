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
#define MX              100000

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

char parent[95];
int rnk[95];

void initializeSet(char c)
{
    for(int i='A'; i<=c; i++)
    {
        parent[i]=i;
        rnk[i]=0;
    }
}

char find_parent(char x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x]=find_parent(parent[x]);
}

int unionSet(char x, char y)
{
    char px=find_parent(x);
    char py=find_parent(y);

    if(px==py)
        return 0;
    else if(rnk[px]<rnk[py])
        parent[px]=py;
    else if(rnk[px]>rnk[py])
        parent[py]=px;
    else
    {
        parent[py]=px;
        rnk[px]++;
    }
    return 1;
}


int main()
{
    int test, ans;
    string s;
    char a, b, c;

    scanf("%d\n\n",&test);
    for(int t=1; t<=test; t++)
    {
        if(t!=1)
            nl;

        getline(cin,s);
        c=s[0];
        ans=c-'A'+1;
        initializeSet(c);

        while(1)
        {
            if(!getline(cin,s) || s.empty())
                break;

            stringstream ss;
            ss << s;
            ss >> a >> b;
            ans-=unionSet(a,b);
        }

        pf("%d\n",ans);
    }

    return 0;
}
