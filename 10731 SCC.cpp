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
#define M               2000
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

string str;
vector<int> v1[30], v2[30];
bool color[30];
stack<int> stak;

void dfs1(int a)
{
    color[a] = 1;
    for(int i=0; i<v1[a].size(); i++) if(!color[v1[a][i]]) dfs1(v1[a][i]);
    stak.push(a);
}

void dfs2(int a)
{
    color[a] = 1;
    for(int i=0; i<v2[a].size(); i++) if(!color[v2[a][i]]) dfs2(v2[a][i]);
    str += (a + 'A' - 1);
}

int main()
{
    int test = 0, n, p, q, r, s, t, u;
    char a, b, c, d, e, f;
    vector<string> arr;
    set<int> st;

    while(cin >> n && n)
    {
        if(test) cout << endl;
        test++;

        memset(color, 0, sizeof(color));
        for(int i=1; i<=26; i++) v1[i].clear(), v2[i].clear();
        arr.clear();
        st.clear();

        for(int i=0; i<n; i++)
        {
            cin >> a >> b >> c >> d >> e >> f;

            p = a - 'A' + 1;
            q = b - 'A' + 1;
            r = c - 'A' + 1;
            s = d - 'A' + 1;
            t = e - 'A' + 1;
            u = f - 'A' + 1;

            v1[u].push_back(p);
            v1[u].push_back(q);
            v1[u].push_back(r);
            v1[u].push_back(s);
            v1[u].push_back(t);

            v2[p].push_back(u);
            v2[q].push_back(u);
            v2[r].push_back(u);
            v2[s].push_back(u);
            v2[t].push_back(u);

            st.insert(p);
            st.insert(q);
            st.insert(r);
            st.insert(s);
            st.insert(t);
        }

        for(auto i : st) if(!color[i]) dfs1(i);
        memset(color, 0, sizeof(color));

        while(!stak.empty())
        {
            p = stak.top();
            stak.pop();
            if(!color[p])
            {
                str.clear();
                dfs2(p);
                sort(str.begin(), str.end());
                arr.push_back(str);
            }
        }

        sort(arr.begin(), arr.end());
        for(auto i : arr)
        {
            for(int j=0; j<i.size(); j++)
            {
                if(j) cout << " ";
                cout << i[j];
            }
            cout << endl;
        }
    }

    return 0;
}
