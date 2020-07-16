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

int arr1[28][28];
int arr2[28][28];

bool floyd_warshall()
{
    for(int k=1; k<=26; k++)
    {
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=26; j++)
            {
                arr1[i][j]= (arr1[i][j] || (arr1[i][k] && arr1[k][j]));
                arr2[i][j]= (arr2[i][j] || (arr2[i][k] && arr2[k][j]));
            }
        }
    }

    for(int i=1; i<=26; i++)
    {
        for(int j=1; j<=26; j++)
        {
            if(arr1[i][j]!=arr2[i][j])
                return false;
        }
    }

    return true;
}


int main()
{
    map<char,int>mp;
    int d=1;
    char c='A';
    while(c<='Z')
    {
        mp[c]=d++;
        c++;
    }


    int test, n, m;
    char a, b;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        if(t!=1)
            nl;

        bool chk;
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));

        fs(n);
        while(n--)
        {
            scanf(" %c %c",&a,&b);
            arr1[mp[a]][mp[b]]=arr1[mp[b]][mp[a]]=1;
        }

        fs(m);
        while(m--)
        {
            scanf(" %c %c",&a,&b);
            arr2[mp[a]][mp[b]]=arr2[mp[b]][mp[a]]=1;
        }

        chk=floyd_warshall();

        if(chk)
            pf("YES\n");
        else
            pf("NO\n");
    }

    return 0;
}
