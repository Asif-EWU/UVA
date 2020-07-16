/*
........................................................
........................................................
তুমি ছেলেহারা মা জাহানারা ইমামের একাক্তরের দিনগুলি
তুমি জসিম উদদীনের নকশী কাথার মাঠ, মুঠো মুঠো সোনার ধুলি
তুমি তিরিশ কিংবা তার অধিক লাখো শহীদের প্রাণ
তুমি শহীদ মিনারের প্রভাতফেরী, ভাইহারা একুশের গান
........................................................
........................................................
*/

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
#define MOD             1000000007
#define M               200005
#define MX              50005

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

int main()
{
    int n, a;
    string s;

    while(cin >> n && n)
    {
        cin.ignore();

        vector<int>v;
        for(int i=1; i<=n; i++) v.push_back(i);

        while(getline(cin,s))
        {
            if(s=="0")
            {
                cout << endl;
                break;
            }

            queue<int>q;
            stack<int>st;

            stringstream ss(s);
            while(ss >> a) q.push(a);

            a=0;
            while(1)
            {
                if(q.empty())
                {
                    cout << "Yes" << endl;
                    break;
                }
                else if(st.empty())
                {
                    if(q.front()==v[a]) q.pop();
                    else st.push(v[a]);
                    a++;
                }
                else if(a==n)
                {
                    if(q.front()==st.top())
                    {
                        q.pop();
                        st.pop();
                    }
                    else
                    {
                        cout << "No" << endl;
                        break;
                    }
                }
                else
                {
                    if(q.front()==st.top())
                    {
                        q.pop();
                        st.pop();
                    }
                    else if(q.front()==v[a])
                    {
                        q.pop();
                        a++;
                    }
                    else
                    {
                        st.push(v[a]);
                        a++;
                    }
                }
            }
        }
    }

    return 0;
}
