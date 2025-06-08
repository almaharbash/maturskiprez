#include<iostream>
#include<fstream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    freopen("unos.txt","r",stdin);
    freopen("ispis.txt","w",stdout);
    cin>>n;
    map<double,int> film;
    for(int i=0;i<n;i++) 
    {
        double a;
        cin>>a;
        film[a]++;
    }
    vector<int> sum;
    for(auto [a,b]:film)
    {
        if(sum.empty())
        sum.push_back(b);
        else
        sum.push_back(sum.back()+b);
    }
    int m;
    cin>>m;
    vector<pair<double,double>> ocjena(m);
    for(int i=0;i<m;i++)
    {
        double a,b;
        cin>>a>>b;
        ocjena[i]={a,b};
    }
    for(auto [a,b]:ocjena)
    {
        if(a>b)
        {
            cout<<0<<endl;
            continue;
        }
        int cnta=2;
        int cntb=1;
        bool br=0;
        bool brb=0;
        if(film.count(a)) 
        {
            cntb--;
            cnta--;
            br=1;
        }
        if(film.count(b)) brb=1;
        film[a]++;
        film[b]++;
        int id1=distance(film.begin(),film.find(a));
        int id2=distance(film.begin(),film.find(b));
        if(id1>n&&id2>n||a>b)
        {
            cout<<0<<endl;
            continue;
        }
        id2-=cnta;
        id1-=cntb;
        
        if(id1==-1)
        {
            ispis<<sum[id2]<<endl;
            continue;
        }
        
        ispis<<sum[id2]-sum[id1]<<endl;
        if(!br) film.erase(a);
        if(!brb) film.erase(b);
    }
}