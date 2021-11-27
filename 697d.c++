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
vector<string> matrix;
int n,m,scc=0;
vector<vi> edge,revedge;
vi stack1,rTopoSort;
vector<bool> isVisited;
void addEdge(int x,int y)
{
//    cout<<"1 i m edge :"<<x<<" "<<y<<"\n";
    int xchn=x+n*2,ychn=y+n*2;

    edge[xchn].push_back(ychn);
    revedge[ychn].push_back(xchn);
    edge[ychn].push_back(xchn);
    revedge[xchn].push_back(ychn);
    edge[x].push_back(y);
    revedge[y].push_back(x);
    edge[y].push_back(x);
    revedge[x].push_back(y);

}
void addEdge1(int x,int y)
{
//    cout<<"2 i m edge :"<<x<<" "<<y<<"\n";
    int xchn=x+n*2,ychn=y+n*2;
    edge[xchn].push_back(y);
    edge[y].push_back(xchn);
    edge[ychn].push_back(x);
    edge[x].push_back(ychn);
    revedge[y].push_back(xchn);
    revedge[xchn].push_back(y);
    revedge[x].push_back(ychn);
    revedge[ychn].push_back(x);
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

//Handle each test case
void testcase()
{
    cin>>n;
    string s;
    scc=0;
    stack1.resize(0);
    matrix.resize(0);
    edge.resize(0);
    revedge.resize(0);
    rTopoSort.resize(0);
    isVisited.resize(0);
    matrix.resize(n);
    edge.resize(n*4);
    revedge.resize(n*4);
    rTopoSort.resize(n*4,0);
    isVisited.resize(n*4, false);
    for (int i = 0; i < n; ++i) {
        cin>>matrix[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>s;
        for (int j = 0; j <n ; ++j) {
            if(matrix[i][j]==s[j])
            {
                addEdge(i,j+n);
            }else {
                //both are not same
                addEdge1(i,j+n);
            }
        }
    }

    //apply Kosaraju's Algorithm.
    for (int i = 0; i <4*n ; ++i) {
        if(!isVisited[i] && edge[i].size()>0)
            dfs(i);
    }
    edge=revedge;
    isVisited.resize(0);
    isVisited.resize(4*n, false);
    for (int i = stack1.size()-1; i >=0 ; --i) {
        int currIdx=stack1[i];
        if(!isVisited[currIdx])
        {
            scc++;
            dfs1(currIdx);
        }
    }
    //answer
    for (int i = 0; i <n*2 ; ++i) {
        if(rTopoSort[i]==rTopoSort[i+2*n]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}


int32_t main()
{
    w{
        testcase();
    }
    return 0;
}