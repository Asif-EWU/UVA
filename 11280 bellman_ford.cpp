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
#define MX              50005

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

int cost[105], n, m;
vector<st> G;
map<string, int> mp;

bool cmp(st x, st y)
{
    return x.b > y.b;
}

void Bellman_ford()
{
    int a, b, c, d[105];

    d[1] = 0;
    for(int i=2; i<=n; i++) d[i] = INT_MAX;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            a = G[j].a;
            b = G[j].b;
            c = G[j].c;
            if(d[a] != INT_MAX && d[a] + c < d[b]) d[b] = d[a] + c;
        }
        cost[i] = d[n];
    }
}

int main()
{
    int test, q, a;
    string s1, s2;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        G.clear();
        mp.clear();

        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> s1;
            mp[s1] = i;
            cost[i] = INT_MAX;
        }
        cost[0] = INT_MAX;

        cin >> m;
        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2 >> a;
            G.push_back({mp[s1], mp[s2], a});
        }
        sort(G.begin(), G.end(), cmp);
        Bellman_ford();

        if(t != 1) cout << endl;
        cout << "Scenario #" << t << endl;

        cin >> q;
        for(int i=0; i<q; i++)
        {
            cin >> a;
            a = min(a, n-2);
            if(cost[a] == INT_MAX) cout << "No satisfactory flights" << endl;
            else cout << "Total cost of flight(s) is $" << cost[a] << endl;
        }
    }

    return 0;
}




