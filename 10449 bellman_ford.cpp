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
#define PS              system("pause");
#define MOD             998244353
#define M               205
#define MX              1000000000

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>  using ordered_set =
    tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>  using orderedSet =
    tree<pair<int,int>, null_type, less<pair<int,int> >,
    rb_tree_tag, tree_order_statistics_node_update>;
// *s.find_by_order(); s.order_of_key();

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

struct st
{
    int a, b, c;
};

vector<st> G;
int arr[M], d[M];

void Bellman_ford(int source, int n, int m)
{
    int a, b, c;
    bool chk;

    for(int i=1; i<=n; i++) d[i] = MX;
    d[source] = 0;

    for(int i=0; i<n-1; i++)
    {
        chk = false;
        for(int j=0; j<m; j++)
        {
            a = G[j].a;
            b = G[j].b;
            c = G[j].c;

            if(d[a] != MX && d[a] + c < d[b])
            {
                d[b] = d[a] + c;
                chk = true;
            }
        }
        if(!chk) return;
    }

    for(int j=0; j<m; j++)
    {
        a = G[j].a;
        b = G[j].b;
        c = G[j].c;
        if(d[a] != MX && d[a] + c < d[b]) d[b] = -MX;
    }
    return;
}

int main()
{
    int n, m, q, a, b, c, kase = 1;

    while(scanf("%d",&n) == 1)
    {
        G.clear();
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);

        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            c = arr[b] - arr[a];
            c = c * c * c;
            G.push_back({a, b, c});
        }
        Bellman_ford(1, n, m);

        printf("Set #%d\n",kase++);
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            scanf("%d",&a);
            if(d[a] == MX || d[a] < 3) printf("?\n");
            else printf("%d\n",d[a]);
        }
    }

    return 0;
}



