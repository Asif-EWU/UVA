#include<bits/stdc++.h>
using namespace std;

int kount[1002];     //number of times each paper is being reviewed
vector<int>v[1002];  //list of scientists reviewing a paper
map<string,int>mp;   //index number each institution
int mark[1002][1002];
int arr[1002];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, a, cnt;
    string s;

    while((cin >> n >> m) && n+m)
    {
        cnt=0;
        memset(kount,0,sizeof(kount));
        memset(arr,0,sizeof(arr));
        memset(mark,0,sizeof(mark));
        mp.clear();
        for(int i=1; i<=m; i++) v[i].clear();

        for(int i=1; i<=m; i++)
        {
            cin >> s;
            if(mp[s]==0) mp[s]=i;
            arr[i]=mp[s];

            for(int j=0; j<n; j++)
            {
                cin >> a;
                mark[i][a]++;
                if(mark[i][a]==2) kount[a]=n;
                kount[a]++;
                v[a].push_back(i);
            }
        }

        for(int i=1; i<=m; i++)
        {
            if(kount[i]!=n)
            {
                cnt++;
                continue;
            }

            for(int j=0; j<v[i].size(); j++)
            {
                a=v[i][j];
                if(arr[i]==arr[a])
                {
                    cnt++;
                    break;
                }
            }
        }

        if(cnt==0) cout << "NO PROBLEMS FOUND" << endl;
        else if(cnt==1) cout << "1 PROBLEM FOUND" << endl;
        else cout << cnt << " PROBLEMS FOUND" << endl;
    }

    return 0;
}
