#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<utility>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
int bfs(vector<vector<int>>&m, int i,int j)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(m.size(),vector<bool>(m[0].size(),0));
    visited[i][j]=1;
    vector<pair<int,int>> move{{1,0},{0,1},{-1,0},{0,-1}};
    int b=0;
    q.push({i,j});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        if(m[x][y]==9)
        b++;
        q.pop();
        for(auto a:move)
        {
            int b=x+a.first;
            int c=y+a.second;
            if(b>=0&&b<m.size()&&c>=0&&c<m[0].size()&&!visited[b][c])
            {
                if(m[b][c]==m[x][y]+1)
                {
                    visited[b][c]=1;
                q.push({b,c});
                }
            }
        }
    }
    return b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> m;
    string s;
    while(getline(cin,s))
    {
        if(s.empty()) break;
        vector<int> temp;
        for(int i=0;i<s.length();i++)
        temp.push_back(s[i]-'0');
        m.push_back(temp);
    }
    int br=0;
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].size();j++)
        {
            if(m[i][j]==0)
            br+=bfs(m,i,j);
        }
    }
    cout<<br<<endl;

    return 0;
}