#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#define ff            first
#define ss            second
#define int           long long
#define pb            push_back
#define mp            make_pair
#define pii           pair<int,int>
#define vi            vector<int>
#define mii           map<int,int>
#define pqb           priority_queue<int>
#define pqs           priority_queue<int,vi,greater<int>>
#define setbits(x)    __builtin_popcountll(x)
#define zrobits(x)    __builtin_ctzll(x)
#define mod           998244353
#define inf           1e18
#define ps(x,y)       fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n];
#define w           int x125;cin>>x125;while(x125--)
#define F10            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int,null_type,rb_tree_tag,tree_order_statistics_node_update> pbds;
int n,m,scc=0;
vector<set<int>> edge,revedge;
vi stack1,rTopoSort;
vector<bool> isVisited;
void addEdge(char a,int x,char b,int y)
{
    int xorg,xchn,yorg,ychn;
    if(a=='+')
    {
        xorg=x;
        xchn=m+x;
    }
    else
    {
        xorg=m+x;
        xchn=x;
    }
    if(b=='+')
    {
        yorg=y;
        ychn=m+y;
    }
    else
    {
        yorg=m+y;
        ychn=y;
    }
    edge[xchn].insert(yorg);
    revedge[yorg].insert(xchn);
    edge[ychn].insert(xorg);
    revedge[xorg].insert(ychn);
}
void dfs(int curr)
{
    if(isVisited[curr])
        return;
    isVisited[curr]=true;
    for (int i : edge[curr]) {
        dfs(i);
    }
    stack1.push_back(curr);
}
void dfs1(int curridx)
{
    if(isVisited[curridx])
        return;
    rTopoSort[curridx]=scc;
    isVisited[curridx]=true;
    for (int i : edge[curridx]) {
        dfs1(i);
    }
}
int32_t main() {
    F10;
    int x, ans = 1,y;
    char a,b;
    cin >> n >> m;
    edge.resize(2*m+1);
    revedge.resize(2*m+1);
    rTopoSort.resize(2*m+1,0);
    isVisited.resize(2*m+1, false);
    for (int i = 0; i <n ; ++i) {
        cin>>a>>x>>b>>y;
        addEdge(a,x,b,y);
    }
//    for (int i = 1; i < 2*m+1; ++i) {
//        for (int j : edge[i]) {
//            cout<<j<<" ";
//        }
//        cout<<'\n';
//    }
    for (int i = 1; i <=2*m ; ++i) {
        if(!isVisited[i] && edge[i].size()>0)
            dfs(i);
    }
//    cout<<"ok\n";
//    for (int i = 1; i < 2*m+1; ++i) {
//        for (int j : edge[i]) {
//            cout<<j<<" ";
//        }
//        cout<<'\n';
//    }
//    return 0;
    edge=revedge;
    isVisited.resize(0);
    isVisited.resize(2*m+1, false);
    for (int i = stack1.size()-1; i >=0 ; --i) {
        int currIdx=stack1[i];
        if(!isVisited[currIdx])
        {
            scc++;
            dfs1(currIdx);
        }
    }
    for (int i = 1; i <=m ; ++i) {
        if(rTopoSort[i]>0 && rTopoSort[i]==rTopoSort[i+m])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <=m ; ++i) {
        if(rTopoSort[i]==0 || rTopoSort[i]>rTopoSort[i+m])
        {
            cout<<"+ ";
        } else
        {
            cout<<"- ";

        }
    }
}






