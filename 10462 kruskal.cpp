#include<bits/stdc++.h>
#define MX  102
using namespace std;

struct Edge
{
    int from, to, cost;
    Edge(int _from, int _to, int _cost)
    {
        from=_from;
        to=_to;
        cost=_cost;
    }
};
bool operator<(Edge x, Edge y)
{
    return x.cost<y.cost;
}

int parent[MX];
int mark[MX];
int d;
vector<Edge>arr;

void initializeSet(int n)
{
    for(int i=1; i<=n; i++)
        parent[i]=i;
}

int findParent(int x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x]=findParent(parent[x]);
}

void unionSet(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if(px!=py)
        parent[py] = px;
}

int kruskal_1(int n)
{
    int x, y, z;
    int sz, sum=0, ans=-1;

    initializeSet(n);
    sort(arr.begin(),arr.end());
    sz=arr.size();

    for(int i=0; i<sz; i++)
    {
        x=arr[i].from;
        y=arr[i].to;
        z=arr[i].cost;

        if(findParent(x)!=findParent(y))
        {
            unionSet(parent[x],parent[y]);
            sum+=z;
            mark[d++]=i;
            if(d+1==n)
                break;
        }
    }

    if(d+1==n)
        ans=sum;
    return ans;
}

int kruskal_2(int n)
{
    int x, y, z, cnt;
    int sz, sum, ans=INT_MAX;

    sz=arr.size();

    for(int j=0; j<d; j++)
    {
        initializeSet(n);
        sum=0;
        cnt=0;

        for(int i=0; i<sz; i++)
        {
            if(i==mark[j])
                continue;

            x=arr[i].from;
            y=arr[i].to;
            z=arr[i].cost;

            if(findParent(x)!=findParent(y))
            {
                unionSet(parent[x],parent[y]);
                sum+=z;
                cnt++;
                if(cnt+1==n)
                    break;
            }
        }

        if(cnt+1==n)
            ans=min(ans,sum);
    }

    return ans;
}


int main()
{
    int test, node, edge, a, b, c, mst1, mst2;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        arr.clear();
        memset(mark,0,sizeof(mark));
        d=0;

        cin >> node >> edge;
        for(int i=0; i<edge; i++)
        {
            cin >> a >> b >> c;
            arr.push_back(Edge(a,b,c));
        }

        printf("Case #%d : ",t);

        mst1=kruskal_1(node);
        if(mst1==-1)
        {
            printf("No way\n");
            continue;
        }

        mst2=kruskal_2(node);
        if(mst2==INT_MAX)
            printf("No second way\n");
        else
            printf("%d\n",mst2);
    }

    return 0;
}
