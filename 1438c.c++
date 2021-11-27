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
vector<vi> matrix;
int n,m,scc=0;
vector<set<int>> edge,revedge;
vi stack1,rTopoSort;
vector<bool> isVisited;
void addEdge(int x,int y)
{
//    cout<<"1 i m edge :"<<x<<" "<<y<<"\n";
    int xchn=x+n*m,ychn=y+n*m;

    edge[xchn].insert(y);
    revedge[y].insert(xchn);
    edge[ychn].insert(x);
    revedge[x].insert(ychn);
    edge[x].insert(ychn);
    revedge[ychn].insert(x);
    edge[y].insert(xchn);
    revedge[xchn].insert(y);

}
void addEdge1(int x,int y)
{
//    cout<<"2 i m edge :"<<x<<" "<<y<<"\n";
    int xchn=x+n*m,ychn=y+n*m;
    edge[xchn].insert(ychn);
    edge[y].insert(x);
    revedge[ychn].insert(xchn);
    revedge[x].insert(y);
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
    cin>>n>>m;
    scc=0;
    stack1.resize(0);
    matrix.resize(0);
    edge.resize(0);
    revedge.resize(0);
    rTopoSort.resize(0);
    isVisited.resize(0);
    matrix.resize(n,vi(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <m ; ++j) {
            cin>>matrix[i][j];
        }
    }
    {
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j <m ; ++j) {
//            cout<<matrix[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    }
    edge.resize(n*m*2);
    revedge.resize(n*m*2);
    rTopoSort.resize(n*m*2,0);
    isVisited.resize(n*m*2, false);
    //add edge in to graph
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //column view
            if(i+1<n )
            {
                if(matrix[i][j]==matrix[i+1][j])
                {
                    addEdge(i*m+j,(i+1)*m+j);
                } else if(min(matrix[i][j],matrix[i+1][j])+1==max(matrix[i][j],matrix[i+1][j]))
                {
                    if(matrix[i][j]>matrix[i+1][j])
                    {
                        addEdge1(i*m+j,(i+1)*m+j);
                    } else
                    {
                        addEdge1((i+1)*m+j,i*m+j);
                    }
                }
            }

            //row view
            if(j+1<m)
            {
                if(matrix[i][j]==matrix[i][j+1])
                {
                    addEdge(i*m+j,(i)*m+j+1);
                } else if(min(matrix[i][j],matrix[i][1+j])+1==max(matrix[i][j],matrix[i][j+1]))
                {
                    if(matrix[i][j]>matrix[i][1+j])
                    {
                        addEdge1(i*m+j,i*m+j+1);
                    } else
                    {
                        addEdge1(1+i*m+j,i*m+j);
                    }
                }
            }

        }
    }
    //apply Kosaraju's Algorithm.
    for (int i = 1; i <2*m*n ; ++i) {
        if(!isVisited[i] && edge[i].size()>0)
            dfs(i);
    }
    edge=revedge;
    isVisited.resize(0);
    isVisited.resize(2*m*n, false);
    for (int i = stack1.size()-1; i >=0 ; --i) {
        int currIdx=stack1[i];
        if(!isVisited[currIdx])
        {
            scc++;
            dfs1(currIdx);
        }
    }
    //answer
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < m; ++j) {
            if(rTopoSort[i*m+j]==0)
                cout<<matrix[i][j]<<" ";
            else
            {
                if(rTopoSort[i*m+j]==rTopoSort[n*m+i*m+j])
                    cout<<"Impossible";
                if(rTopoSort[i*m+j]<rTopoSort[n*m+i*m+j])
                    cout<<matrix[i][j]<<" ";
                else
                    cout<<matrix[i][j]+1<<" ";
            }
        }
        cout<<"\n";
    }
}


int32_t main()
{
    w{
        testcase();
    }
    return 0;
}