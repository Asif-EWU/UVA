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
#define M               1000
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

bool color[M+10];
vector<string> arr(M+10);
vector<int> v1[M+10], v2[M+10];
stack<int> st1;
map<string, int> mp;

void dfs1(int a)
{
    color[a] = 1;
    for(int i=0; i<v1[a].size(); i++) if(!color[v1[a][i]]) dfs1(v1[a][i]);
    st1.push(a);
}

void dfs2(int a)
{
    color[a] = 1;
    for(int i=0; i<v2[a].size(); i++) if(!color[v2[a][i]]) dfs2(v2[a][i]);
}

int main()
{
    //fin;
    int n, m, cnt;
    string s1, s2;

    while(cin >> n >> m && n+m)
    {
        for(int i=1; i<=n; i++) color[i] = 0, v1[i].clear(), v2[i].clear();
        mp.clear();
        cnt = 0;

        cin.ignore();

        for(int i=1; i<=n; i++)
        {
            getline(cin, s1);
            mp[s1] = i;
        }

        for(int i=0; i<m; i++)
        {
            getline(cin, s1);
            getline(cin, s2);
            v1[mp[s1]].push_back(mp[s2]);
            v2[mp[s2]].push_back(mp[s1]);
        }

        for(int i=1; i<=n; i++) if(!color[i]) dfs1(i);
        for(int i=1; i<=n; i++) color[i] = 0;

        while(!st1.empty())
        {
            int a = st1.top();
            st1.pop();
            if(!color[a])
            {
                dfs2(a);
                cnt++;
            }
        }

        cout << cnt << endl;
    }


    return 0;
}
