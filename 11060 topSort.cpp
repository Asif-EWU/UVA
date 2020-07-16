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
#define PS              system("pause")
#define MOD             100000007
#define M               100005
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

vector<int>arr[105];
int inDegree[105];
queue<int>q;

void topSort(int n)
{
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=1; i<=n; i++)
    {
        if(!inDegree[i])
            pq.push(i);
    }

    while(!pq.empty())
    {
        int a=pq.top();
        pq.pop();

        for(int i=0; i<arr[a].size(); i++)
        {
            int b=arr[a][i];
            inDegree[b]--;
            if(inDegree[b]==0) pq.push(b);
        }

        q.push(a);
    }
}


int main()
{
    int n, m, kase=1, a;
    string s1, s2;

    while(cin >> n)
    {
        for(int i=1; i<=n; i++)
            arr[i].clear();
        memset(inDegree,0,sizeof(inDegree));
        map<string,int>mp1;
        map<int,string>mp2;

        for(int i=1; i<=n; i++)
        {
            cin >> s1;
            mp1[s1]=i;
            mp2[i]=s1;
        }

        cin >> m;
        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2;
            inDegree[mp1[s2]]++;
            arr[mp1[s1]].push_back(mp1[s2]);
        }

        topSort(n);

        printf("Case #%d: Dilbert should drink beverages in this order:",kase++);
        while(!q.empty())
        {
            a=q.front();
            q.pop();

            cout << " " << mp2[a];
        }
        printf(".\n\n");
    }

    return 0;
}
