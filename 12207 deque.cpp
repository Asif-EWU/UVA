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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000
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


int32_t main()
{
    sync;
    int n, m, a, b, kase=0;
    char c;

    while(cin >> n >> m && n+m)
    {
        deque<int>q;
        map<int,int>mp;

        for(int i=1; i<=min(n,m); i++)
        {
            q.push_back(i);
            mp[i]=1;
        }

        cout << "Case " << ++kase << ":" << endl;
        for(int i=0; i<m; i++)
        {
            cin >> c;
            if(c=='N')
            {
                b=q.front();
                q.pop_front();
                cout << b << endl;
                q.push_back(b);
            }
            else
            {
                cin >> a;

                if(mp[a]==0)
                {
                    q.push_front(a);
                    mp[a]=1;
                }
                else
                {
                    stack<int> st;
                    while(1)
                    {
                        b=q.front();
                        q.pop_front();
                        if(b==a) break;
                        st.push(b);
                    }

                    while(!st.empty())
                    {
                        b=st.top();
                        st.pop();
                        q.push_front(b);
                    }

                    q.push_front(a);
                }
            }
        }
    }

    return 0;
}
